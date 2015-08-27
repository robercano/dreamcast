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
 *      { 0xE000, __1110nnnniiiiiiii }, // 0xE000 is 1110000000000000
 *      { 0xE001, __1110nnnniiiiiiii },
 *      ...
 *      ...
 *      { 0xEFFE, __1110nnnniiiiiiii },
 *      { 0xEFFF, __1110nnnniiiiiiii }, // 0xEFFF is 1110111111111111
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

struct {
	char opcode[17];
    char mnemonic[16];
} opcodeDefs[] = {
	{ "1110nnnniiiiiiii", "mov #i,Rn" }
};

void GenerateOpcodeLUT()
{
	uint32_t i, j, k;
	uint8_t positions[12];
	uint8_t numPositions = 0;
	uint16_t base, opcode;

	fprintf(stdout, "/* Forward declaration of all function processors */\n");
	for (i=0; i<sizeof opcodeDefs/sizeof *opcodeDefs; ++i) {
		fprintf(stdout, "void __%s(uint16_t op); /**< %s */\n", opcodeDefs[i].opcode, opcodeDefs[i].mnemonic);
	}

	fprintf(stdout, "\n");

	fprintf(stdout, "/* Opcodes lookup table */\n");
	fprintf(stdout, "typedef void (*OPProcesor_t)(uint16_t);\n");
    fprintf(stdout, "\n");
	fprintf(stdout, "struct {\n");
	fprintf(stdout, "    uint16_t opcode;\n");
	fprintf(stdout, "    OPProcesor_t processor;\n");
	fprintf(stdout, "} SH7750OPLUT[] = {\n");

	/* Parse the input definition */
	for (i=0; i<sizeof opcodeDefs/sizeof *opcodeDefs; ++i) {
		base = 0;
		for (j=0; j<16; j++) {
			base <<= 1;
			if (opcodeDefs[i].opcode[j] == '1') {
				base |= 1;
			} else if (opcodeDefs[i].opcode[j] != '0') {
				positions[numPositions++] = 15-j;
			}
		}

		/* Generate all possible combinations */
		for (j=0; j<(1<<numPositions); j++) {
			opcode = base;
			for (k=0; k<numPositions; k++) {
				opcode |= ((j>>(numPositions-k-1))&0x1)<<positions[k];
			}
			fprintf(stdout, "{ 0x%04x, __%s }, /**< %s */\n", opcode, opcodeDefs[i].opcode, opcodeDefs[i].mnemonic);
		}
	}
	fprintf(stdout, "}\n");
}

int main()
{
	GenerateOpcodeLUT();
	return 0;
}

































