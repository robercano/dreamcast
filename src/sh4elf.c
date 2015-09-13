/**
 * sh4elfloader.c
 *
 * ELF loader for SH binaries using libbfd
 */
#include "bfd.h"
#include "sh4.h"
#include <stdlib.h>
#include <string.h>

static SH4Error __SH4_ELF_GetMainEntry(IN bfd *elf, uint32_t *mainentry, uint32_t *printentry)
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

    /* Analyze the symbols */
    bool printFound = false, mainFound = false;
    for (i=0; i<symcount; i++) {
        bfd *cur_bfd;

        if (symbols[i] == NULL) {
            continue;
        }
        if (strcmp(symbols[i]->name, "_main") == 0) {
            if (symbols[i]->section == NULL) {
                *mainentry = (uint32_t)symbols[i]->value;
            } else {
                *mainentry = (uint32_t)(symbols[i]->section->vma + symbols[i]->value);
            }
            mainFound = true;
        } else if (strcmp(symbols[i]->name, "_printf") == 0) {
            *printentry = (uint32_t)(symbols[i]->section->vma + symbols[i]->value);
            printFound = true;
        }

        if (mainFound && printFound) {
            free((void*)symbols);
            ret = SH4_SUCCESS;
            break;
        }
    }
    return ret;
}

SH4Error SH4_ELF_ShowInfo(const char *elfname)
{
    bfd *elf;
    asection *section;
    uint32_t main_entry, print_entry;
    SH4Error ret;

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

    SH4_Log(SH4_LOG_INFO, "Format: %s", elf->xvec->name);
    SH4_Log(SH4_LOG_INFO, "Entrypoint: 0x%08x", (unsigned int)bfd_get_start_address(elf));

    /* Sections */
    for (section=elf->sections; section!=NULL; section=section->next) {
        if (bfd_get_section_flags (elf, section) & (SEC_LOAD)) {
            if (bfd_section_lma (elf, section) != bfd_section_vma (elf, section)) {
                SH4_Log(SH4_LOG_INFO, "LOAD    %-20s: lma=0x%08x (vma=0x%08x) size=0x%08x",
                                     bfd_section_name(elf, section),
                                     (unsigned int)bfd_section_lma(elf, section),
                                     (unsigned int)bfd_section_vma(elf, section),
                                     (unsigned int)bfd_section_size(elf, section));
            } else {
                SH4_Log(SH4_LOG_INFO, "LOAD    %-20s: addr=0x%08x size=0x%08x",
                                     bfd_section_name(elf, section),
                                     (unsigned int)bfd_section_lma(elf, section),
                                     (unsigned int)bfd_section_size(elf, section));
            }
        } else {
            SH4_Log(SH4_LOG_INFO, "NO_LOAD %-20s: addr=0x%08x size=0x%08x",
                                 bfd_section_name (elf, section),
                                 (unsigned int)bfd_section_vma(elf, section),
                                 (unsigned int)bfd_section_size(elf, section));
        }
    }

    SH4_LogEx(SH4_LOG_INFO, "\n");

    ret = __SH4_ELF_GetMainEntry(elf, &main_entry, &print_entry);

    bfd_close(elf);

    if (ret != SH4_SUCCESS) {
        SH4_LogErr(SH4_LOG_ERROR, ret, "ERROR _main entrypoint not found in file");
        return SH4_ERROR_WRONG_FORMAT;
    }

    SH4_Log(SH4_LOG_INFO, "Main entrypoint: %08x", main_entry);
    SH4_Log(SH4_LOG_INFO, "printf address: %08x", print_entry);
    SH4_LogEx(SH4_LOG_INFO, "\n");

    return SH4_SUCCESS;
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

    ret = __SH4_ELF_GetMainEntry(elf, &context->entrypoint, &context->print);
    if (ret != SH4_SUCCESS) {
        SH4_Log(SH4_LOG_INFO, "_main entrypoint not found, using start address");
        context->entrypoint = (uint32_t)bfd_get_start_address(elf);
    }

    /* Initialize the registers */
    SH4_Reset(context, context->entrypoint, context->print);

    /* Sections */
    for (section=elf->sections; section!=NULL; section=section->next) {
        uint32_t offset = bfd_section_lma(elf, section);
        uint32_t vma = bfd_section_vma(elf, section);
        uint32_t size = bfd_section_size(elf, section);
        uint32_t load = bfd_get_section_flags(elf, section) & SEC_LOAD;

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
            /* Initialize R15 to the address */
            context->regs.R[15].bank[1] = offset;
        }
    }
    bfd_close(elf);

    return 0;
}
