/**
 * List of opcodes of the SH7750h.
 *
 * The idea of this list is to be the input of the tool that automatically
 * generates the LUT for the opcodes. The format is something like this:
 *
 *    _OP(1110nnnniiiiiiii, "mov #i,Rn")
 *
 * Then the parser will translate this into:
 *
 *  // Functions declarations
 *  void __1110nnnniiiiiiii(uin16_t op);
 *
 *  // LUT
 *  typedef void (*OPProcesor_t)(uint16_t);
 *
 *  struct {
 *		uint16_t opcode;
 *		OPProcesor_t processor;
 *  } SH7750OPLUT[] = {
 *      ....
 *      ....
 *      __1110nnnniiiiiiii, // 0xE000 is 1110000000000000
 *      __1110nnnniiiiiiii,
 *      ...
 *      ...
 *      __1110nnnniiiiiiii,
 *      __1110nnnniiiiiiii, // 0xEFFF is 1110111111111111
 *      ...
 *      };
 *
 * Then the function implementation by default is:
 *
 *      void __1110nnnniiiiiiii(uin16_t op) {
 *			// mov #i,Rn
 *			fprintf(stderr, "[NOT IMPLEMENTED!!] mov #i,Rn --> __1110nnnniiiiiiii\n");
 *      }
 *
 * A sample implementation of the function could be:
 *
 *      void __1110nnnniiiiiiii(uin16_t op) {
 *			// mov #i,Rn
 *			register uint8_t Rn = (op>>8)&0xF;
 *			register uint8_t imm = op&0xFF;
 *			fprintf(stderr, " mov #%d,R%d\n", imm, Rn);
 *      }
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* List of opcodes and mnemonics */
struct {
	char opcode[32];
    char mnemonic[32];
    char format[32];
	struct {
		char symbol;
		uint8_t firstBit;
		uint8_t numBits;
    } seenVars[3];
	uint8_t seenVarsOrder[3];
	uint8_t numSeenVars;
} opcodeDefs[] = {
	{ "0000000000000000", "noop", 0},
	{ "1110nnnniiiiiiii", "mov #%i,R%n", 0 },
	{ "1001nnnndddddddd", "mov.w @(%d,PC),R%n", 0 },
	{ "1101nnnndddddddd", "mov.w @(%d,PC),R%n", 0 },
	{ "0110nnnnmmmm0011", "mov R%m,R%n", 0 },
};
uint16_t opcodeLUT[65536] = {0};

void GenerateOpcodeLUT()
{
	uint32_t i, j, k, l, pos;
	uint8_t positions[12];
	uint8_t numPositions = 0;
	uint16_t base, opcode;
	char printVars[3];
	uint8_t numPrintVars;
	size_t mnemonicLen;

	/* Parse the input definition */
	for (i=0; i<sizeof opcodeDefs/sizeof *opcodeDefs; ++i) {
		for (j=0, base=0, numPositions=0; j<16; j++) {
			base <<= 1;
			if (opcodeDefs[i].opcode[j] == '1') {
				base |= 1;
			} else if (opcodeDefs[i].opcode[j] != '0') {
				/* Save the position of the variable bit of the mnemonic */
				positions[numPositions++] = 15-j;

				/* Process the symbols for precooked variables */
				for (l=0; l<opcodeDefs[i].numSeenVars; ++l) {
					if (opcodeDefs[i].seenVars[l].symbol == opcodeDefs[i].opcode[j]) {
						opcodeDefs[i].seenVars[l].numBits++;
						break;
					}
				}
				if (l == opcodeDefs[i].numSeenVars) {
					/* We've seen a new symbol, save it */
					opcodeDefs[i].seenVars[opcodeDefs[i].numSeenVars].symbol = opcodeDefs[i].opcode[j];
					opcodeDefs[i].seenVars[opcodeDefs[i].numSeenVars].firstBit = 15-j;
					opcodeDefs[i].seenVars[opcodeDefs[i].numSeenVars].numBits++;
					opcodeDefs[i].numSeenVars++;
				}
			}
		}
		/* Parse the mnemonic to find out the printing order
		 * of the precooked variables */
		strcpy(opcodeDefs[i].format, opcodeDefs[i].mnemonic);
		mnemonicLen = strlen(opcodeDefs[i].mnemonic);
		for (j=0, pos=0; j<mnemonicLen; ++j) {
			if (opcodeDefs[i].mnemonic[j] == '%' && j<mnemonicLen-1) {
				j++;

				/* Find the symbol in the precooked vars array */
				for (k=0; k<opcodeDefs[i].numSeenVars; ++k) {
					if (opcodeDefs[i].seenVars[k].symbol == opcodeDefs[i].mnemonic[j]) {
						opcodeDefs[i].seenVarsOrder[pos++] = k;
						break;
					}
				}
				if (k == opcodeDefs[i].numSeenVars) {
					fprintf(stderr, "[CRITICAL!!] Please check mnemonic %d (%s, %s), syntax seems to be wrong\n",
							         i, opcodeDefs[i].opcode, opcodeDefs[i].mnemonic);
					exit(1);
				}

				/* Now fix the symbol so we can use it as a printf format string */
				opcodeDefs[i].mnemonic[j] = 'c';
				opcodeDefs[i].format[j] = 'd';
			}
		}

		/* Generate all possible combinations */
		for (j=0; j<(1<<numPositions); j++) {
			opcode = base;
			for (k=0; k<numPositions; k++) {
				opcode |= ((j>>(numPositions-k-1))&0x1)<<positions[k];
			}
			opcodeLUT[opcode] = i;
		}
	}

	/* Output the opcodes file */
	fprintf(stdout, "/* Forward declaration of all function processors */\n");
	for (i=0; i<sizeof opcodeDefs/sizeof *opcodeDefs; ++i) {
		fprintf(stdout, "void __%s(uint16_t op); /**< %s */\n", opcodeDefs[i].opcode, opcodeDefs[i].mnemonic);
	}
	fprintf(stdout, "\n");

	fprintf(stdout, "/* Opcodes lookup table */\n");
	fprintf(stdout, "typedef void (*OPProcesor_t)(uint16_t);\n");
    fprintf(stdout, "\n");
	fprintf(stdout, "OPProcesor_t SH7750OPLUT[] = {\n");

	for (i=0; i<sizeof opcodeLUT/sizeof *opcodeLUT; ++i) {
		uint16_t defEntry = opcodeLUT[i];
		fprintf(stdout, "__%s, /**< %s */\n", opcodeDefs[defEntry].opcode, opcodeDefs[defEntry].mnemonic);
	}

	fprintf(stdout, "};\n");
	fprintf(stdout, "\n");
	for (i=0; i<sizeof opcodeDefs/sizeof *opcodeDefs; ++i) {
		fprintf(stdout, "void __%s(uint16_t op)\n", opcodeDefs[i].opcode);
		fprintf(stdout, "{\n");
		fprintf(stdout, "    /* ");
				fprintf(stdout, opcodeDefs[i].mnemonic, opcodeDefs[i].seenVars[opcodeDefs[i].seenVarsOrder[0]],
						                                opcodeDefs[i].seenVars[opcodeDefs[i].seenVarsOrder[1]],
						                                opcodeDefs[i].seenVars[opcodeDefs[i].seenVarsOrder[2]]);
		fprintf(stdout, " */\n");

		/* Precooked variables holding the needed ops */
		for (j=0; j<opcodeDefs[i].numSeenVars; ++j) {
			if (opcodeDefs[i].seenVars[j].numBits > 8) {
				fprintf(stdout, "    uint16_t ");
			} else {
				fprintf(stdout, "    uint8_t ");
			}
			if (opcodeDefs[i].seenVars[j].firstBit+1-opcodeDefs[i].seenVars[j].numBits > 0) {
				fprintf(stdout, "%c = (op>>%d)&0x%x;\n", opcodeDefs[i].seenVars[j].symbol,
														 opcodeDefs[i].seenVars[j].firstBit+1-
														 opcodeDefs[i].seenVars[j].numBits,
														 (1<<opcodeDefs[i].seenVars[j].numBits)-1);
			} else {
				fprintf(stdout, "%c = op&0x%x;\n", opcodeDefs[i].seenVars[j].symbol,
						                           (1<<opcodeDefs[i].seenVars[j].numBits)-1);
			}
		}
		fprintf(stdout, "#ifdef SH7750_ENABLE_DISASSEMBLER\n");
		fprintf(stdout, "    fprintf(stdout, \"%s\\n\"", opcodeDefs[i].format);
		for (j=0; j<opcodeDefs[i].numSeenVars; ++j) {
			fprintf(stdout, ", %c", opcodeDefs[i].seenVars[opcodeDefs[i].seenVarsOrder[j]].symbol);
		}
		fprintf(stdout, ");\n");
		fprintf(stdout, "#else\n");
		fprintf(stdout, "    fprintf(stderr, \"[NOT IMPLEMENTED!] %s --> %s\\n\");\n",
				         opcodeDefs[i].mnemonic, opcodeDefs[i].opcode);
		fprintf(stdout, "    exit(1);\n");
		fprintf(stdout, "#endif\n");
		fprintf(stdout, "}\n");
		fprintf(stdout, "\n");
	}
}

int main()
{
	GenerateOpcodeLUT();
	return 0;
}

































