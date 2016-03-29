/**
 * Core of the sh7750h emulation
 *
 * @author Roberto Cano <http://www.robertocano.es>
 * @date 26-Aug-2015
 */
#include "sh4.h"
#include "sh4opcode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <libgen.h>
#include <unistd.h>

void usage(char *name)
{
    fprintf(stderr, "Usage:\n");
    fprintf(stderr, "    %s [-d] [-i] <elf_file> <params...>\n", basename(name));
    fprintf(stderr, "\n");
    fprintf(stderr, "    -d: Enables the disassembler with all debug information\n");
    fprintf(stderr, "    -h: Prints this help\n");
    fprintf(stderr, "    -i: Prints information about the ELF file\n");
    fprintf(stderr, "    <elf_file>: SH ELF file name\n");
    fprintf(stderr, "    <params>: Parameters to be passed to the ELF executable\n");
    fprintf(stderr, "\n");
    exit(1);
}

int main(int argc, char **argv)
{
    SH4Context_t context;
    uint32_t value;
    SH4Error ret;
    bool debug = false, info = false;
    char *elfname;
    int c, count=1;

    while ((c=getopt(argc, argv, "dhi")) != -1) {
        switch (c) {
            case 'd':
                debug = true;
                count++;
                break;
            case 'i':
                info = true;
                count++;
                break;
            case 'h':
            default:
                usage(argv[0]);
        }
    }

    elfname = argv[count];

    SH4_InitContext(&context);

    ret = SH4_ELF_Load(&context, elfname, 0x400000);
    if (ret != SH4_SUCCESS) {
        SH4_LogErr(SH4_LOG_ERROR, ret, "ERROR loading ELF file %s to memory", elfname);
        exit(1);
    }

    if (info) {
        SH4_Log(SH4_LOG_INFO, "ELF file: %s", elfname);
        SH4_ELF_ShowInfo(&context);
        exit(0);
    }

    if (debug) {
        SH4_EnableDebug(&context);
    }
    SH4_EnableAbort(&context);

    SH4_Reset(&context);

    argc -= count;
    argv += count;
    return SH4_Execute(&context, argc, argv);
}
