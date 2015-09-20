/*********************************************
 * sh4opcodedis.c
 *
 * Contains the implementation of the processing functions for the disassembler
 *
 * @author Roberto Cano <roberto dot cano at google mail>
 *
 * THIS FILE IS AUTOMATICALLY GENERATED.
 * DO NOT MODIFY!!!!
 *
 *********************************************/
#include "sh4opcode.h"
#include <ncurses.h>
#include <stdlib.h>

void __0000000000000000_dis(SH4Context_t *c, uint16_t op)
{
    /* EXCEPTION */
    printw(".word 0x%04x", op);
}

void __1110nnnniiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* mov     #i,rn */
    int8_t n = (op>>8)&0xf;
    int8_t i = op&0xff;
    printw("mov     #%d,r%d", i, n);
}

void __1001nnnndddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @(d,pc),rn */
    int8_t n = (op>>8)&0xf;
    int8_t d = op&0xff;
    printw("mov.w   @(%d,pc),r%d", d, n);
}

void __1101nnnndddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @(d,pc),rn */
    int8_t n = (op>>8)&0xf;
    int8_t d = op&0xff;
    printw("mov.l   @(%d,pc),r%d", d, n);
}

void __0110nnnnmmmm0011_dis(SH4Context_t *c, uint16_t op)
{
    /* mov     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov     r%d,r%d", m, n);
}

void __0010nnnnmmmm0000_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   rm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.b   r%d,@r%d", m, n);
}

void __0010nnnnmmmm0001_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   rm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.w   r%d,@r%d", m, n);
}

void __0010nnnnmmmm0010_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   rm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.l   r%d,@r%d", m, n);
}

void __0110nnnnmmmm0000_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.b   @r%d,r%d", m, n);
}

void __0110nnnnmmmm0001_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.w   @r%d,r%d", m, n);
}

void __0110nnnnmmmm0010_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.l   @r%d,r%d", m, n);
}

void __0010nnnnmmmm0100_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   rm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.b   r%d,@-r%d", m, n);
}

void __0010nnnnmmmm0101_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   rm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.w   r%d,@-r%d", m, n);
}

void __0010nnnnmmmm0110_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   rm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.l   r%d,@-r%d", m, n);
}

void __0110nnnnmmmm0100_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @rm+,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.b   @r%d+,r%d", m, n);
}

void __0110nnnnmmmm0101_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @rm+,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.w   @r%d+,r%d", m, n);
}

void __0110nnnnmmmm0110_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @rm+,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.l   @r%d+,r%d", m, n);
}

void __10000000nnnndddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   r0,@(d,rn) */
    int8_t n = (op>>4)&0xf;
    int8_t d = op&0xf;
    printw("mov.b   r0,@(%d,r%d)", d, n);
}

void __10000001nnnndddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   r0,@(d,rn) */
    int8_t n = (op>>4)&0xf;
    int8_t d = op&0xf;
    printw("mov.w   r0,@(%d,r%d)", d, n);
}

void __0001nnnnmmmmdddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   rm,@(d,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    int8_t d = op&0xf;
    printw("mov.l   r%d,@(%d,r%d)", m, d, n);
}

void __10000100mmmmdddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @(d,rm),r0 */
    int8_t m = (op>>4)&0xf;
    int8_t d = op&0xf;
    printw("mov.b   @(%d,r%d),r0", d, m);
}

void __10000101mmmmdddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @(d,rm),r0 */
    int8_t m = (op>>4)&0xf;
    int8_t d = op&0xf;
    printw("mov.w   @(%d,r%d),r0", d, m);
}

void __0101nnnnmmmmdddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @(d,rm),rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    int8_t d = op&0xf;
    printw("mov.l   @(%d,r%d),r%d", d, m, n);
}

void __0000nnnnmmmm0100_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   rm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.b   r%d,@(r0,r%d)", m, n);
}

void __0000nnnnmmmm0101_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   rm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.w   r%d,@(r0,r%d)", m, n);
}

void __0000nnnnmmmm0110_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   rm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.l   r%d,@(r0,r%d)", m, n);
}

void __0000nnnnmmmm1100_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @(r0,rm),rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.b   @(r0,r%d),r%d", m, n);
}

void __0000nnnnmmmm1101_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @(r0,rm),rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.w   @(r0,r%d),r%d", m, n);
}

void __0000nnnnmmmm1110_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @(r0,rm),rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mov.l   @(r0,r%d),r%d", m, n);
}

void __11000000dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   r0,@(d,gbr) */
    int8_t d = op&0xff;
    printw("mov.b   r0,@(%d,gbr)", d);
}

void __11000001dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   r0,@(d,gbr) */
    int8_t d = op&0xff;
    printw("mov.w   r0,@(%d,gbr)", d);
}

void __11000010dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   r0,@(d,gbr) */
    int8_t d = op&0xff;
    printw("mov.l   r0,@(%d,gbr)", d);
}

void __11000100dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @(d,gbr),r0 */
    int8_t d = op&0xff;
    printw("mov.b   @(%d,gbr),r0", d);
}

void __11000101dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @(d,gbr),r0 */
    int8_t d = op&0xff;
    printw("mov.w   @(%d,gbr),r0", d);
}

void __11000110dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @(d,gbr),r0 */
    int8_t d = op&0xff;
    printw("mov.l   @(%d,gbr),r0", d);
}

void __11000111dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* mova    @(d,pc),r0 */
    int8_t d = op&0xff;
    printw("mova    @(%d,pc),r0", d);
}

void __0000nnnn00101001_dis(SH4Context_t *c, uint16_t op)
{
    /* movt    rn */
    int8_t n = (op>>8)&0xf;
    printw("movt    r%d", n);
}

void __0110nnnnmmmm1000_dis(SH4Context_t *c, uint16_t op)
{
    /* swap.b  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("swap.b  r%d,r%d", m, n);
}

void __0110nnnnmmmm1001_dis(SH4Context_t *c, uint16_t op)
{
    /* swap.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("swap.w  r%d,r%d", m, n);
}

void __0010nnnnmmmm1101_dis(SH4Context_t *c, uint16_t op)
{
    /* xtrct   rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("xtrct   r%d,r%d", m, n);
}

void __0011nnnnmmmm1100_dis(SH4Context_t *c, uint16_t op)
{
    /* add     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("add     r%d,r%d", m, n);
}

void __0111nnnniiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* add     #i,rn */
    int8_t n = (op>>8)&0xf;
    int8_t i = op&0xff;
    printw("add     #%d,r%d", i, n);
}

void __0011nnnnmmmm1110_dis(SH4Context_t *c, uint16_t op)
{
    /* addc    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("addc    r%d,r%d", m, n);
}

void __0011nnnnmmmm1111_dis(SH4Context_t *c, uint16_t op)
{
    /* addv    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("addv    r%d,r%d", m, n);
}

void __10001000iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* cmp/eq  #i,r0 */
    int8_t i = op&0xff;
    printw("cmp/eq  #%d,r0", i);
}

void __0011nnnnmmmm0000_dis(SH4Context_t *c, uint16_t op)
{
    /* cmp/eq  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("cmp/eq  r%d,r%d", m, n);
}

void __0011nnnnmmmm0010_dis(SH4Context_t *c, uint16_t op)
{
    /* cmp/hs  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("cmp/hs  r%d,r%d", m, n);
}

void __0011nnnnmmmm0011_dis(SH4Context_t *c, uint16_t op)
{
    /* cmp/ge  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("cmp/ge  r%d,r%d", m, n);
}

void __0011nnnnmmmm0110_dis(SH4Context_t *c, uint16_t op)
{
    /* cmp/hi  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("cmp/hi  r%d,r%d", m, n);
}

void __0011nnnnmmmm0111_dis(SH4Context_t *c, uint16_t op)
{
    /* cmp/gt  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("cmp/gt  r%d,r%d", m, n);
}

void __0100nnnn00010001_dis(SH4Context_t *c, uint16_t op)
{
    /* cmp/pz  rn */
    int8_t n = (op>>8)&0xf;
    printw("cmp/pz  r%d", n);
}

void __0100nnnn00010101_dis(SH4Context_t *c, uint16_t op)
{
    /* cmp/pl  rn */
    int8_t n = (op>>8)&0xf;
    printw("cmp/pl  r%d", n);
}

void __0010nnnnmmmm1100_dis(SH4Context_t *c, uint16_t op)
{
    /* cmp/str rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("cmp/str r%d,r%d", m, n);
}

void __0011nnnnmmmm0100_dis(SH4Context_t *c, uint16_t op)
{
    /* div1    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("div1    r%d,r%d", m, n);
}

void __0010nnnnmmmm0111_dis(SH4Context_t *c, uint16_t op)
{
    /* div0s   rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("div0s   r%d,r%d", m, n);
}

void __0000000000011001_dis(SH4Context_t *c, uint16_t op)
{
    /* div0u */
    printw("div0u");
}

void __0011nnnnmmmm1101_dis(SH4Context_t *c, uint16_t op)
{
    /* dmuls.l rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("dmuls.l r%d,r%d", m, n);
}

void __0011nnnnmmmm0101_dis(SH4Context_t *c, uint16_t op)
{
    /* dmulu.l rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("dmulu.l r%d,r%d", m, n);
}

void __0100nnnn00010000_dis(SH4Context_t *c, uint16_t op)
{
    /* dt      rn */
    int8_t n = (op>>8)&0xf;
    printw("dt      r%d", n);
}

void __0110nnnnmmmm1110_dis(SH4Context_t *c, uint16_t op)
{
    /* exts.b  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("exts.b  r%d,r%d", m, n);
}

void __0110nnnnmmmm1111_dis(SH4Context_t *c, uint16_t op)
{
    /* exts.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("exts.w  r%d,r%d", m, n);
}

void __0110nnnnmmmm1100_dis(SH4Context_t *c, uint16_t op)
{
    /* extu.b  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("extu.b  r%d,r%d", m, n);
}

void __0110nnnnmmmm1101_dis(SH4Context_t *c, uint16_t op)
{
    /* extu.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("extu.w  r%d,r%d", m, n);
}

void __0000nnnnmmmm1111_dis(SH4Context_t *c, uint16_t op)
{
    /* mac.l   @rm+,@rn+ */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mac.l   @r%d+,@r%d+", m, n);
}

void __0100nnnnmmmm1111_dis(SH4Context_t *c, uint16_t op)
{
    /* mac.w   @rm+,@rn+ */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mac.w   @r%d+,@r%d+", m, n);
}

void __0000nnnnmmmm0111_dis(SH4Context_t *c, uint16_t op)
{
    /* mul.l   rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mul.l   r%d,r%d", m, n);
}

void __0010nnnnmmmm1111_dis(SH4Context_t *c, uint16_t op)
{
    /* muls.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("muls.w  r%d,r%d", m, n);
}

void __0010nnnnmmmm1110_dis(SH4Context_t *c, uint16_t op)
{
    /* mulu.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("mulu.w  r%d,r%d", m, n);
}

void __0110nnnnmmmm1011_dis(SH4Context_t *c, uint16_t op)
{
    /* neg     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("neg     r%d,r%d", m, n);
}

void __0110nnnnmmmm1010_dis(SH4Context_t *c, uint16_t op)
{
    /* negc    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("negc    r%d,r%d", m, n);
}

void __0011nnnnmmmm1000_dis(SH4Context_t *c, uint16_t op)
{
    /* sub     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("sub     r%d,r%d", m, n);
}

void __0011nnnnmmmm1010_dis(SH4Context_t *c, uint16_t op)
{
    /* subc    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("subc    r%d,r%d", m, n);
}

void __0011nnnnmmmm1011_dis(SH4Context_t *c, uint16_t op)
{
    /* subv    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("subv    r%d,r%d", m, n);
}

void __0010nnnnmmmm1001_dis(SH4Context_t *c, uint16_t op)
{
    /* and     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("and     r%d,r%d", m, n);
}

void __11001001iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* and     #i,r0 */
    int8_t i = op&0xff;
    printw("and     #%d,r0", i);
}

void __11001101iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* and.b   #i,@(r0,gbr) */
    int8_t i = op&0xff;
    printw("and.b   #%d,@(r0,gbr)", i);
}

void __0110nnnnmmmm0111_dis(SH4Context_t *c, uint16_t op)
{
    /* not     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("not     r%d,r%d", m, n);
}

void __0010nnnnmmmm1011_dis(SH4Context_t *c, uint16_t op)
{
    /* or      rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("or      r%d,r%d", m, n);
}

void __11001011iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* or      #i,r0 */
    int8_t i = op&0xff;
    printw("or      #%d,r0", i);
}

void __11001111iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* or.b    #i,@(r0,gbr) */
    int8_t i = op&0xff;
    printw("or.b    #%d,@(r0,gbr)", i);
}

void __0100nnnn00011011_dis(SH4Context_t *c, uint16_t op)
{
    /* tas.b   @rn */
    int8_t n = (op>>8)&0xf;
    printw("tas.b   @r%d", n);
}

void __0010nnnnmmmm1000_dis(SH4Context_t *c, uint16_t op)
{
    /* tst     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("tst     r%d,r%d", m, n);
}

void __11001000iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* tst     #i,r0 */
    int8_t i = op&0xff;
    printw("tst     #%d,r0", i);
}

void __11001100iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* tst.b   #i,@(r0,gbr) */
    int8_t i = op&0xff;
    printw("tst.b   #%d,@(r0,gbr)", i);
}

void __0010nnnnmmmm1010_dis(SH4Context_t *c, uint16_t op)
{
    /* xor     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("xor     r%d,r%d", m, n);
}

void __11001010iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* xor     #i,r0 */
    int8_t i = op&0xff;
    printw("xor     #%d,r0", i);
}

void __11001110iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* xor.b   #i,@(r0,gbr) */
    int8_t i = op&0xff;
    printw("xor.b   #%d,@(r0,gbr)", i);
}

void __0100nnnn00000100_dis(SH4Context_t *c, uint16_t op)
{
    /* rotl    rn */
    int8_t n = (op>>8)&0xf;
    printw("rotl    r%d", n);
}

void __0100nnnn00000101_dis(SH4Context_t *c, uint16_t op)
{
    /* rotr    rn */
    int8_t n = (op>>8)&0xf;
    printw("rotr    r%d", n);
}

void __0100nnnn00100100_dis(SH4Context_t *c, uint16_t op)
{
    /* rotcl   rn */
    int8_t n = (op>>8)&0xf;
    printw("rotcl   r%d", n);
}

void __0100nnnn00100101_dis(SH4Context_t *c, uint16_t op)
{
    /* rotcr   rn */
    int8_t n = (op>>8)&0xf;
    printw("rotcr   r%d", n);
}

void __0100nnnnmmmm1100_dis(SH4Context_t *c, uint16_t op)
{
    /* shad    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("shad    r%d,r%d", m, n);
}

void __0100nnnn00100000_dis(SH4Context_t *c, uint16_t op)
{
    /* shal    rn */
    int8_t n = (op>>8)&0xf;
    printw("shal    r%d", n);
}

void __0100nnnn00100001_dis(SH4Context_t *c, uint16_t op)
{
    /* shar    rn */
    int8_t n = (op>>8)&0xf;
    printw("shar    r%d", n);
}

void __0100nnnnmmmm1101_dis(SH4Context_t *c, uint16_t op)
{
    /* shld    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("shld    r%d,r%d", m, n);
}

void __0100nnnn00000000_dis(SH4Context_t *c, uint16_t op)
{
    /* shll    rn */
    int8_t n = (op>>8)&0xf;
    printw("shll    r%d", n);
}

void __0100nnnn00000001_dis(SH4Context_t *c, uint16_t op)
{
    /* shlr    rn */
    int8_t n = (op>>8)&0xf;
    printw("shlr    r%d", n);
}

void __0100nnnn00001000_dis(SH4Context_t *c, uint16_t op)
{
    /* shll2   rn */
    int8_t n = (op>>8)&0xf;
    printw("shll2   r%d", n);
}

void __0100nnnn00001001_dis(SH4Context_t *c, uint16_t op)
{
    /* shlr2   rn */
    int8_t n = (op>>8)&0xf;
    printw("shlr2   r%d", n);
}

void __0100nnnn00011000_dis(SH4Context_t *c, uint16_t op)
{
    /* shll8   rn */
    int8_t n = (op>>8)&0xf;
    printw("shll8   r%d", n);
}

void __0100nnnn00011001_dis(SH4Context_t *c, uint16_t op)
{
    /* shlr8   rn */
    int8_t n = (op>>8)&0xf;
    printw("shlr8   r%d", n);
}

void __0100nnnn00101000_dis(SH4Context_t *c, uint16_t op)
{
    /* shll16  rn */
    int8_t n = (op>>8)&0xf;
    printw("shll16  r%d", n);
}

void __0100nnnn00101001_dis(SH4Context_t *c, uint16_t op)
{
    /* shlr16  rn */
    int8_t n = (op>>8)&0xf;
    printw("shlr16  r%d", n);
}

void __10001011dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* bf      d */
    int8_t d = op&0xff;
    printw("bf      %d", d);
}

void __10001111dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* bf/s    d */
    int8_t d = op&0xff;
    printw("bf/s    %d", d);
}

void __10001001dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* bt      d */
    int8_t d = op&0xff;
    printw("bt      %d", d);
}

void __10001101dddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* bt/s    d */
    int8_t d = op&0xff;
    printw("bt/s    %d", d);
}

void __1010dddddddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* bra     d */
    int16_t d = op&0xfff;
    if (op&0x800) {
        d |= 0xF000;
    }
    printw("bra     %d", d);
}

void __0000nnnn00100011_dis(SH4Context_t *c, uint16_t op)
{
    /* braf    rn */
    int8_t n = (op>>8)&0xf;
    printw("braf    r%d", n);
}

void __1011dddddddddddd_dis(SH4Context_t *c, uint16_t op)
{
    /* bsr     d */
    int16_t d = op&0xfff;
    if (op&0x800) {
        d |= 0xF000;
    }
    printw("bsr     %d", d);
}

void __0000nnnn00000011_dis(SH4Context_t *c, uint16_t op)
{
    /* bsrf    rn */
    int8_t n = (op>>8)&0xf;
    printw("bsrf    r%d", n);
}

void __0100nnnn00101011_dis(SH4Context_t *c, uint16_t op)
{
    /* jmp     @rn */
    int8_t n = (op>>8)&0xf;
    printw("jmp     @r%d", n);
}

void __0100nnnn00001011_dis(SH4Context_t *c, uint16_t op)
{
    /* jsr     @rn */
    int8_t n = (op>>8)&0xf;
    printw("jsr     @r%d", n);
}

void __0000000000001011_dis(SH4Context_t *c, uint16_t op)
{
    /* rts */
    printw("rts");
}

void __0000000000101000_dis(SH4Context_t *c, uint16_t op)
{
    /* clrmac */
    printw("clrmac");
}

void __0000000001001000_dis(SH4Context_t *c, uint16_t op)
{
    /* clrs */
    printw("clrs");
}

void __0000000000001000_dis(SH4Context_t *c, uint16_t op)
{
    /* clrt */
    printw("clrt");
}

void __0100mmmm00001110_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,sr */
    int8_t m = (op>>8)&0xf;
    printw("ldc     r%d,sr", m);
}

void __0100mmmm00011110_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,gbr */
    int8_t m = (op>>8)&0xf;
    printw("ldc     r%d,gbr", m);
}

void __0100mmmm00101110_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,vbr */
    int8_t m = (op>>8)&0xf;
    printw("ldc     r%d,vbr", m);
}

void __0100mmmm00111110_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,ssr */
    int8_t m = (op>>8)&0xf;
    printw("ldc     r%d,ssr", m);
}

void __0100mmmm01001110_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,spc */
    int8_t m = (op>>8)&0xf;
    printw("ldc     r%d,spc", m);
}

void __0100mmmm11111010_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,dbr */
    int8_t m = (op>>8)&0xf;
    printw("ldc     r%d,dbr", m);
}

void __0100mmmm1nnn1110_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,rn_bank */
    int8_t m = (op>>8)&0xf;
    int8_t n = (op>>4)&0x7;
    printw("ldc     r%d,r%d_bank", m, n);
}

void __0100mmmm00000111_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,sr */
    int8_t m = (op>>8)&0xf;
    printw("ldc.l   @r%d+,sr", m);
}

void __0100mmmm00010111_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,gbr */
    int8_t m = (op>>8)&0xf;
    printw("ldc.l   @r%d+,gbr", m);
}

void __0100mmmm00100111_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,vbr */
    int8_t m = (op>>8)&0xf;
    printw("ldc.l   @r%d+,vbr", m);
}

void __0100mmmm00110111_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,ssr */
    int8_t m = (op>>8)&0xf;
    printw("ldc.l   @r%d+,ssr", m);
}

void __0100mmmm01000111_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,spc */
    int8_t m = (op>>8)&0xf;
    printw("ldc.l   @r%d+,spc", m);
}

void __0100mmmm11110110_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,dbr */
    int8_t m = (op>>8)&0xf;
    printw("ldc.l   @r%d+,dbr", m);
}

void __0100mmmm1nnn0111_dis(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,rn_bank */
    int8_t m = (op>>8)&0xf;
    int8_t n = (op>>4)&0x7;
    printw("ldc.l   @r%d+,r%d_bank", m, n);
}

void __0100mmmm00001010_dis(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,mach */
    int8_t m = (op>>8)&0xf;
    printw("lds     r%d,mach", m);
}

void __0100mmmm00011010_dis(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,macl */
    int8_t m = (op>>8)&0xf;
    printw("lds     r%d,macl", m);
}

void __0100mmmm00101010_dis(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,pr */
    int8_t m = (op>>8)&0xf;
    printw("lds     r%d,pr", m);
}

void __0100mmmm00000110_dis(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,mach */
    int8_t m = (op>>8)&0xf;
    printw("lds.l   @r%d+,mach", m);
}

void __0100mmmm00010110_dis(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,macl */
    int8_t m = (op>>8)&0xf;
    printw("lds.l   @r%d+,macl", m);
}

void __0100mmmm00100110_dis(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,pr */
    int8_t m = (op>>8)&0xf;
    printw("lds.l   @r%d+,pr", m);
}

void __0000000000111000_dis(SH4Context_t *c, uint16_t op)
{
    /* ldtlb */
    printw("ldtlb");
}

void __0000nnnn11000011_dis(SH4Context_t *c, uint16_t op)
{
    /* movca.l r0,@rn */
    int8_t n = (op>>8)&0xf;
    printw("movca.l r0,@r%d", n);
}

void __0000000000001001_dis(SH4Context_t *c, uint16_t op)
{
    /* nop */
    printw("nop");
}

void __0000nnnn10010011_dis(SH4Context_t *c, uint16_t op)
{
    /* ocbi    @rn */
    int8_t n = (op>>8)&0xf;
    printw("ocbi    @r%d", n);
}

void __0000nnnn10100011_dis(SH4Context_t *c, uint16_t op)
{
    /* ocbp    @rn */
    int8_t n = (op>>8)&0xf;
    printw("ocbp    @r%d", n);
}

void __0000nnnn10110011_dis(SH4Context_t *c, uint16_t op)
{
    /* ocbwb   @rn */
    int8_t n = (op>>8)&0xf;
    printw("ocbwb   @r%d", n);
}

void __0000nnnn10000011_dis(SH4Context_t *c, uint16_t op)
{
    /* pref    @rn */
    int8_t n = (op>>8)&0xf;
    printw("pref    @r%d", n);
}

void __0000000000101011_dis(SH4Context_t *c, uint16_t op)
{
    /* rte */
    printw("rte");
}

void __0000000001011000_dis(SH4Context_t *c, uint16_t op)
{
    /* sets */
    printw("sets");
}

void __0000000000011000_dis(SH4Context_t *c, uint16_t op)
{
    /* sett */
    printw("sett");
}

void __0000000000011011_dis(SH4Context_t *c, uint16_t op)
{
    /* sleep */
    printw("sleep");
}

void __0000nnnn00000010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc     sr,rn */
    int8_t n = (op>>8)&0xf;
    printw("stc     sr,r%d", n);
}

void __0000nnnn00010010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc     gbr,rn */
    int8_t n = (op>>8)&0xf;
    printw("stc     gbr,r%d", n);
}

void __0000nnnn00100010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc     vbr,rn */
    int8_t n = (op>>8)&0xf;
    printw("stc     vbr,r%d", n);
}

void __0000nnnn00110010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc     ssr,rn */
    int8_t n = (op>>8)&0xf;
    printw("stc     ssr,r%d", n);
}

void __0000nnnn01000010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc     spc,rn */
    int8_t n = (op>>8)&0xf;
    printw("stc     spc,r%d", n);
}

void __0000nnnn00111010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc     sgr,rn */
    int8_t n = (op>>8)&0xf;
    printw("stc     sgr,r%d", n);
}

void __0000nnnn11111010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc     dbr,rn */
    int8_t n = (op>>8)&0xf;
    printw("stc     dbr,r%d", n);
}

void __0000nnnn1mmm0010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc     rm_bank,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0x7;
    printw("stc     r%d_bank,r%d", m, n);
}

void __0100nnnn00000011_dis(SH4Context_t *c, uint16_t op)
{
    /* stc.l   sr,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("stc.l   sr,@-r%d", n);
}

void __0100nnnn00010011_dis(SH4Context_t *c, uint16_t op)
{
    /* stc.l   gbr,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("stc.l   gbr,@-r%d", n);
}

void __0100nnnn00100011_dis(SH4Context_t *c, uint16_t op)
{
    /* stc.l   vbr,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("stc.l   vbr,@-r%d", n);
}

void __0100nnnn00110011_dis(SH4Context_t *c, uint16_t op)
{
    /* stc.l   ssr,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("stc.l   ssr,@-r%d", n);
}

void __0100nnnn01000011_dis(SH4Context_t *c, uint16_t op)
{
    /* stc.l   spc,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("stc.l   spc,@-r%d", n);
}

void __0100nnnn00110010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc.l   sgr,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("stc.l   sgr,@-r%d", n);
}

void __0100nnnn11110010_dis(SH4Context_t *c, uint16_t op)
{
    /* stc.l   dbr,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("stc.l   dbr,@-r%d", n);
}

void __0100nnnn1mmm0011_dis(SH4Context_t *c, uint16_t op)
{
    /* stc.l   rm_bank,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0x7;
    printw("stc.l   r%d_bank,@-r%d", m, n);
}

void __0000nnnn00001010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts     mach,rn */
    int8_t n = (op>>8)&0xf;
    printw("sts     mach,r%d", n);
}

void __0000nnnn00011010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts     macl,rn */
    int8_t n = (op>>8)&0xf;
    printw("sts     macl,r%d", n);
}

void __0000nnnn00101010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts   pr,rn */
    int8_t n = (op>>8)&0xf;
    printw("sts   pr,r%d", n);
}

void __0100nnnn00000010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts.l   mach,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("sts.l   mach,@-r%d", n);
}

void __0100nnnn00010010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts.l   macl,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("sts.l   macl,@-r%d", n);
}

void __0100nnnn00100010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts.l   pr,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("sts.l   pr,@-r%d", n);
}

void __11000011iiiiiiii_dis(SH4Context_t *c, uint16_t op)
{
    /* trapa   #i */
    int8_t i = op&0xff;
    printw("trapa   #%d", i);
}

void __1111nnnn10001101_dis(SH4Context_t *c, uint16_t op)
{
    /* fldi0   frn */
    int8_t n = (op>>8)&0xf;
    printw("fldi0   fr%d", n);
}

void __1111nnnn10011101_dis(SH4Context_t *c, uint16_t op)
{
    /* fldi1   frn */
    int8_t n = (op>>8)&0xf;
    printw("fldi1   fr%d", n);
}

void __1111nnnnmmmm1100_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fmov    fr%d,fr%d", m, n);
}

void __1111nnnnmmmm1000_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  @rm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fmov.s  @r%d,fr%d", m, n);
}

void __1111nnnnmmmm0110_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  @(r0,rm),frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fmov.s  @(r0,r%d),fr%d", m, n);
}

void __1111nnnnmmmm1001_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  @rm+,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fmov.s  @r%d+,fr%d", m, n);
}

void __1111nnnnmmmm1010_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  frm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fmov.s  fr%d,@r%d", m, n);
}

void __1111nnnnmmmm1011_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  frm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fmov.s  fr%d,@-r%d", m, n);
}

void __1111nnnnmmmm0111_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  frm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fmov.s  fr%d,@(r0,r%d)", m, n);
}

void __1111nnn0mmm01100_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fmov    dr%d,dr%d", m, n);
}

void __1111nnn0mmmm1000_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    @rm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    printw("fmov    @r%d,dr%d", m, n);
}

void __1111nnn0mmmm0110_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    @(r0,rm),drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    printw("fmov    @(r0,r%d),dr%d", m, n);
}

void __1111nnn0mmmm1001_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    @rm+,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    printw("fmov    @r%d+,dr%d", m, n);
}

void __1111nnnnmmm01010_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    printw("fmov    dr%d,@r%d", m, n);
}

void __1111nnnnmmm01011_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    printw("fmov    dr%d,@-r%d", m, n);
}

void __1111nnnnmmm00111_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    printw("fmov    dr%d,@(r0,r%d)", m, n);
}

void __1111mmmm00011101_dis(SH4Context_t *c, uint16_t op)
{
    /* flds    frm,fpul */
    int8_t m = (op>>8)&0xf;
    printw("flds    fr%d,fpul", m);
}

void __1111nnnn00001101_dis(SH4Context_t *c, uint16_t op)
{
    /* fsts    fpul,frn */
    int8_t n = (op>>8)&0xf;
    printw("fsts    fpul,fr%d", n);
}

void __1111nnnn01011101_dis(SH4Context_t *c, uint16_t op)
{
    /* fabs    frn */
    int8_t n = (op>>8)&0xf;
    printw("fabs    fr%d", n);
}

void __1111nnnnmmmm0000_dis(SH4Context_t *c, uint16_t op)
{
    /* fadd    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fadd    fr%d,fr%d", m, n);
}

void __1111nnnnmmmm0100_dis(SH4Context_t *c, uint16_t op)
{
    /* fcmp/eq frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fcmp/eq fr%d,fr%d", m, n);
}

void __1111nnnnmmmm0101_dis(SH4Context_t *c, uint16_t op)
{
    /* fcmp/gt frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fcmp/gt fr%d,fr%d", m, n);
}

void __1111nnnnmmmm0011_dis(SH4Context_t *c, uint16_t op)
{
    /* fdiv    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fdiv    fr%d,fr%d", m, n);
}

void __1111nnnn00101101_dis(SH4Context_t *c, uint16_t op)
{
    /* float   fpul,frn */
    int8_t n = (op>>8)&0xf;
    printw("float   fpul,fr%d", n);
}

void __1111nnnnmmmm1110_dis(SH4Context_t *c, uint16_t op)
{
    /* fmac    fr0,frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fmac    fr0,fr%d,fr%d", m, n);
}

void __1111nnnnmmmm0010_dis(SH4Context_t *c, uint16_t op)
{
    /* fmul    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fmul    fr%d,fr%d", m, n);
}

void __1111nnnn01001101_dis(SH4Context_t *c, uint16_t op)
{
    /* fneg    frn */
    int8_t n = (op>>8)&0xf;
    printw("fneg    fr%d", n);
}

void __1111nnnn01101101_dis(SH4Context_t *c, uint16_t op)
{
    /* fsqrt   frn */
    int8_t n = (op>>8)&0xf;
    printw("fsqrt   fr%d", n);
}

void __1111nnnnmmmm0001_dis(SH4Context_t *c, uint16_t op)
{
    /* fsub    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    printw("fsub    fr%d,fr%d", m, n);
}

void __1111mmmm00111101_dis(SH4Context_t *c, uint16_t op)
{
    /* ftrc    frm,fpul */
    int8_t m = (op>>8)&0xf;
    printw("ftrc    fr%d,fpul", m);
}

void __1111nnn001011101_dis(SH4Context_t *c, uint16_t op)
{
    /* fabs    drn */
    int8_t n = (op>>9)&0x7;
    printw("fabs    dr%d", n);
}

void __1111nnn0mmm00000_dis(SH4Context_t *c, uint16_t op)
{
    /* fadd    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fadd    dr%d,dr%d", m, n);
}

void __1111nnn0mmm00100_dis(SH4Context_t *c, uint16_t op)
{
    /* fcmp/eq drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fcmp/eq dr%d,dr%d", m, n);
}

void __1111nnn0mmm00101_dis(SH4Context_t *c, uint16_t op)
{
    /* fcmp/gt drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fcmp/gt dr%d,dr%d", m, n);
}

void __1111nnn0mmm00011_dis(SH4Context_t *c, uint16_t op)
{
    /* fdiv    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fdiv    dr%d,dr%d", m, n);
}

void __1111mmm010111101_dis(SH4Context_t *c, uint16_t op)
{
    /* fcnvds  drm,fpul */
    int8_t m = (op>>9)&0x7;
    printw("fcnvds  dr%d,fpul", m);
}

void __1111nnn010101101_dis(SH4Context_t *c, uint16_t op)
{
    /* fcnvsd  fpul,drn */
    int8_t n = (op>>9)&0x7;
    printw("fcnvsd  fpul,dr%d", n);
}

void __1111nnn000101101_dis(SH4Context_t *c, uint16_t op)
{
    /* float   fpul,drn */
    int8_t n = (op>>9)&0x7;
    printw("float   fpul,dr%d", n);
}

void __1111nnn0mmm00010_dis(SH4Context_t *c, uint16_t op)
{
    /* fmul    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fmul    dr%d,dr%d", m, n);
}

void __1111nnn001001101_dis(SH4Context_t *c, uint16_t op)
{
    /* fneg    drn */
    int8_t n = (op>>9)&0x7;
    printw("fneg    dr%d", n);
}

void __1111nnn001101101_dis(SH4Context_t *c, uint16_t op)
{
    /* fsqrt   drn */
    int8_t n = (op>>9)&0x7;
    printw("fsqrt   dr%d", n);
}

void __1111nnn0mmm00001_dis(SH4Context_t *c, uint16_t op)
{
    /* fsub    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fsub    dr%d,dr%d", m, n);
}

void __1111mmm000111101_dis(SH4Context_t *c, uint16_t op)
{
    /* ftrc    drm,fpul */
    int8_t m = (op>>9)&0x7;
    printw("ftrc    dr%d,fpul", m);
}

void __0100mmmm01101010_dis(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,fpscr */
    int8_t m = (op>>8)&0xf;
    printw("lds     r%d,fpscr", m);
}

void __0100mmmm01011010_dis(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,fpul */
    int8_t m = (op>>8)&0xf;
    printw("lds     r%d,fpul", m);
}

void __0100mmmm01100110_dis(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,fpscr */
    int8_t m = (op>>8)&0xf;
    printw("lds.l   @r%d+,fpscr", m);
}

void __0100mmmm01010110_dis(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,fpul */
    int8_t m = (op>>8)&0xf;
    printw("lds.l   @r%d+,fpul", m);
}

void __0000nnnn01101010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts     fpscr,rn */
    int8_t n = (op>>8)&0xf;
    printw("sts     fpscr,r%d", n);
}

void __0000nnnn01011010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts     fpul,rn */
    int8_t n = (op>>8)&0xf;
    printw("sts     fpul,r%d", n);
}

void __0100nnnn01100010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts.l   fpscr,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("sts.l   fpscr,@-r%d", n);
}

void __0100nnnn01010010_dis(SH4Context_t *c, uint16_t op)
{
    /* sts.l   fpul,@-rn */
    int8_t n = (op>>8)&0xf;
    printw("sts.l   fpul,@-r%d", n);
}

void __1111nnn1mmm01100_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,xdn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fmov    dr%d,xd%d", m, n);
}

void __1111nnn0mmm11100_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fmov    xd%d,dr%d", m, n);
}

void __1111nnn1mmm11100_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,xdn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    printw("fmov    xd%d,xd%d", m, n);
}

void __1111nnn1mmmm1000_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    @rm,xdn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    printw("fmov    @r%d,xd%d", m, n);
}

void __1111nnn1mmmm1001_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    @rm+,xdn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    printw("fmov    @r%d+,xd%d", m, n);
}

void __1111nnn1mmmm0110_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    @(r0,rm),drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    printw("fmov    @(r0,r%d),dr%d", m, n);
}

void __1111nnnnmmm11010_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    printw("fmov    xd%d,@r%d", m, n);
}

void __1111nnnnmmm11011_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    printw("fmov    xd%d,@-r%d", m, n);
}

void __1111nnnnmmm10111_dis(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    printw("fmov    xd%d,@(r0,r%d)", m, n);
}

void __1111nnmm11101101_dis(SH4Context_t *c, uint16_t op)
{
    /* fipr    fvm,fvn */
    int8_t n = (op>>10)&0x3;
    int8_t m = (op>>8)&0x3;
    printw("fipr    fv%d,fv%d", m, n);
}

void __1111nn0111111101_dis(SH4Context_t *c, uint16_t op)
{
    /* ftrv    xmtrx,fvn */
    int8_t n = (op>>10)&0x3;
    printw("ftrv    xmtrx,fv%d", n);
}

void __1111101111111101_dis(SH4Context_t *c, uint16_t op)
{
    /* frchg */
    printw("frchg");
}

void __1111001111111101_dis(SH4Context_t *c, uint16_t op)
{
    /* fschg */
    printw("fschg");
}

