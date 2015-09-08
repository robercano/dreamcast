/**
 * sh4elfloader.c
 *
 * ELF loader for SH binaries using libbfd
 */
#include "bfd.h"
#include "sh4.h"
#include <stdlib.h>
#include <string.h>

SH4Error SH4_ELF_ShowInfo(const char *elfname)
{
    bfd *elf;
    asection *section;

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

    bfd_close(elf);
    return SH4_SUCCESS;
}

SH4Error SH4_ELF_Load(IN SH4Context_t *context, IN const char *elfname, IN uint32_t maxMemSize)
{
    bfd *elf;
    asection *section;

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

    context->entrypoint = (uint32_t)bfd_get_start_address(elf);

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
    }
    bfd_close(elf);

    /* Initialize the registers */
    SH4_Reset(context, context->entrypoint);
    return 0;
}
