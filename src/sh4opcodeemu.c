/*********************************************
 * sh4opcodeemu.c
 *
 * Contains the implementation of the processing functions for the emulator
 *
 * @author Roberto Cano <roberto dot cano at google mail>
 *
 *********************************************/
#include "sh4opcode.h"
#include <stdio.h>
#include <stdlib.h>

void __0000000000000000(uint16_t op)
{
    /* EXCEPTION */
    fprintf(stderr, "[NOT IMPLEMENTED!] EXCEPTION --> __0000000000000000\n");
    exit(1);
}

void __1110nnnniiiiiiii(uint16_t op)
{
    /* mov #i,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov #i,Rn --> __1110nnnniiiiiiii\n");
    exit(1);
}

void __1001nnnndddddddd(uint16_t op)
{
    /* mov.w @(d,PC),Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w @(d,PC),Rn --> __1001nnnndddddddd\n");
    exit(1);
}

void __1101nnnndddddddd(uint16_t op)
{
    /* mov.l @(d,PC),Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l @(d,PC),Rn --> __1101nnnndddddddd\n");
    exit(1);
}

void __0110nnnnmmmm0011(uint16_t op)
{
    /* mov Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov Rm,Rn --> __0110nnnnmmmm0011\n");
    exit(1);
}

void __0010nnnnmmmm0000(uint16_t op)
{
    /* mov.b Rm,@Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b Rm,@Rn --> __0010nnnnmmmm0000\n");
    exit(1);
}

void __0010nnnnmmmm0001(uint16_t op)
{
    /* mov.w Rm,@Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w Rm,@Rn --> __0010nnnnmmmm0001\n");
    exit(1);
}

void __0010nnnnmmmm0010(uint16_t op)
{
    /* mov.l Rm,@Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l Rm,@Rn --> __0010nnnnmmmm0010\n");
    exit(1);
}

void __0110nnnnmmmm0000(uint16_t op)
{
    /* mov.b @Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b @Rm,Rn --> __0110nnnnmmmm0000\n");
    exit(1);
}

void __0110nnnnmmmm0001(uint16_t op)
{
    /* mov.w @Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w @Rm,Rn --> __0110nnnnmmmm0001\n");
    exit(1);
}

void __0110nnnnmmmm0010(uint16_t op)
{
    /* mov.l @Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l @Rm,Rn --> __0110nnnnmmmm0010\n");
    exit(1);
}

void __0010nnnnmmmm0100(uint16_t op)
{
    /* mov.b Rm,@-Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b Rm,@-Rn --> __0010nnnnmmmm0100\n");
    exit(1);
}

void __0010nnnnmmmm0101(uint16_t op)
{
    /* mov.w Rm,@-Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w Rm,@-Rn --> __0010nnnnmmmm0101\n");
    exit(1);
}

void __0010nnnnmmmm0110(uint16_t op)
{
    /* mov.l Rm,@-Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l Rm,@-Rn --> __0010nnnnmmmm0110\n");
    exit(1);
}

void __0110nnnnmmmm0100(uint16_t op)
{
    /* mov.b @Rm+,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b @Rm+,Rn --> __0110nnnnmmmm0100\n");
    exit(1);
}

void __0110nnnnmmmm0101(uint16_t op)
{
    /* mov.w @Rm+,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w @Rm+,Rn --> __0110nnnnmmmm0101\n");
    exit(1);
}

void __0110nnnnmmmm0110(uint16_t op)
{
    /* mov.l @Rm+,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l @Rm+,Rn --> __0110nnnnmmmm0110\n");
    exit(1);
}

void __10000000nnnndddd(uint16_t op)
{
    /* mov.b R0,@(d,Rn) */
    uint8_t n = (op>>4)&0xf;
    uint8_t d = op&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b R0,@(d,Rn) --> __10000000nnnndddd\n");
    exit(1);
}

void __10000001nnnndddd(uint16_t op)
{
    /* mov.w R0,@(d,Rn) */
    uint8_t n = (op>>4)&0xf;
    uint8_t d = op&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w R0,@(d,Rn) --> __10000001nnnndddd\n");
    exit(1);
}

void __0001nnnnmmmmdddd(uint16_t op)
{
    /* mov.l Rm,@(d,Rn) */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    uint8_t d = op&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l Rm,@(d,Rn) --> __0001nnnnmmmmdddd\n");
    exit(1);
}

void __10000100mmmmdddd(uint16_t op)
{
    /* mov.b @(d,Rm),R0 */
    uint8_t m = (op>>4)&0xf;
    uint8_t d = op&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b @(d,Rm),R0 --> __10000100mmmmdddd\n");
    exit(1);
}

void __10000101mmmmdddd(uint16_t op)
{
    /* mov.w @(d,Rm),R0 */
    uint8_t m = (op>>4)&0xf;
    uint8_t d = op&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w @(d,Rm),R0 --> __10000101mmmmdddd\n");
    exit(1);
}

void __0101nnnnmmmmdddd(uint16_t op)
{
    /* mov.l @(d,Rm),Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    uint8_t d = op&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l @(d,Rm),Rn --> __0101nnnnmmmmdddd\n");
    exit(1);
}

void __0000nnnnmmmm0100(uint16_t op)
{
    /* mov.b Rm,@(R0,Rn) */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b Rm,@(R0,Rn) --> __0000nnnnmmmm0100\n");
    exit(1);
}

void __0000nnnnmmmm0101(uint16_t op)
{
    /* mov.w Rm,@(R0,Rn) */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w Rm,@(R0,Rn) --> __0000nnnnmmmm0101\n");
    exit(1);
}

void __0000nnnnmmmm0110(uint16_t op)
{
    /* mov.l Rm,@(R0,Rn) */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l Rm,@(R0,Rn) --> __0000nnnnmmmm0110\n");
    exit(1);
}

void __0000nnnnmmmm1100(uint16_t op)
{
    /* mov.b @(R0,Rm),Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b @(R0,Rm),Rn --> __0000nnnnmmmm1100\n");
    exit(1);
}

void __0000nnnnmmmm1101(uint16_t op)
{
    /* mov.w @(R0,Rm),Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w @(R0,Rm),Rn --> __0000nnnnmmmm1101\n");
    exit(1);
}

void __0000nnnnmmmm1110(uint16_t op)
{
    /* mov.l @(R0,Rm),Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l @(R0,Rm),Rn --> __0000nnnnmmmm1110\n");
    exit(1);
}

void __11000000dddddddd(uint16_t op)
{
    /* mov.b R0,@(d,GBR) */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b R0,@(d,GBR) --> __11000000dddddddd\n");
    exit(1);
}

void __11000001dddddddd(uint16_t op)
{
    /* mov.w R0,@(d,GBR) */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w R0,@(d,GBR) --> __11000001dddddddd\n");
    exit(1);
}

void __11000010dddddddd(uint16_t op)
{
    /* mov.l R0,@(d,GBR) */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l R0,@(d,GBR) --> __11000010dddddddd\n");
    exit(1);
}

void __11000100dddddddd(uint16_t op)
{
    /* mov.b @(d,GBR),R0 */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.b @(d,GBR),R0 --> __11000100dddddddd\n");
    exit(1);
}

void __11000101dddddddd(uint16_t op)
{
    /* mov.w @(d,GBR),R0 */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.w @(d,GBR),R0 --> __11000101dddddddd\n");
    exit(1);
}

void __11000110dddddddd(uint16_t op)
{
    /* mov.l @(d,GBR),R0 */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mov.l @(d,GBR),R0 --> __11000110dddddddd\n");
    exit(1);
}

void __11000111dddddddd(uint16_t op)
{
    /* mova @(d,PC),R0 */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] mova @(d,PC),R0 --> __11000111dddddddd\n");
    exit(1);
}

void __0000nnnn00101001(uint16_t op)
{
    /* movt Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] movt Rn --> __0000nnnn00101001\n");
    exit(1);
}

void __0110nnnnmmmm1000(uint16_t op)
{
    /* swap.b Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] swap.b Rm,Rn --> __0110nnnnmmmm1000\n");
    exit(1);
}

void __0110nnnnmmmm1001(uint16_t op)
{
    /* swap.w Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] swap.w Rm,Rn --> __0110nnnnmmmm1001\n");
    exit(1);
}

void __0010nnnnmmmm1101(uint16_t op)
{
    /* xtrct Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] xtrct Rm,Rn --> __0010nnnnmmmm1101\n");
    exit(1);
}

void __0011nnnnmmmm1100(uint16_t op)
{
    /* add Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] add Rm,Rn --> __0011nnnnmmmm1100\n");
    exit(1);
}

void __0111nnnniiiiiiii(uint16_t op)
{
    /* add #i,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] add #i,Rn --> __0111nnnniiiiiiii\n");
    exit(1);
}

void __0011nnnnmmmm1110(uint16_t op)
{
    /* addc Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] addc Rm,Rn --> __0011nnnnmmmm1110\n");
    exit(1);
}

void __0011nnnnmmmm1111(uint16_t op)
{
    /* addv Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] addv Rm,Rn --> __0011nnnnmmmm1111\n");
    exit(1);
}

void __10001000iiiiiiii(uint16_t op)
{
    /* cmp/eq #i,R0 */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] cmp/eq #i,R0 --> __10001000iiiiiiii\n");
    exit(1);
}

void __0011nnnnmmmm0000(uint16_t op)
{
    /* cmp/eq Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] cmp/eq Rm,Rn --> __0011nnnnmmmm0000\n");
    exit(1);
}

void __0011nnnnmmmm0010(uint16_t op)
{
    /* cmp/hs Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] cmp/hs Rm,Rn --> __0011nnnnmmmm0010\n");
    exit(1);
}

void __0011nnnnmmmm0011(uint16_t op)
{
    /* cmp/ge Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] cmp/ge Rm,Rn --> __0011nnnnmmmm0011\n");
    exit(1);
}

void __0011nnnnmmmm0110(uint16_t op)
{
    /* cmp/hi Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] cmp/hi Rm,Rn --> __0011nnnnmmmm0110\n");
    exit(1);
}

void __0011nnnnmmmm0111(uint16_t op)
{
    /* cmp/gt Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] cmp/gt Rm,Rn --> __0011nnnnmmmm0111\n");
    exit(1);
}

void __0100nnnn00010001(uint16_t op)
{
    /* cmp/pz Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] cmp/pz Rn --> __0100nnnn00010001\n");
    exit(1);
}

void __0100nnnn00010101(uint16_t op)
{
    /* cmp/pl Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] cmp/pl Rn --> __0100nnnn00010101\n");
    exit(1);
}

void __0010nnnnmmmm1100(uint16_t op)
{
    /* cmp/str Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] cmp/str Rm,Rn --> __0010nnnnmmmm1100\n");
    exit(1);
}

void __0011nnnnmmmm0100(uint16_t op)
{
    /* div1 Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] div1 Rm,Rn --> __0011nnnnmmmm0100\n");
    exit(1);
}

void __0010nnnnmmmm0111(uint16_t op)
{
    /* div0s Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] div0s Rm,Rn --> __0010nnnnmmmm0111\n");
    exit(1);
}

void __0000000000011001(uint16_t op)
{
    /* div0u */
    fprintf(stderr, "[NOT IMPLEMENTED!] div0u --> __0000000000011001\n");
    exit(1);
}

void __0011nnnnmmmm1101(uint16_t op)
{
    /* dmuls.l Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] dmuls.l Rm,Rn --> __0011nnnnmmmm1101\n");
    exit(1);
}

void __0011nnnnmmmm0101(uint16_t op)
{
    /* dmulu.l Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] dmulu.l Rm,Rn --> __0011nnnnmmmm0101\n");
    exit(1);
}

void __0100nnnn00010000(uint16_t op)
{
    /* dt Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] dt Rn --> __0100nnnn00010000\n");
    exit(1);
}

void __0110nnnnmmmm1110(uint16_t op)
{
    /* exts.b Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] exts.b Rm,Rn --> __0110nnnnmmmm1110\n");
    exit(1);
}

void __0110nnnnmmmm1111(uint16_t op)
{
    /* exts.w Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] exts.w Rm,Rn --> __0110nnnnmmmm1111\n");
    exit(1);
}

void __0110nnnnmmmm1100(uint16_t op)
{
    /* extu.b Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] extu.b Rm,Rn --> __0110nnnnmmmm1100\n");
    exit(1);
}

void __0110nnnnmmmm1101(uint16_t op)
{
    /* extu.w Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] extu.w Rm,Rn --> __0110nnnnmmmm1101\n");
    exit(1);
}

void __0000nnnnmmmm1111(uint16_t op)
{
    /* mac.l @Rm+,@Rn+ */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mac.l @Rm+,@Rn+ --> __0000nnnnmmmm1111\n");
    exit(1);
}

void __0100nnnnmmmm1111(uint16_t op)
{
    /* mac.w @Rm+,@Rn+ */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mac.w @Rm+,@Rn+ --> __0100nnnnmmmm1111\n");
    exit(1);
}

void __0000nnnnmmmm0111(uint16_t op)
{
    /* mul.l Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mul.l Rm,Rn --> __0000nnnnmmmm0111\n");
    exit(1);
}

void __0010nnnnmmmm1111(uint16_t op)
{
    /* muls.w Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] muls.w Rm,Rn --> __0010nnnnmmmm1111\n");
    exit(1);
}

void __0010nnnnmmmm1110(uint16_t op)
{
    /* mulu.w Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] mulu.w Rm,Rn --> __0010nnnnmmmm1110\n");
    exit(1);
}

void __0110nnnnmmmm1011(uint16_t op)
{
    /* neg Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] neg Rm,Rn --> __0110nnnnmmmm1011\n");
    exit(1);
}

void __0110nnnnmmmm1010(uint16_t op)
{
    /* negc Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] negc Rm,Rn --> __0110nnnnmmmm1010\n");
    exit(1);
}

void __0011nnnnmmmm1000(uint16_t op)
{
    /* sub Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sub Rm,Rn --> __0011nnnnmmmm1000\n");
    exit(1);
}

void __0011nnnnmmmm1010(uint16_t op)
{
    /* subc Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] subc Rm,Rn --> __0011nnnnmmmm1010\n");
    exit(1);
}

void __0011nnnnmmmm1011(uint16_t op)
{
    /* subv Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] subv Rm,Rn --> __0011nnnnmmmm1011\n");
    exit(1);
}

void __0010nnnnmmmm1001(uint16_t op)
{
    /* and Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] and Rm,Rn --> __0010nnnnmmmm1001\n");
    exit(1);
}

void __11001001iiiiiiii(uint16_t op)
{
    /* and #i,R0 */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] and #i,R0 --> __11001001iiiiiiii\n");
    exit(1);
}

void __11001101iiiiiiii(uint16_t op)
{
    /* and.b #i,@(R0,GBR) */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] and.b #i,@(R0,GBR) --> __11001101iiiiiiii\n");
    exit(1);
}

void __0110nnnnmmmm0111(uint16_t op)
{
    /* not Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] not Rm,Rn --> __0110nnnnmmmm0111\n");
    exit(1);
}

void __0010nnnnmmmm1011(uint16_t op)
{
    /* or Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] or Rm,Rn --> __0010nnnnmmmm1011\n");
    exit(1);
}

void __11001011iiiiiiii(uint16_t op)
{
    /* or #i,R0 */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] or #i,R0 --> __11001011iiiiiiii\n");
    exit(1);
}

void __11001111iiiiiiii(uint16_t op)
{
    /* or.b #i,@(R0,GBR) */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] or.b #i,@(R0,GBR) --> __11001111iiiiiiii\n");
    exit(1);
}

void __0100nnnn00011011(uint16_t op)
{
    /* tas.b @Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] tas.b @Rn --> __0100nnnn00011011\n");
    exit(1);
}

void __0010nnnnmmmm1000(uint16_t op)
{
    /* tst Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] tst Rm,Rn --> __0010nnnnmmmm1000\n");
    exit(1);
}

void __11001000iiiiiiii(uint16_t op)
{
    /* tst #i,R0 */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] tst #i,R0 --> __11001000iiiiiiii\n");
    exit(1);
}

void __11001100iiiiiiii(uint16_t op)
{
    /* tst.b #i,@(R0,GBR) */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] tst.b #i,@(R0,GBR) --> __11001100iiiiiiii\n");
    exit(1);
}

void __0010nnnnmmmm1010(uint16_t op)
{
    /* xor Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] xor Rm,Rn --> __0010nnnnmmmm1010\n");
    exit(1);
}

void __11001010iiiiiiii(uint16_t op)
{
    /* xor #i,R0 */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] xor #i,R0 --> __11001010iiiiiiii\n");
    exit(1);
}

void __11001110iiiiiiii(uint16_t op)
{
    /* xor.b #i,@(R0,GBR) */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] xor.b #i,@(R0,GBR) --> __11001110iiiiiiii\n");
    exit(1);
}

void __0100nnnn00000100(uint16_t op)
{
    /* rotl Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] rotl Rn --> __0100nnnn00000100\n");
    exit(1);
}

void __0100nnnn00000101(uint16_t op)
{
    /* rotr Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] rotr Rn --> __0100nnnn00000101\n");
    exit(1);
}

void __0100nnnn00100100(uint16_t op)
{
    /* rotcl Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] rotcl Rn --> __0100nnnn00100100\n");
    exit(1);
}

void __0100nnnn00100101(uint16_t op)
{
    /* rotcr Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] rotcr Rn --> __0100nnnn00100101\n");
    exit(1);
}

void __0100nnnnmmmm1100(uint16_t op)
{
    /* shad Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shad Rm,Rn --> __0100nnnnmmmm1100\n");
    exit(1);
}

void __0100nnnn00100000(uint16_t op)
{
    /* shal Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shal Rn --> __0100nnnn00100000\n");
    exit(1);
}

void __0100nnnn00100001(uint16_t op)
{
    /* shar Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shar Rn --> __0100nnnn00100001\n");
    exit(1);
}

void __0100nnnnmmmm1101(uint16_t op)
{
    /* shld Rm,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shld Rm,Rn --> __0100nnnnmmmm1101\n");
    exit(1);
}

void __0100nnnn00000000(uint16_t op)
{
    /* shll Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shll Rn --> __0100nnnn00000000\n");
    exit(1);
}

void __0100nnnn00000001(uint16_t op)
{
    /* shlr Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shlr Rn --> __0100nnnn00000001\n");
    exit(1);
}

void __0100nnnn00001000(uint16_t op)
{
    /* shll2 Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shll2 Rn --> __0100nnnn00001000\n");
    exit(1);
}

void __0100nnnn00001001(uint16_t op)
{
    /* shlr2 Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shlr2 Rn --> __0100nnnn00001001\n");
    exit(1);
}

void __0100nnnn00011000(uint16_t op)
{
    /* shll8 Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shll8 Rn --> __0100nnnn00011000\n");
    exit(1);
}

void __0100nnnn00011001(uint16_t op)
{
    /* shlr8 Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shlr8 Rn --> __0100nnnn00011001\n");
    exit(1);
}

void __0100nnnn00101000(uint16_t op)
{
    /* shll16 Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shll16 Rn --> __0100nnnn00101000\n");
    exit(1);
}

void __0100nnnn00101001(uint16_t op)
{
    /* shlr16 Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] shlr16 Rn --> __0100nnnn00101001\n");
    exit(1);
}

void __10001011dddddddd(uint16_t op)
{
    /* bf d */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] bf d --> __10001011dddddddd\n");
    exit(1);
}

void __10001111dddddddd(uint16_t op)
{
    /* bf/s d */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] bf/s d --> __10001111dddddddd\n");
    exit(1);
}

void __10001001dddddddd(uint16_t op)
{
    /* bt d */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] bt d --> __10001001dddddddd\n");
    exit(1);
}

void __10001101dddddddd(uint16_t op)
{
    /* bt/s d */
    uint8_t d = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] bt/s d --> __10001101dddddddd\n");
    exit(1);
}

void __1010dddddddddddd(uint16_t op)
{
    /* bra d */
    uint16_t d = op&0xfff;
    fprintf(stderr, "[NOT IMPLEMENTED!] bra d --> __1010dddddddddddd\n");
    exit(1);
}

void __0000nnnn00100011(uint16_t op)
{
    /* braf Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] braf Rn --> __0000nnnn00100011\n");
    exit(1);
}

void __1011dddddddddddd(uint16_t op)
{
    /* bsr d */
    uint16_t d = op&0xfff;
    fprintf(stderr, "[NOT IMPLEMENTED!] bsr d --> __1011dddddddddddd\n");
    exit(1);
}

void __0000nnnn00000011(uint16_t op)
{
    /* bsrf Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] bsrf Rn --> __0000nnnn00000011\n");
    exit(1);
}

void __0100nnnn00101011(uint16_t op)
{
    /* jmp @Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] jmp @Rn --> __0100nnnn00101011\n");
    exit(1);
}

void __0100nnnn00001011(uint16_t op)
{
    /* jsr @Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] jsr @Rn --> __0100nnnn00001011\n");
    exit(1);
}

void __0000000000001011(uint16_t op)
{
    /* rts */
    fprintf(stderr, "[NOT IMPLEMENTED!] rts --> __0000000000001011\n");
    exit(1);
}

void __0000000000101000(uint16_t op)
{
    /* clrmac */
    fprintf(stderr, "[NOT IMPLEMENTED!] clrmac --> __0000000000101000\n");
    exit(1);
}

void __0000000001001000(uint16_t op)
{
    /* clrs */
    fprintf(stderr, "[NOT IMPLEMENTED!] clrs --> __0000000001001000\n");
    exit(1);
}

void __0000000000001000(uint16_t op)
{
    /* clrt */
    fprintf(stderr, "[NOT IMPLEMENTED!] clrt --> __0000000000001000\n");
    exit(1);
}

void __0100mmmm00001110(uint16_t op)
{
    /* ldc Rm,SR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc Rm,SR --> __0100mmmm00001110\n");
    exit(1);
}

void __0100mmmm00011110(uint16_t op)
{
    /* ldc Rm,GBR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc Rm,GBR --> __0100mmmm00011110\n");
    exit(1);
}

void __0100mmmm00101110(uint16_t op)
{
    /* ldc Rm,VBR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc Rm,VBR --> __0100mmmm00101110\n");
    exit(1);
}

void __0100mmmm00111110(uint16_t op)
{
    /* ldc Rm,SSR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc Rm,SSR --> __0100mmmm00111110\n");
    exit(1);
}

void __0100mmmm01001110(uint16_t op)
{
    /* ldc Rm,SPC */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc Rm,SPC --> __0100mmmm01001110\n");
    exit(1);
}

void __0100mmmm11111010(uint16_t op)
{
    /* ldc Rm,DBR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc Rm,DBR --> __0100mmmm11111010\n");
    exit(1);
}

void __0100mmmm1nnn1110(uint16_t op)
{
    /* ldc Rm,Rn_BANK */
    uint8_t m = (op>>8)&0xf;
    uint8_t n = (op>>4)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc Rm,Rn_BANK --> __0100mmmm1nnn1110\n");
    exit(1);
}

void __0100mmmm00000111(uint16_t op)
{
    /* ldc.l @Rm+,SR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc.l @Rm+,SR --> __0100mmmm00000111\n");
    exit(1);
}

void __0100mmmm00010111(uint16_t op)
{
    /* ldc.l @Rm+,GBR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc.l @Rm+,GBR --> __0100mmmm00010111\n");
    exit(1);
}

void __0100mmmm00100111(uint16_t op)
{
    /* ldc.l @Rm+,VBR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc.l @Rm+,VBR --> __0100mmmm00100111\n");
    exit(1);
}

void __0100mmmm00110111(uint16_t op)
{
    /* ldc.l @Rm+,SSR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc.l @Rm+,SSR --> __0100mmmm00110111\n");
    exit(1);
}

void __0100mmmm01000111(uint16_t op)
{
    /* ldc.l @Rm+,SPC */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc.l @Rm+,SPC --> __0100mmmm01000111\n");
    exit(1);
}

void __0100mmmm11110110(uint16_t op)
{
    /* ldc.l @Rm+,DBR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc.l @Rm+,DBR --> __0100mmmm11110110\n");
    exit(1);
}

void __0100mmmm1nnn0111(uint16_t op)
{
    /* ldc.l @Rm+,Rn_BANK */
    uint8_t m = (op>>8)&0xf;
    uint8_t n = (op>>4)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] ldc.l @Rm+,Rn_BANK --> __0100mmmm1nnn0111\n");
    exit(1);
}

void __0100mmmm00001010(uint16_t op)
{
    /* lds Rm,MACH */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds Rm,MACH --> __0100mmmm00001010\n");
    exit(1);
}

void __0100mmmm00011010(uint16_t op)
{
    /* lds Rm,MACL */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds Rm,MACL --> __0100mmmm00011010\n");
    exit(1);
}

void __0100mmmm00101010(uint16_t op)
{
    /* lds Rm,PR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds Rm,PR --> __0100mmmm00101010\n");
    exit(1);
}

void __0100mmmm00000110(uint16_t op)
{
    /* lds.l @Rm+,MACH */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds.l @Rm+,MACH --> __0100mmmm00000110\n");
    exit(1);
}

void __0100mmmm00010110(uint16_t op)
{
    /* lds.l @Rm+,MACL */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds.l @Rm+,MACL --> __0100mmmm00010110\n");
    exit(1);
}

void __0100mmmm00100110(uint16_t op)
{
    /* lds.l @Rm+,PR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds.l @Rm+,PR --> __0100mmmm00100110\n");
    exit(1);
}

void __0000000000111000(uint16_t op)
{
    /* ldtlb */
    fprintf(stderr, "[NOT IMPLEMENTED!] ldtlb --> __0000000000111000\n");
    exit(1);
}

void __0000nnnn11000011(uint16_t op)
{
    /* movca.l R0,@Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] movca.l R0,@Rn --> __0000nnnn11000011\n");
    exit(1);
}

void __0000000000001001(uint16_t op)
{
    /* nop */
    fprintf(stderr, "[NOT IMPLEMENTED!] nop --> __0000000000001001\n");
    exit(1);
}

void __0000nnnn10010011(uint16_t op)
{
    /* ocbi @Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ocbi @Rn --> __0000nnnn10010011\n");
    exit(1);
}

void __0000nnnn10100011(uint16_t op)
{
    /* ocbp @Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ocbp @Rn --> __0000nnnn10100011\n");
    exit(1);
}

void __0000nnnn10110011(uint16_t op)
{
    /* ocbwb @Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ocbwb @Rn --> __0000nnnn10110011\n");
    exit(1);
}

void __0000nnnn10000011(uint16_t op)
{
    /* pref @Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] pref @Rn --> __0000nnnn10000011\n");
    exit(1);
}

void __0000000000101011(uint16_t op)
{
    /* rte */
    fprintf(stderr, "[NOT IMPLEMENTED!] rte --> __0000000000101011\n");
    exit(1);
}

void __0000000001011000(uint16_t op)
{
    /* sets */
    fprintf(stderr, "[NOT IMPLEMENTED!] sets --> __0000000001011000\n");
    exit(1);
}

void __0000000000011000(uint16_t op)
{
    /* sett */
    fprintf(stderr, "[NOT IMPLEMENTED!] sett --> __0000000000011000\n");
    exit(1);
}

void __0000000000011011(uint16_t op)
{
    /* sleep */
    fprintf(stderr, "[NOT IMPLEMENTED!] sleep --> __0000000000011011\n");
    exit(1);
}

void __0000nnnn00000010(uint16_t op)
{
    /* stc SR,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc SR,Rn --> __0000nnnn00000010\n");
    exit(1);
}

void __0000nnnn00010010(uint16_t op)
{
    /* stc GBR,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc GBR,Rn --> __0000nnnn00010010\n");
    exit(1);
}

void __0000nnnn00100010(uint16_t op)
{
    /* stc VBR,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc VBR,Rn --> __0000nnnn00100010\n");
    exit(1);
}

void __0000nnnn00110010(uint16_t op)
{
    /* stc SSR,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc SSR,Rn --> __0000nnnn00110010\n");
    exit(1);
}

void __0000nnnn01000010(uint16_t op)
{
    /* stc SPC,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc SPC,Rn --> __0000nnnn01000010\n");
    exit(1);
}

void __0000nnnn00111010(uint16_t op)
{
    /* stc SGR,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc SGR,Rn --> __0000nnnn00111010\n");
    exit(1);
}

void __0000nnnn11111010(uint16_t op)
{
    /* stc DBR,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc DBR,Rn --> __0000nnnn11111010\n");
    exit(1);
}

void __0000nnnn1mmm0010(uint16_t op)
{
    /* stc Rm_BANK,Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc Rm_BANK,Rn --> __0000nnnn1mmm0010\n");
    exit(1);
}

void __0100nnnn00000011(uint16_t op)
{
    /* stc.l SR,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc.l SR,@-Rn --> __0100nnnn00000011\n");
    exit(1);
}

void __0100nnnn00010011(uint16_t op)
{
    /* stc.l GBR,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc.l GBR,@-Rn --> __0100nnnn00010011\n");
    exit(1);
}

void __0100nnnn00100011(uint16_t op)
{
    /* stc.l VBR,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc.l VBR,@-Rn --> __0100nnnn00100011\n");
    exit(1);
}

void __0100nnnn00110011(uint16_t op)
{
    /* stc.l SSR,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc.l SSR,@-Rn --> __0100nnnn00110011\n");
    exit(1);
}

void __0100nnnn01000011(uint16_t op)
{
    /* stc.l SPC,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc.l SPC,@-Rn --> __0100nnnn01000011\n");
    exit(1);
}

void __0100nnnn00110010(uint16_t op)
{
    /* stc.l SGR,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc.l SGR,@-Rn --> __0100nnnn00110010\n");
    exit(1);
}

void __0100nnnn11110010(uint16_t op)
{
    /* stc.l DBR,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc.l DBR,@-Rn --> __0100nnnn11110010\n");
    exit(1);
}

void __0100nnnn1mmm0011(uint16_t op)
{
    /* stc.l Rm_BANK,@-Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] stc.l Rm_BANK,@-Rn --> __0100nnnn1mmm0011\n");
    exit(1);
}

void __0000nnnn00001010(uint16_t op)
{
    /* sts MACH,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts MACH,Rn --> __0000nnnn00001010\n");
    exit(1);
}

void __0000nnnn00011010(uint16_t op)
{
    /* sts MACL,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts MACL,Rn --> __0000nnnn00011010\n");
    exit(1);
}

void __0000nnnn00101010(uint16_t op)
{
    /* sts PR,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts PR,Rn --> __0000nnnn00101010\n");
    exit(1);
}

void __0100nnnn00000010(uint16_t op)
{
    /* sts.l MACH,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts.l MACH,@-Rn --> __0100nnnn00000010\n");
    exit(1);
}

void __0100nnnn00010010(uint16_t op)
{
    /* sts.l MACL,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts.l MACL,@-Rn --> __0100nnnn00010010\n");
    exit(1);
}

void __0100nnnn00100010(uint16_t op)
{
    /* sts.l PR,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts.l PR,@-Rn --> __0100nnnn00100010\n");
    exit(1);
}

void __11000011iiiiiiii(uint16_t op)
{
    /* trapa #i */
    uint8_t i = op&0xff;
    fprintf(stderr, "[NOT IMPLEMENTED!] trapa #i --> __11000011iiiiiiii\n");
    exit(1);
}

void __1111nnnn10001101(uint16_t op)
{
    /* fldi0 FRn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fldi0 FRn --> __1111nnnn10001101\n");
    exit(1);
}

void __1111nnnn10011101(uint16_t op)
{
    /* fldi1 FRn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fldi1 FRn --> __1111nnnn10011101\n");
    exit(1);
}

void __1111nnnnmmmm1100(uint16_t op)
{
    /* fmov FRm,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov FRm,FRn --> __1111nnnnmmmm1100\n");
    exit(1);
}

void __1111nnnnmmmm1000(uint16_t op)
{
    /* fmov.s @Rm,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov.s @Rm,FRn --> __1111nnnnmmmm1000\n");
    exit(1);
}

void __1111nnnnmmmm0110(uint16_t op)
{
    /* fmov.s @(R0,Rm),FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov.s @(R0,Rm),FRn --> __1111nnnnmmmm0110\n");
    exit(1);
}

void __1111nnnnmmmm1001(uint16_t op)
{
    /* fmov.s @Rm+,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov.s @Rm+,FRn --> __1111nnnnmmmm1001\n");
    exit(1);
}

void __1111nnnnmmmm1010(uint16_t op)
{
    /* fmov.s FRm,@Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov.s FRm,@Rn --> __1111nnnnmmmm1010\n");
    exit(1);
}

void __1111nnnnmmmm1011(uint16_t op)
{
    /* fmov.s FRm,@-Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov.s FRm,@-Rn --> __1111nnnnmmmm1011\n");
    exit(1);
}

void __1111nnnnmmmm0111(uint16_t op)
{
    /* fmov.s FRm,@(R0,Rn) */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov.s FRm,@(R0,Rn) --> __1111nnnnmmmm0111\n");
    exit(1);
}

void __1111nnn0mmm01100(uint16_t op)
{
    /* fmov DRm,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov DRm,DRn --> __1111nnn0mmm01100\n");
    exit(1);
}

void __1111nnn0mmmm1000(uint16_t op)
{
    /* fmov @Rm,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov @Rm,DRn --> __1111nnn0mmmm1000\n");
    exit(1);
}

void __1111nnn0mmmm0110(uint16_t op)
{
    /* fmov @(R0,Rm),DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov @(R0,Rm),DRn --> __1111nnn0mmmm0110\n");
    exit(1);
}

void __1111nnn0mmmm1001(uint16_t op)
{
    /* fmov @Rm+,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov @Rm+,DRn --> __1111nnn0mmmm1001\n");
    exit(1);
}

void __1111nnnnmmm01010(uint16_t op)
{
    /* fmov DRm,@Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov DRm,@Rn --> __1111nnnnmmm01010\n");
    exit(1);
}

void __1111nnnnmmm01011(uint16_t op)
{
    /* fmov DRm,@-Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov DRm,@-Rn --> __1111nnnnmmm01011\n");
    exit(1);
}

void __1111nnnnmmm00111(uint16_t op)
{
    /* fmov DRm,@(R0,Rn) */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov DRm,@(R0,Rn) --> __1111nnnnmmm00111\n");
    exit(1);
}

void __1111mmmm00011101(uint16_t op)
{
    /* flds FRm,FPUL */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] flds FRm,FPUL --> __1111mmmm00011101\n");
    exit(1);
}

void __1111nnnn00001101(uint16_t op)
{
    /* fsts FPUL,FRn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fsts FPUL,FRn --> __1111nnnn00001101\n");
    exit(1);
}

void __1111nnnn01011101(uint16_t op)
{
    /* fabs FRn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fabs FRn --> __1111nnnn01011101\n");
    exit(1);
}

void __1111nnnnmmmm0000(uint16_t op)
{
    /* fadd FRm,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fadd FRm,FRn --> __1111nnnnmmmm0000\n");
    exit(1);
}

void __1111nnnnmmmm0100(uint16_t op)
{
    /* fcmp/eq FRm,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fcmp/eq FRm,FRn --> __1111nnnnmmmm0100\n");
    exit(1);
}

void __1111nnnnmmmm0101(uint16_t op)
{
    /* fcmp/gt FRm,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fcmp/gt FRm,FRn --> __1111nnnnmmmm0101\n");
    exit(1);
}

void __1111nnnnmmmm0011(uint16_t op)
{
    /* fdiv FRm,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fdiv FRm,FRn --> __1111nnnnmmmm0011\n");
    exit(1);
}

void __1111nnnn00101101(uint16_t op)
{
    /* float FPUL,FRn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] float FPUL,FRn --> __1111nnnn00101101\n");
    exit(1);
}

void __1111nnnnmmmm1110(uint16_t op)
{
    /* fmac FR0,FRm,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmac FR0,FRm,FRn --> __1111nnnnmmmm1110\n");
    exit(1);
}

void __1111nnnnmmmm0010(uint16_t op)
{
    /* fmul FRm,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmul FRm,FRn --> __1111nnnnmmmm0010\n");
    exit(1);
}

void __1111nnnn01001101(uint16_t op)
{
    /* fneg FRn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fneg FRn --> __1111nnnn01001101\n");
    exit(1);
}

void __1111nnnn01101101(uint16_t op)
{
    /* fsqrt FRn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fsqrt FRn --> __1111nnnn01101101\n");
    exit(1);
}

void __1111nnnnmmmm0001(uint16_t op)
{
    /* fsub FRm,FRn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fsub FRm,FRn --> __1111nnnnmmmm0001\n");
    exit(1);
}

void __1111mmmm00111101(uint16_t op)
{
    /* ftrc FRm,FPUL */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] ftrc FRm,FPUL --> __1111mmmm00111101\n");
    exit(1);
}

void __1111nnn001011101(uint16_t op)
{
    /* fabs DRn */
    uint8_t n = (op>>9)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fabs DRn --> __1111nnn001011101\n");
    exit(1);
}

void __1111nnn0mmm00000(uint16_t op)
{
    /* fadd DRm,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fadd DRm,DRn --> __1111nnn0mmm00000\n");
    exit(1);
}

void __1111nnn0mmm00100(uint16_t op)
{
    /* fcmp/eq DRm,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fcmp/eq DRm,DRn --> __1111nnn0mmm00100\n");
    exit(1);
}

void __1111nnn0mmm00101(uint16_t op)
{
    /* fcmp/gt DRm,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fcmp/gt DRm,DRn --> __1111nnn0mmm00101\n");
    exit(1);
}

void __1111nnn0mmm00011(uint16_t op)
{
    /* fdiv DRm,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fdiv DRm,DRn --> __1111nnn0mmm00011\n");
    exit(1);
}

void __1111mmm010111101(uint16_t op)
{
    /* fcnvds DRm,FPUL */
    uint8_t m = (op>>9)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fcnvds DRm,FPUL --> __1111mmm010111101\n");
    exit(1);
}

void __1111nnn010101101(uint16_t op)
{
    /* fcnvsd FPUL,DRn */
    uint8_t n = (op>>9)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fcnvsd FPUL,DRn --> __1111nnn010101101\n");
    exit(1);
}

void __1111nnn000101101(uint16_t op)
{
    /* float FPUL,DRn */
    uint8_t n = (op>>9)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] float FPUL,DRn --> __1111nnn000101101\n");
    exit(1);
}

void __1111nnn0mmm00010(uint16_t op)
{
    /* fmul DRm,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmul DRm,DRn --> __1111nnn0mmm00010\n");
    exit(1);
}

void __1111nnn001001101(uint16_t op)
{
    /* fneg DRn */
    uint8_t n = (op>>9)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fneg DRn --> __1111nnn001001101\n");
    exit(1);
}

void __1111nnn001101101(uint16_t op)
{
    /* fsqrt DRn */
    uint8_t n = (op>>9)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fsqrt DRn --> __1111nnn001101101\n");
    exit(1);
}

void __1111nnn0mmm00001(uint16_t op)
{
    /* fsub DRm,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fsub DRm,DRn --> __1111nnn0mmm00001\n");
    exit(1);
}

void __1111mmm000111101(uint16_t op)
{
    /* ftrc DRm,FPUL */
    uint8_t m = (op>>9)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] ftrc DRm,FPUL --> __1111mmm000111101\n");
    exit(1);
}

void __0100mmmm01101010(uint16_t op)
{
    /* lds Rm,FPSCR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds Rm,FPSCR --> __0100mmmm01101010\n");
    exit(1);
}

void __0100mmmm01011010(uint16_t op)
{
    /* lds Rm,FPUL */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds Rm,FPUL --> __0100mmmm01011010\n");
    exit(1);
}

void __0100mmmm01100110(uint16_t op)
{
    /* lds.l @Rm+,FPSCR */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds.l @Rm+,FPSCR --> __0100mmmm01100110\n");
    exit(1);
}

void __0100mmmm01010110(uint16_t op)
{
    /* lds.l @Rm+,FPUL */
    uint8_t m = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] lds.l @Rm+,FPUL --> __0100mmmm01010110\n");
    exit(1);
}

void __0000nnnn01101010(uint16_t op)
{
    /* sts FPSCR,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts FPSCR,Rn --> __0000nnnn01101010\n");
    exit(1);
}

void __0000nnnn01011010(uint16_t op)
{
    /* sts FPUL,Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts FPUL,Rn --> __0000nnnn01011010\n");
    exit(1);
}

void __0100nnnn01100010(uint16_t op)
{
    /* sts.l FPSCR,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts.l FPSCR,@-Rn --> __0100nnnn01100010\n");
    exit(1);
}

void __0100nnnn01010010(uint16_t op)
{
    /* sts.l FPUL,@-Rn */
    uint8_t n = (op>>8)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] sts.l FPUL,@-Rn --> __0100nnnn01010010\n");
    exit(1);
}

void __1111nnn1mmm01100(uint16_t op)
{
    /* fmov DRm,XDn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov DRm,XDn --> __1111nnn1mmm01100\n");
    exit(1);
}

void __1111nnn0mmm11100(uint16_t op)
{
    /* fmov XDm,DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov XDm,DRn --> __1111nnn0mmm11100\n");
    exit(1);
}

void __1111nnn1mmm11100(uint16_t op)
{
    /* fmov XDm,XDn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov XDm,XDn --> __1111nnn1mmm11100\n");
    exit(1);
}

void __1111nnn1mmmm1000(uint16_t op)
{
    /* fmov @Rm,XDn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov @Rm,XDn --> __1111nnn1mmmm1000\n");
    exit(1);
}

void __1111nnn1mmmm1001(uint16_t op)
{
    /* fmov @Rm+,XDn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov @Rm+,XDn --> __1111nnn1mmmm1001\n");
    exit(1);
}

void __1111nnn1mmmm0110(uint16_t op)
{
    /* fmov @(R0,Rm),DRn */
    uint8_t n = (op>>9)&0x7;
    uint8_t m = (op>>4)&0xf;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov @(R0,Rm),DRn --> __1111nnn1mmmm0110\n");
    exit(1);
}

void __1111nnnnmmm11010(uint16_t op)
{
    /* fmov XDm,@Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov XDm,@Rn --> __1111nnnnmmm11010\n");
    exit(1);
}

void __1111nnnnmmm11011(uint16_t op)
{
    /* fmov XDm,@-Rn */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov XDm,@-Rn --> __1111nnnnmmm11011\n");
    exit(1);
}

void __1111nnnnmmm10111(uint16_t op)
{
    /* fmov XDm,@(R0,Rn) */
    uint8_t n = (op>>8)&0xf;
    uint8_t m = (op>>5)&0x7;
    fprintf(stderr, "[NOT IMPLEMENTED!] fmov XDm,@(R0,Rn) --> __1111nnnnmmm10111\n");
    exit(1);
}

void __1111nnmm11101101(uint16_t op)
{
    /* fipr FVm,FVn */
    uint8_t n = (op>>10)&0x3;
    uint8_t m = (op>>8)&0x3;
    fprintf(stderr, "[NOT IMPLEMENTED!] fipr FVm,FVn --> __1111nnmm11101101\n");
    exit(1);
}

void __1111nn0111111101(uint16_t op)
{
    /* ftrv XMTRX,FVn */
    uint8_t n = (op>>10)&0x3;
    fprintf(stderr, "[NOT IMPLEMENTED!] ftrv XMTRX,FVn --> __1111nn0111111101\n");
    exit(1);
}

void __1111101111111101(uint16_t op)
{
    /* frchg */
    fprintf(stderr, "[NOT IMPLEMENTED!] frchg --> __1111101111111101\n");
    exit(1);
}

void __1111001111111101(uint16_t op)
{
    /* fschg */
    fprintf(stderr, "[NOT IMPLEMENTED!] fschg --> __1111001111111101\n");
    exit(1);
}

