/**
 * Core of the sh7750h emulation
 *
 * @author Roberto Cano <roberto.cano at google mail>
 * @date 26-Aug-2015
 */
#include "sh4.h"
#include "sh4opcode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    FILE *opfile;
    uint16_t op;
    int ret;

    if (argc < 2) {
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "    sh4disassembler <opcode_file>\n");
        fprintf(stderr, "\n");
        exit(1);
    }

    opfile = fopen(argv[1], "rb");
    if (opfile == NULL) {
        fprintf(stderr, "ERROR opening opcodes file %s\n", argv[1]);
        exit(1);
    }

    for (;;) {
        ret = fread(&op, sizeof op, 1, opfile);
        if (ret != 1) {
            if (!feof(opfile)) {
                fprintf(stderr, "ERROR reading opcode from file: %s\n", strerror(errno));
                exit(1);
            }
            break;
        }

        op = ntohs(op);

        /* Execute the opcode */
        fprintf(stdout, "%02x %02x           ", (op>>8)&0xff, op&0xff);
        SH7750DisasmLUT[op](op);
    }

	return 0;
}
