/**
 * sh4elfloader.c
 *
 * ELF loader for SH binaries using libbfd
 */
#include "bfd.h"
#include "sh4.h"
#include <stdlib.h>
#include <string.h>

static int symbol_entry_cmp(const void *a, const void *b) {
    struct __sh4_symbol_entry *l = (struct __sh4_symbol_entry *)a;
    struct __sh4_symbol_entry *r = (struct __sh4_symbol_entry *)b;
    return l->address < r->address ? -1 : (l->address > r->address) ? 1 : 0;
}
static SH4Error __SH4_ELF_LoadSymbolTable(IN SH4Context_t *c, IN bfd *elf)
{
    asymbol **symbols = NULL;
    long storage, symcount, i;
    SH4Error ret = SH4_ERROR_WRONG_FORMAT;

    if (!(bfd_get_file_flags(elf) & HAS_SYMS)) {
        return SH4_ERROR_WRONG_FORMAT;
    }
    storage = bfd_get_symtab_upper_bound(elf);
    if (storage < 0) {
        return SH4_ERROR_WRONG_FORMAT;
    }
    symbols = (asymbol **)malloc(storage);
    if (symbols == NULL) {
        return SH4_ERROR_OOM;
    }
    symcount = bfd_canonicalize_symtab(elf, symbols);
    if (symcount < 0) {
        free((void*)symbols);
        return SH4_ERROR_OOM;
    }

    if (symcount > sizeof c->symbTable/sizeof *c->symbTable) {
        return SH4_ERROR_BUFFER_TOO_SMALL;
    }

    c->entrypoint = (uint32_t)bfd_get_start_address(elf);

    /* Analyze the symbols */
    for (i=0; i<symcount; i++) {
        bfd *cur_bfd;

        if (symbols[i] == NULL) {
            continue;
        }

        /* Insert symbol in the symbol table */
        struct __sh4_symbol_entry *item = &c->symbTable[c->symbTableLen];
        if (symbols[i]->section == NULL) {
            item->address = (uint32_t)symbols[i]->value;
        } else {
            item->address = (uint32_t)(symbols[i]->section->vma + symbols[i]->value);
        }
        strncpy(item->name, symbols[i]->name, sizeof item->name);

        //SH4_Log(SH4_LOG_ERROR, "SYMBOL: %s", symbols[i]->name);
        if (strcmp(item->name, "_main") == 0) {
            c->main = item->address;
        } else if (strcmp(item->name, "_printf") == 0) {
            c->print = item->address;
        } else if (strcmp(item->name, "_puts") == 0) {
            c->puts = item->address;
        }
        c->symbTableLen++;
    }
    free((void*)symbols);

    /* Sort the symbol table */
    qsort((void*)c->symbTable, c->symbTableLen, sizeof *c->symbTable, symbol_entry_cmp);

    return SH4_SUCCESS;
}

void SH4_ELF_ShowInfo(IN SH4Context_t *c)
{
    uint32_t i;

    SH4_Log(SH4_LOG_INFO, "Format: %s", c->format);

    /* Sections */
    for (i=0; i<c->sectTableLen; ++i) {
        if (c->sectTable[i].load) {
            if (c->sectTable[i].lma != c->sectTable[i].vma) {
                SH4_Log(SH4_LOG_INFO, "LOAD    %-20s: lma=0x%08x (vma=0x%08x) size=0x%08x",
                        c->sectTable[i].name, c->sectTable[i].lma, c->sectTable[i].vma, c->sectTable[i].size);
            } else {
                SH4_Log(SH4_LOG_INFO, "LOAD    %-20s: addr=0x%08x size=0x%08x",
                        c->sectTable[i].name, c->sectTable[i].lma, c->sectTable[i].size);
            }
        } else {
            SH4_Log(SH4_LOG_INFO, "NO_LOAD %-20s: addr=0x%08x size=0x%08x",
                    c->sectTable[i].name, c->sectTable[i].vma, c->sectTable[i].size);
        }
    }

    SH4_LogEx(SH4_LOG_INFO, "\n");
    SH4_Log(SH4_LOG_INFO, "Start address: 0x%08x", c->entrypoint);
    SH4_Log(SH4_LOG_INFO, "_main entrypoint: %08x", c->main);
    SH4_Log(SH4_LOG_INFO, "_printf address: %08x", c->print);
    SH4_Log(SH4_LOG_INFO, "_puts address: %08x", c->puts);
    SH4_LogEx(SH4_LOG_INFO, "\n");
}

SH4Error SH4_ELF_Load(IN SH4Context_t *context, IN const char *elfname, IN uint32_t maxMemSize)
{
    bfd *elf;
    asection *section;
    SH4Error ret;

    /* Load the ELF file */
    bfd_init();

    elf = bfd_openr(elfname, 0);
    if (elf == NULL) {
        return SH4_ERROR_FILE_NOT_FOUND;
    }

    if (!bfd_check_format(elf, bfd_object)) {
        if (bfd_get_error() != bfd_error_file_ambiguously_recognized) {
            return SH4_ERROR_WRONG_FORMAT;
        }
    }

    free((void*)context->memory);
    context->memory = NULL;
    context->memsize = 0;
    context->entrypoint = 0;
    context->print = 0;
    context->puts = 0;
    context->main = 0;

    strncpy(context->format, elf->xvec->name, sizeof context->format);

    ret = __SH4_ELF_LoadSymbolTable(context, elf);
    if (ret != SH4_SUCCESS) {
        SH4_Log(SH4_LOG_ERROR, "ERROR analyzing ELF to get main entry point");
        return ret;
    }
    if (context->entrypoint == 0) {
        SH4_Log(SH4_LOG_INFO, "_main entrypoint not found, using start address");
        context->entrypoint = (uint32_t)bfd_get_start_address(elf);
    }

    /* Sections */
    for (section=elf->sections; section!=NULL; section=section->next) {
        uint32_t offset = bfd_section_lma(elf, section);
        uint32_t vma = bfd_section_vma(elf, section);
        uint32_t size = bfd_section_size(elf, section);
        uint32_t load = bfd_get_section_flags(elf, section) & SEC_LOAD;

        struct __sh4_section_entry *item = &context->sectTable[context->sectTableLen];

        /* Save the section info */
        strncpy(item->name, bfd_section_name(elf, section), sizeof item->name);
        item->lma = (uint32_t)bfd_section_lma(elf, section);
        item->vma = (uint32_t)bfd_section_vma(elf, section);
        item->size = (uint32_t)bfd_section_size(elf, section);
        context->sectTableLen++;

        if (load != 0 && offset != vma) {
            SH4_Log(SH4_LOG_INFO, "Section not loaded: virtual addresses not supported!");
            continue;
        }

        if ( (load == 0) && (strcmp(bfd_section_name(elf, section), ".bss") != 0)) {
            continue;
        }

        if (offset + size > maxMemSize) {
            free((void*)context->memory);
            context->memsize = 0;
            context->entrypoint = 0;

            return SH4_ERROR_CODE_TOO_BIG;
        }

        if (offset + size > context->memsize) {
           context->memsize = offset+size;
           context->memory = realloc(context->memory, context->memsize);

           if (context->memory == NULL) {
               return SH4_ERROR_OOM;
           }
        }

        /* Only non-loadable section we treat differently is .bss */
        if (strcmp(bfd_section_name(elf, section), ".bss") == 0) {
            memset(context->memory + offset, 0, size);
        } else {
            bfd_get_section_contents(elf, section, context->memory + offset, 0, size);
        }

        if (strcmp(bfd_section_name(elf, section), ".stack") == 0) {
            context->stack = offset;
        }
    }
    bfd_close(elf);

    /* Allocate extra memory for argv */
    context->memsize += 1024; // 1KB
    context->memory = realloc(context->memory, context->memsize);
    if (context->memory == NULL) {
        return SH4_ERROR_OOM;
    }

    return 0;
}
