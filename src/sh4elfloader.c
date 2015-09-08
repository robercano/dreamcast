/**
 * sh4elfloader.c
 *
 * ELF loader for SH binaries using libbfd
 */
#include "bfd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int showELFInfo(const char *elfname)
{
    bfd *file;
    asection *s;

    bfd_init();

    file = bfd_openr(elfname, 0);
    if (file == NULL) {
        fprintf(stderr, "ERROR opening ELF file %s\n", elfname);
        return -1;
    }

    if (!bfd_check_format(file, bfd_object)) {
        if (bfd_get_error() != bfd_error_file_ambiguously_recognized) {
            fprintf(stderr, "Wrong ELF format\n");
            return -2;
        }
    }

    fprintf(stdout, "Format: %s\n", file->xvec->name);
    fprintf(stdout, "Entrypoint: 0x%08x\n", (unsigned int)bfd_get_start_address(file));

    /* Sections */
    for (s = file->sections; s; s = s->next) {
        if (bfd_get_section_flags (file, s) & (SEC_LOAD)) {
            if (bfd_section_lma (file, s) != bfd_section_vma (file, s)) {
                printf ("LOAD    %-20s: lma=0x%08x (vma=0x%08x) size=0x%08x\n",
                        bfd_section_name(file, s),
                        (unsigned int)bfd_section_lma(file, s),
                        (unsigned int)bfd_section_vma(file, s),
                        (unsigned int)bfd_section_size(file, s));
            } else {
                printf ("LOAD    %-20s: addr=0x%08x size=0x%08x\n",
                        bfd_section_name(file, s),
                        (unsigned int)bfd_section_lma(file, s),
                        (unsigned int)bfd_section_size(file, s));
            }
        }
        else {
            printf ("NO_LOAD %-20s: addr=0x%08x size=0x%08x \n",
                    bfd_section_name (file, s),
                    (unsigned int)bfd_section_vma(file, s),
                    (unsigned int)bfd_section_size(file, s));
        }
    }

    bfd_close(file);
    return 0;
}

int loadELFToMemory(const char *elfname, char **memory, uint32_t *memsize, uint32_t *entrypoint)
{
    bfd *file;
    asection *s;

    *memsize = 0;
    *memory = NULL;

    bfd_init();

    file = bfd_openr(elfname, 0);
    if (file == NULL) {
        fprintf(stderr, "ERROR opening ELF file %s\n", elfname);
        return -1;
    }

    if (!bfd_check_format(file, bfd_object)) {
        if (bfd_get_error() != bfd_error_file_ambiguously_recognized) {
            fprintf(stderr, "Wrong ELF format\n");
            return -2;
        }
    }

    *entrypoint = (uint32_t)bfd_get_start_address(file);

    /* Sections */
    for (s = file->sections; s; s = s->next) {
        if ((bfd_get_section_flags (file, s) & (SEC_LOAD)) &&
                bfd_section_lma (file, s) != bfd_section_vma (file, s)) {
            fprintf(stderr, "Not supported conversion from LMA to VMA for section %s\n", bfd_section_name(file, s));
            continue;
        }

        if ((bfd_get_section_flags (file, s) & (SEC_LOAD)) == 0 &&
                strcmp(bfd_section_name(file, s), ".bss") != 0) {
            continue;
        }
        uint32_t offset = bfd_section_lma(file, s);
        uint32_t size = bfd_section_size(file, s);

        if (offset + size > *memsize) {
           *memsize = offset+size;
           *memory = realloc(*memory, *memsize);
        }

        bfd_get_section_contents(file, s, *memory + bfd_section_lma(file, s), 0, bfd_section_size(file, s));
    }

    bfd_close(file);
    return 0;
}

int main(int argc, char *argv[])
{
    char *memory = NULL;
    uint32_t memsize, entrypoint;
    int i;

    showELFInfo(argv[1]);
    loadELFToMemory(argv[1], &memory, &memsize, &entrypoint);

    if (memory == NULL) {
        fprintf(stderr, "ERROR loading ELF to memory\n");
        return 1;
    }

    fprintf(stdout, "Loaded memory with range 0x00000000-0x%08x with entrypoint at 0x%08x\n", memsize, entrypoint);
    return 0;
}
