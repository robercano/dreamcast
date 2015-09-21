/*********************************************
 * sh4opcodeemu.c
 *
 * Contains the implementation of the processing functions for the emulator
 *
 * @author Roberto Cano <roberto dot cano at google mail>
 *
 *********************************************/
#include "sh4.h"
#include "sh4opcode.h"
#include <stdlib.h>

void __0000000000000000(SH4Context_t *c, uint16_t op)
{
    /* EXCEPTION */
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] EXCEPTION --> __0000000000000000\n");
    exit(1);
}

void __1110nnnniiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* mov     #i,rn */
    int8_t n = (op>>8)&0xf;
    int8_t i = op&0xff;
    _R(n) = i;
}

void __1001nnnndddddddd(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @(d,pc),rn */
    int8_t n = (op>>8)&0xf;
    int8_t d = op&0xff;

    _R(n) = SH4_MMU_ReadS16(c, d*2 + c->regs.PC + 4);
}

void __1101nnnndddddddd(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @(d,pc),rn */
    int8_t n = (op>>8)&0xf;
    int8_t d = op&0xff;
    _R(n) = SH4_MMU_ReadU32(c, d*4 + (c->regs.PC&0xfffffffc) + 4);
}

void __0110nnnnmmmm0011(SH4Context_t *c, uint16_t op)
{
    /* mov     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = _R(m);
}

void __0010nnnnmmmm0000(SH4Context_t *c, uint16_t op)
{
    /* mov.b   rm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_MMU_WriteU8(c, (uint8_t)_R(m), _R(n));
}

void __0010nnnnmmmm0001(SH4Context_t *c, uint16_t op)
{
    /* mov.w   rm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.w   rm,@rn --> __0010nnnnmmmm0001\n");
    exit(1);
}

void __0010nnnnmmmm0010(SH4Context_t *c, uint16_t op)
{
    /* mov.l   rm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_MMU_WriteU32(c, _R(m), _R(n));
}

void __0110nnnnmmmm0000(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = SH4_MMU_ReadS8(c, _R(m));
}

void __0110nnnnmmmm0001(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.w   @rm,rn --> __0110nnnnmmmm0001\n");
    exit(1);
}

void __0110nnnnmmmm0010(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = SH4_MMU_ReadU32(c, _R(m));
}

void __0010nnnnmmmm0100(SH4Context_t *c, uint16_t op)
{
    /* mov.b   rm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.b   rm,@-rn --> __0010nnnnmmmm0100\n");
    exit(1);
}

void __0010nnnnmmmm0101(SH4Context_t *c, uint16_t op)
{
    /* mov.w   rm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.w   rm,@-rn --> __0010nnnnmmmm0101\n");
    exit(1);
}

void __0010nnnnmmmm0110(SH4Context_t *c, uint16_t op)
{
    /* mov.l   rm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;

    _R(n) -= 4;
    SH4_MMU_WriteU32(c, _R(m), _R(n));
}

void __0110nnnnmmmm0100(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @rm+,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = SH4_MMU_ReadS8(c, _R(m));
    _R(m)++;
}

void __0110nnnnmmmm0101(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @rm+,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.w   @rm+,rn --> __0110nnnnmmmm0101\n");
    exit(1);
}

void __0110nnnnmmmm0110(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @rm+,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = SH4_MMU_ReadU32(c, _R(m));
    _R(m) += 4;
}

void __10000000nnnndddd(SH4Context_t *c, uint16_t op)
{
    /* mov.b   r0,@(d,rn) */
    int8_t n = (op>>4)&0xf;
    int8_t d = op&0xf;
    SH4_MMU_WriteU8(c, _R(0), _R(n)+d);
}

void __10000001nnnndddd(SH4Context_t *c, uint16_t op)
{
    /* mov.w   r0,@(d,rn) */
    int8_t n = (op>>4)&0xf;
    int8_t d = op&0xf;
    SH4_MMU_WriteU16(c, (uint16_t)_R(0), _R(n)+d*2);
}

void __0001nnnnmmmmdddd(SH4Context_t *c, uint16_t op)
{
    /* mov.l   rm,@(d,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    int8_t d = op&0xf;
    SH4_MMU_WriteU32(c, _R(m), d*4+_R(n));
}

void __10000100mmmmdddd(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @(d,rm),r0 */
    int8_t m = (op>>4)&0xf;
    int8_t d = op&0xf;
    _R(0) = SH4_MMU_ReadS8(c, _R(m)+d);
}

void __10000101mmmmdddd(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @(d,rm),r0 */
    int8_t m = (op>>4)&0xf;
    int8_t d = op&0xf;
    _R(0) = SH4_MMU_ReadS16(c, _R(m)+d*2);
}

void __0101nnnnmmmmdddd(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @(d,rm),rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    int8_t d = op&0xf;
    _R(n) = SH4_MMU_ReadU32(c, d*4 + _R(m));
}

void __0000nnnnmmmm0100(SH4Context_t *c, uint16_t op)
{
    /* mov.b   rm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.b   rm,@(r0,rn) --> __0000nnnnmmmm0100\n");
    exit(1);
}

void __0000nnnnmmmm0101(SH4Context_t *c, uint16_t op)
{
    /* mov.w   rm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.w   rm,@(r0,rn) --> __0000nnnnmmmm0101\n");
    exit(1);
}

void __0000nnnnmmmm0110(SH4Context_t *c, uint16_t op)
{
    /* mov.l   rm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;

    SH4_MMU_WriteU32(c, _R(m), _R(0) + _R(m));
}

void __0000nnnnmmmm1100(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @(r0,rm),rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.b   @(r0,rm),rn --> __0000nnnnmmmm1100\n");
    exit(1);
}

void __0000nnnnmmmm1101(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @(r0,rm),rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = SH4_MMU_ReadS16(c, _R(0)+_R(m));
}

void __0000nnnnmmmm1110(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @(r0,rm),rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = SH4_MMU_ReadU32(c, _R(0) + _R(m));
}

void __11000000dddddddd(SH4Context_t *c, uint16_t op)
{
    /* mov.b   r0,@(d,gbr) */
    int8_t d = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.b   r0,@(d,gbr) --> __11000000dddddddd\n");
    exit(1);
}

void __11000001dddddddd(SH4Context_t *c, uint16_t op)
{
    /* mov.w   r0,@(d,gbr) */
    int8_t d = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.w   r0,@(d,gbr) --> __11000001dddddddd\n");
    exit(1);
}

void __11000010dddddddd(SH4Context_t *c, uint16_t op)
{
    /* mov.l   r0,@(d,gbr) */
    int8_t d = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.l   r0,@(d,gbr) --> __11000010dddddddd\n");
    exit(1);
}

void __11000100dddddddd(SH4Context_t *c, uint16_t op)
{
    /* mov.b   @(d,gbr),r0 */
    int8_t d = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.b   @(d,gbr),r0 --> __11000100dddddddd\n");
    exit(1);
}

void __11000101dddddddd(SH4Context_t *c, uint16_t op)
{
    /* mov.w   @(d,gbr),r0 */
    int8_t d = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.w   @(d,gbr),r0 --> __11000101dddddddd\n");
    exit(1);
}

void __11000110dddddddd(SH4Context_t *c, uint16_t op)
{
    /* mov.l   @(d,gbr),r0 */
    int8_t d = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mov.l   @(d,gbr),r0 --> __11000110dddddddd\n");
    exit(1);
}

void __11000111dddddddd(SH4Context_t *c, uint16_t op)
{
    /* mova    @(d,pc),r0 */
    int8_t d = op&0xff;
    _R(0) = (d<<2) + (c->regs.PC&0xFFFFFFFC) + 4;
}

void __0000nnnn00101001(SH4Context_t *c, uint16_t op)
{
    /* movt    rn */
    int8_t n = (op>>8)&0xf;
    _R(n) = c->regs.SR.T;
}

void __0110nnnnmmmm1000(SH4Context_t *c, uint16_t op)
{
    /* swap.b  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] swap.b  rm,rn --> __0110nnnnmmmm1000\n");
    exit(1);
}

void __0110nnnnmmmm1001(SH4Context_t *c, uint16_t op)
{
    /* swap.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = (_R(m)<<16) | (_R(m)>>16);
}

void __0010nnnnmmmm1101(SH4Context_t *c, uint16_t op)
{
    /* xtrct   rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = (_R(m)<<16) | (_R(n)>>16);
}

void __0011nnnnmmmm1100(SH4Context_t *c, uint16_t op)
{
    /* add     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) += _R(m);
}

void __0111nnnniiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* add     #i,rn */
    int8_t n = (op>>8)&0xf;
    int8_t i = op&0xff;
    _R(n) += i;
}

void __0011nnnnmmmm1110(SH4Context_t *c, uint16_t op)
{
    /* addc    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    uint64_t sum = _R(n) + _R(m) + c->regs.SR.T;
    _R(n) = sum;
    c->regs.SR.T = (sum > 0x100000000LL);
}

void __0011nnnnmmmm1111(SH4Context_t *c, uint16_t op)
{
    /* addv    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] addv    rm,rn --> __0011nnnnmmmm1111\n");
    exit(1);
}

void __10001000iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* cmp/eq  #i,r0 */
    int8_t i = op&0xff;
    c->regs.SR.T = _R(0)==i;
}

void __0011nnnnmmmm0000(SH4Context_t *c, uint16_t op)
{
    /* cmp/eq  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    c->regs.SR.T = _R(n)==_R(m);
}

void __0011nnnnmmmm0010(SH4Context_t *c, uint16_t op)
{
    /* cmp/hs  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    c->regs.SR.T = _R(n)>=_R(m);
}

void __0011nnnnmmmm0011(SH4Context_t *c, uint16_t op)
{
    /* cmp/ge  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    c->regs.SR.T = (int32_t)_R(n) >= (int32_t)_R(m);
}

void __0011nnnnmmmm0110(SH4Context_t *c, uint16_t op)
{
    /* cmp/hi  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    c->regs.SR.T = _R(n)>_R(m);
}

void __0011nnnnmmmm0111(SH4Context_t *c, uint16_t op)
{
    /* cmp/gt  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    c->regs.SR.T = (int32_t)_R(n) > (int32_t)_R(m);
}

void __0100nnnn00010001(SH4Context_t *c, uint16_t op)
{
    /* cmp/pz  rn */
    int8_t n = (op>>8)&0xf;
    c->regs.SR.T = ((int32_t)_R(n)) >= 0;
}

void __0100nnnn00010101(SH4Context_t *c, uint16_t op)
{
    /* cmp/pl  rn */
    int8_t n = (op>>8)&0xf;
    c->regs.SR.T = ((int32_t)_R(n)) > 0;
}

void __0010nnnnmmmm1100(SH4Context_t *c, uint16_t op)
{
    /* cmp/str rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;

    uint32_t tmp = _R(n)^_R(m);
    c->regs.SR.T = !(((uint8_t*)&tmp)[0] &&
                     ((uint8_t*)&tmp)[1] &&
                     ((uint8_t*)&tmp)[2] &&
                     ((uint8_t*)&tmp)[3]);
}

void __0011nnnnmmmm0100(SH4Context_t *c, uint16_t op)
{
    /* div1    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;

    /* Code copied from reicast....too lazy to write it myself */
    uint32_t tmp0, tmp2;
    uint8_t old_q, tmp1;

    old_q = c->regs.SR.Q;
    c->regs.SR.Q = (uint8_t)((0x80000000 & _R(n)) !=0);

    _R(n) <<= 1;
    _R(n) |= (uint32_t)c->regs.SR.T;

    tmp0 = _R(n);    // this need only be done once here ..
    tmp2 = _R(m);

    if( 0 == old_q ) {
        if( 0 == c->regs.SR.M ) {
            _R(n) -= tmp2;
            tmp1 = (_R(n)>tmp0);
            c->regs.SR.Q = (c->regs.SR.Q==0) ? tmp1 : (uint8_t)(tmp1==0) ;
        } else {
            _R(n) += tmp2;
            tmp1 =(_R(n)<tmp0);
            c->regs.SR.Q = (c->regs.SR.Q==0) ? (uint8_t)(tmp1==0) : tmp1;
        }
    } else {
        if( 0 == c->regs.SR.M ) {
            _R(n) += tmp2;
            tmp1 = (_R(n)<tmp0);
            c->regs.SR.Q = (c->regs.SR.Q==0) ? tmp1 : (uint8_t)(tmp1==0) ;
        } else {
            _R(n) -= tmp2;
            tmp1 = (_R(n)>tmp0);
            c->regs.SR.Q = (c->regs.SR.Q==0) ? (uint8_t)(tmp1==0) : tmp1 ;
        }
    }
    c->regs.SR.T = (c->regs.SR.Q==c->regs.SR.M);
}

void __0010nnnnmmmm0111(SH4Context_t *c, uint16_t op)
{
    /* div0s   rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] div0s   rm,rn --> __0010nnnnmmmm0111\n");
    exit(1);
}

void __0000000000011001(SH4Context_t *c, uint16_t op)
{
    /* div0u */
    c->regs.SR.T = 0;
    c->regs.SR.M = 0;
    c->regs.SR.Q = 0;
}

void __0011nnnnmmmm1101(SH4Context_t *c, uint16_t op)
{
    /* dmuls.l rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] dmuls.l rm,rn --> __0011nnnnmmmm1101\n");
    exit(1);
}

void __0011nnnnmmmm0101(SH4Context_t *c, uint16_t op)
{
    /* dmulu.l rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] dmulu.l rm,rn --> __0011nnnnmmmm0101\n");
    exit(1);
}

void __0100nnnn00010000(SH4Context_t *c, uint16_t op)
{
    /* dt      rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] dt      rn --> __0100nnnn00010000\n");
    exit(1);
}

void __0110nnnnmmmm1110(SH4Context_t *c, uint16_t op)
{
    /* exts.b  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = (int8_t)_R(m);
}

void __0110nnnnmmmm1111(SH4Context_t *c, uint16_t op)
{
    /* exts.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] exts.w  rm,rn --> __0110nnnnmmmm1111\n");
    exit(1);
}

void __0110nnnnmmmm1100(SH4Context_t *c, uint16_t op)
{
    /* extu.b  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = _R(m)&0x000000FF;
}

void __0110nnnnmmmm1101(SH4Context_t *c, uint16_t op)
{
    /* extu.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = _R(m)&0x0000FFFF;
}

void __0000nnnnmmmm1111(SH4Context_t *c, uint16_t op)
{
    /* mac.l   @rm+,@rn+ */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mac.l   @rm+,@rn+ --> __0000nnnnmmmm1111\n");
    exit(1);
}

void __0100nnnnmmmm1111(SH4Context_t *c, uint16_t op)
{
    /* mac.w   @rm+,@rn+ */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mac.w   @rm+,@rn+ --> __0100nnnnmmmm1111\n");
    exit(1);
}

void __0000nnnnmmmm0111(SH4Context_t *c, uint16_t op)
{
    /* mul.l   rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] mul.l   rm,rn --> __0000nnnnmmmm0111\n");
    exit(1);
}

void __0010nnnnmmmm1111(SH4Context_t *c, uint16_t op)
{
    /* muls.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] muls.w  rm,rn --> __0010nnnnmmmm1111\n");
    exit(1);
}

void __0010nnnnmmmm1110(SH4Context_t *c, uint16_t op)
{
    /* mulu.w  rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    c->regs.MACL = (uint16_t)_R(n)*(uint16_t)_R(m);
}

void __0110nnnnmmmm1011(SH4Context_t *c, uint16_t op)
{
    /* neg     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = (int32_t)0-_R(m);
}

void __0110nnnnmmmm1010(SH4Context_t *c, uint16_t op)
{
    /* negc    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    int64_t tmp = (int64_t)0 - (int64_t)_R(m) - (int64_t)c->regs.SR.T;
    c->regs.SR.T = tmp<0;
    _R(n) = (uint32_t)tmp;
}

void __0011nnnnmmmm1000(SH4Context_t *c, uint16_t op)
{
    /* sub     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;

    _R(n) -= _R(m);
}

void __0011nnnnmmmm1010(SH4Context_t *c, uint16_t op)
{
    /* subc    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    int64_t tmp = (int64_t)_R(n) - (int64_t)_R(m) - (int64_t)c->regs.SR.T;
    c->regs.SR.T = tmp<0;
    _R(n) = (uint32_t)tmp;
}

void __0011nnnnmmmm1011(SH4Context_t *c, uint16_t op)
{
    /* subv    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] subv    rm,rn --> __0011nnnnmmmm1011\n");
    exit(1);
}

void __0010nnnnmmmm1001(SH4Context_t *c, uint16_t op)
{
    /* and     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) &= _R(m);
}

void __11001001iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* and     #i,r0 */
    int8_t i = op&0xff;
    _R(0) &= i;
}

void __11001101iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* and.b   #i,@(r0,gbr) */
    int8_t i = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] and.b   #i,@(r0,gbr) --> __11001101iiiiiiii\n");
    exit(1);
}

void __0110nnnnmmmm0111(SH4Context_t *c, uint16_t op)
{
    /* not     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) = ~_R(m);
}

void __0010nnnnmmmm1011(SH4Context_t *c, uint16_t op)
{
    /* or      rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) |= _R(m);
}

void __11001011iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* or      #i,r0 */
    int8_t i = op&0xff;
    _R(0) |= i;
}

void __11001111iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* or.b    #i,@(r0,gbr) */
    int8_t i = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] or.b    #i,@(r0,gbr) --> __11001111iiiiiiii\n");
    exit(1);
}

void __0100nnnn00011011(SH4Context_t *c, uint16_t op)
{
    /* tas.b   @rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] tas.b   @rn --> __0100nnnn00011011\n");
    exit(1);
}

void __0010nnnnmmmm1000(SH4Context_t *c, uint16_t op)
{
    /* tst     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    c->regs.SR.T = _R(n)&_R(m) ? 0 : 1;
}

void __11001000iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* tst     #i,r0 */
    uint8_t i = op&0xff;
    c->regs.SR.T = !(_R(0)&i);
}

void __11001100iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* tst.b   #i,@(r0,gbr) */
    int8_t i = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] tst.b   #i,@(r0,gbr) --> __11001100iiiiiiii\n");
    exit(1);
}

void __0010nnnnmmmm1010(SH4Context_t *c, uint16_t op)
{
    /* xor     rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    _R(n) ^= _R(m);
}

void __11001010iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* xor     #i,r0 */
    int8_t i = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] xor     #i,r0 --> __11001010iiiiiiii\n");
    exit(1);
}

void __11001110iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* xor.b   #i,@(r0,gbr) */
    int8_t i = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] xor.b   #i,@(r0,gbr) --> __11001110iiiiiiii\n");
    exit(1);
}

void __0100nnnn00000100(SH4Context_t *c, uint16_t op)
{
    /* rotl    rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] rotl    rn --> __0100nnnn00000100\n");
    exit(1);
}

void __0100nnnn00000101(SH4Context_t *c, uint16_t op)
{
    /* rotr    rn */
    int8_t n = (op>>8)&0xf;
    c->regs.SR.T = _R(n)&1;
    _R(n) >>= 1;
    if (c->regs.SR.T) {
        _R(n) |= 0x80000000;
    }
}

void __0100nnnn00100100(SH4Context_t *c, uint16_t op)
{
    /* rotcl   rn */
    int8_t n = (op>>8)&0xf;
    uint8_t tmp = _R(n)>>31;
    _R(n) = (_R(n)<<1) | c->regs.SR.T;
    c->regs.SR.T = tmp;
}

void __0100nnnn00100101(SH4Context_t *c, uint16_t op)
{
    /* rotcr   rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] rotcr   rn --> __0100nnnn00100101\n");
    exit(1);
}

void __0100nnnnmmmm1100(SH4Context_t *c, uint16_t op)
{
    /* shad    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] shad    rm,rn --> __0100nnnnmmmm1100\n");
    exit(1);
}

void __0100nnnn00100000(SH4Context_t *c, uint16_t op)
{
    /* shal    rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] shal    rn --> __0100nnnn00100000\n");
    exit(1);
}

void __0100nnnn00100001(SH4Context_t *c, uint16_t op)
{
    /* shar    rn */
    int8_t n = (op>>8)&0xf;
    c->regs.SR.T = _R(n)&0x1;
    _R(n) >>= 1;
    if (_R(n)&0x4000000) {
        _R(n) |= 0x80000000;
    }
}

void __0100nnnnmmmm1101(SH4Context_t *c, uint16_t op)
{
    /* shld    rm,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] shld    rm,rn --> __0100nnnnmmmm1101\n");
    exit(1);
}

void __0100nnnn00000000(SH4Context_t *c, uint16_t op)
{
    /* shll    rn */
    int8_t n = (op>>8)&0xf;
    if (_R(n)&0x80000000) {
        c->regs.SR.T = 1;
    }
    _R(n) <<= 1;
}

void __0100nnnn00000001(SH4Context_t *c, uint16_t op)
{
    /* shlr    rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] shlr    rn --> __0100nnnn00000001\n");
    exit(1);
}

void __0100nnnn00001000(SH4Context_t *c, uint16_t op)
{
    /* shll2   rn */
    int8_t n = (op>>8)&0xf;
    _R(n) <<= 2;
}

void __0100nnnn00001001(SH4Context_t *c, uint16_t op)
{
    /* shlr2   rn */
    int8_t n = (op>>8)&0xf;
    _R(n) >>= 2;
}

void __0100nnnn00011000(SH4Context_t *c, uint16_t op)
{
    /* shll8   rn */
    int8_t n = (op>>8)&0xf;
    _R(n) <<= 8;
}

void __0100nnnn00011001(SH4Context_t *c, uint16_t op)
{
    /* shlr8   rn */
    int8_t n = (op>>8)&0xf;
    _R(n) >>= 8;
}

void __0100nnnn00101000(SH4Context_t *c, uint16_t op)
{
    /* shll16  rn */
    int8_t n = (op>>8)&0xf;
    _R(n) <<= 16;
}

void __0100nnnn00101001(SH4Context_t *c, uint16_t op)
{
    /* shlr16  rn */
    int8_t n = (op>>8)&0xf;
    _R(n) >>= 16;
}

void __10001011dddddddd(SH4Context_t *c, uint16_t op)
{
    /* bf      d */
    int8_t d = op&0xff;
    if (c->regs.SR.T == 0) {
        c->regs.NPC = c->regs.PC + d*2 + 4;
        c->regs.NNPC = c->regs.NPC + 2;
    }
}

void __10001111dddddddd(SH4Context_t *c, uint16_t op)
{
    /* bf/s    d */
    int8_t d = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] bf/s    d --> __10001111dddddddd\n");
    exit(1);
}

void __10001001dddddddd(SH4Context_t *c, uint16_t op)
{
    /* bt      d */
    int8_t d = op&0xff;
    if (c->regs.SR.T) {
        c->regs.NPC  = c->regs.PC + d*2 + 4;
        c->regs.NNPC = c->regs.NPC + 2;
    }
}

void __10001101dddddddd(SH4Context_t *c, uint16_t op)
{
    /* bt/s    d */
    int8_t d = op&0xff;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] bt/s    d --> __10001101dddddddd\n");
    exit(1);
}

void __1010dddddddddddd(SH4Context_t *c, uint16_t op)
{
    /* bra     d */
    int16_t d = op&0xfff;
    if (op&0x800) {
        d |= 0xF000;
    }
    c->regs.NNPC = d*2 + c->regs.PC + 4;
}

void __0000nnnn00100011(SH4Context_t *c, uint16_t op)
{
    /* braf    rn */
    int8_t n = (op>>8)&0xf;
    c->regs.NNPC = _R(n) + c->regs.PC + 4;
}

void __1011dddddddddddd(SH4Context_t *c, uint16_t op)
{
    /* bsr     d */
    int16_t d = op&0xfff;
    if (op&0x800) {
        d |= 0xF000;
    }
    c->regs.PR = c->regs.PC+4;
    c->regs.NNPC = d*2 + c->regs.PC + 4;
}

void __0000nnnn00000011(SH4Context_t *c, uint16_t op)
{
    /* bsrf    rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] bsrf    rn --> __0000nnnn00000011\n");
    exit(1);
}

void __0100nnnn00101011(SH4Context_t *c, uint16_t op)
{
    /* jmp     @rn */
    int8_t n = (op>>8)&0xf;
    c->regs.NNPC = _R(n);
}

#include <arpa/inet.h>
void __0100nnnn00001011(SH4Context_t *c, uint16_t op)
{
    /* jsr     @rn */
    int8_t n = (op>>8)&0xf;

    if (/*_R(n) == c->print ||*/ _R(n) == c->puts) {
        /* Manually execute next instruction before jumping to printf or puts */
        c->regs.PC    = c->regs.NPC;
        c->regs.NPC   = c->regs.NNPC;
        c->regs.NNPC += 2;

        uint16_t op = ntohs(*(uint16_t*)(c->memory+c->regs.PC));

        /* Execute the opcode */
        //if (c->debug) {
        //    SH4_LogEx(SH4_LOG_DEBUG, "%04x:        %02x %02x           ", c->regs.PC, (op>>8)&0xff, op&0xff);
        //    SH7750DisasmLUT[op](c, op);
        //}
        SH7750InterpLUT[op](c, op);

        /* Now execute printf: maximum of 3 parameters!! */
        if (c->debug) {
            SH4_Log(SH4_LOG_INFO, "Calling printf or puts");
        }
        //SH4_Log(SH4_LOG_INFO, "Calling printf or puts %s, %08x %08x %08x", c->memory+_R(4), _R(5), _R(6), _R(7));
        SH4_LogEx(SH4_LOG_INFO, (char*)(c->memory+_R(4)), _R(5), _R(6), _R(7));
    } else {
        c->regs.PR = c->regs.PC+4;
        c->regs.NNPC = _R(n);
    }
}

void __0000000000001011(SH4Context_t *c, uint16_t op)
{
    /* rts */
    c->regs.NNPC = c->regs.PR;
}

void __0000000000101000(SH4Context_t *c, uint16_t op)
{
    /* clrmac */
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] clrmac --> __0000000000101000\n");
    exit(1);
}

void __0000000001001000(SH4Context_t *c, uint16_t op)
{
    /* clrs */
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] clrs --> __0000000001001000\n");
    exit(1);
}

void __0000000000001000(SH4Context_t *c, uint16_t op)
{
    /* clrt */
    c->regs.SR.T = 0;
}

void __0100mmmm00001110(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,sr */
    int8_t m = (op>>8)&0xf;
    _SRPUT(_R(m));
    SH4_Log(SH4_LOG_ERROR, "------------> %d, %x\n", m, _R(m)>>12);
}

void __0100mmmm00011110(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,gbr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc     rm,gbr --> __0100mmmm00011110\n");
    exit(1);
}

void __0100mmmm00101110(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,vbr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc     rm,vbr --> __0100mmmm00101110\n");
    exit(1);
}

void __0100mmmm00111110(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,ssr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc     rm,ssr --> __0100mmmm00111110\n");
    exit(1);
}

void __0100mmmm01001110(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,spc */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc     rm,spc --> __0100mmmm01001110\n");
    exit(1);
}

void __0100mmmm11111010(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,dbr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc     rm,dbr --> __0100mmmm11111010\n");
    exit(1);
}

void __0100mmmm1nnn1110(SH4Context_t *c, uint16_t op)
{
    /* ldc     rm,rn_bank */
    int8_t m = (op>>8)&0xf;
    int8_t n = (op>>4)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc     rm,rn_bank --> __0100mmmm1nnn1110\n");
    exit(1);
}

void __0100mmmm00000111(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,sr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc.l   @rm+,sr --> __0100mmmm00000111\n");
    exit(1);
}

void __0100mmmm00010111(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,gbr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc.l   @rm+,gbr --> __0100mmmm00010111\n");
    exit(1);
}

void __0100mmmm00100111(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,vbr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc.l   @rm+,vbr --> __0100mmmm00100111\n");
    exit(1);
}

void __0100mmmm00110111(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,ssr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc.l   @rm+,ssr --> __0100mmmm00110111\n");
    exit(1);
}

void __0100mmmm01000111(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,spc */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc.l   @rm+,spc --> __0100mmmm01000111\n");
    exit(1);
}

void __0100mmmm11110110(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,dbr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc.l   @rm+,dbr --> __0100mmmm11110110\n");
    exit(1);
}

void __0100mmmm1nnn0111(SH4Context_t *c, uint16_t op)
{
    /* ldc.l   @rm+,rn_bank */
    int8_t m = (op>>8)&0xf;
    int8_t n = (op>>4)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldc.l   @rm+,rn_bank --> __0100mmmm1nnn0111\n");
    exit(1);
}

void __0100mmmm00001010(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,mach */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] lds     rm,mach --> __0100mmmm00001010\n");
    exit(1);
}

void __0100mmmm00011010(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,macl */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] lds     rm,macl --> __0100mmmm00011010\n");
    exit(1);
}

void __0100mmmm00101010(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,pr */
    int8_t m = (op>>8)&0xf;
    c->regs.PR = _R(m);
}

void __0100mmmm00000110(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,mach */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] lds.l   @rm+,mach --> __0100mmmm00000110\n");
    exit(1);
}

void __0100mmmm00010110(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,macl */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] lds.l   @rm+,macl --> __0100mmmm00010110\n");
    exit(1);
}

void __0100mmmm00100110(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,pr */
    int8_t m = (op>>8)&0xf;
    c->regs.PR = SH4_MMU_ReadU32(c, _R(m));
    _R(m) += 4;
}

void __0000000000111000(SH4Context_t *c, uint16_t op)
{
    /* ldtlb */
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ldtlb --> __0000000000111000\n");
    exit(1);
}

void __0000nnnn11000011(SH4Context_t *c, uint16_t op)
{
    /* movca.l r0,@rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] movca.l r0,@rn --> __0000nnnn11000011\n");
    exit(1);
}

void __0000000000001001(SH4Context_t *c, uint16_t op)
{
    /* nop */
}

void __0000nnnn10010011(SH4Context_t *c, uint16_t op)
{
    /* ocbi    @rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ocbi    @rn --> __0000nnnn10010011\n");
    exit(1);
}

void __0000nnnn10100011(SH4Context_t *c, uint16_t op)
{
    /* ocbp    @rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ocbp    @rn --> __0000nnnn10100011\n");
    exit(1);
}

void __0000nnnn10110011(SH4Context_t *c, uint16_t op)
{
    /* ocbwb   @rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ocbwb   @rn --> __0000nnnn10110011\n");
    exit(1);
}

void __0000nnnn10000011(SH4Context_t *c, uint16_t op)
{
    /* pref    @rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] pref    @rn --> __0000nnnn10000011\n");
    exit(1);
}

void __0000000000101011(SH4Context_t *c, uint16_t op)
{
    /* rte */
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] rte --> __0000000000101011\n");
    exit(1);
}

void __0000000001011000(SH4Context_t *c, uint16_t op)
{
    /* sets */
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sets --> __0000000001011000\n");
    exit(1);
}

void __0000000000011000(SH4Context_t *c, uint16_t op)
{
    /* sett */
    c->regs.SR.T = 1;
}

void __0000000000011011(SH4Context_t *c, uint16_t op)
{
    /* sleep */
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sleep --> __0000000000011011\n");
    exit(1);
}

void __0000nnnn00000010(SH4Context_t *c, uint16_t op)
{
    /* stc     sr,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc     sr,rn --> __0000nnnn00000010\n");
    exit(1);
}

void __0000nnnn00010010(SH4Context_t *c, uint16_t op)
{
    /* stc     gbr,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc     gbr,rn --> __0000nnnn00010010\n");
    exit(1);
}

void __0000nnnn00100010(SH4Context_t *c, uint16_t op)
{
    /* stc     vbr,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc     vbr,rn --> __0000nnnn00100010\n");
    exit(1);
}

void __0000nnnn00110010(SH4Context_t *c, uint16_t op)
{
    /* stc     ssr,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc     ssr,rn --> __0000nnnn00110010\n");
    exit(1);
}

void __0000nnnn01000010(SH4Context_t *c, uint16_t op)
{
    /* stc     spc,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc     spc,rn --> __0000nnnn01000010\n");
    exit(1);
}

void __0000nnnn00111010(SH4Context_t *c, uint16_t op)
{
    /* stc     sgr,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc     sgr,rn --> __0000nnnn00111010\n");
    exit(1);
}

void __0000nnnn11111010(SH4Context_t *c, uint16_t op)
{
    /* stc     dbr,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc     dbr,rn --> __0000nnnn11111010\n");
    exit(1);
}

void __0000nnnn1mmm0010(SH4Context_t *c, uint16_t op)
{
    /* stc     rm_bank,rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc     rm_bank,rn --> __0000nnnn1mmm0010\n");
    exit(1);
}

void __0100nnnn00000011(SH4Context_t *c, uint16_t op)
{
    /* stc.l   sr,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc.l   sr,@-rn --> __0100nnnn00000011\n");
    exit(1);
}

void __0100nnnn00010011(SH4Context_t *c, uint16_t op)
{
    /* stc.l   gbr,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc.l   gbr,@-rn --> __0100nnnn00010011\n");
    exit(1);
}

void __0100nnnn00100011(SH4Context_t *c, uint16_t op)
{
    /* stc.l   vbr,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc.l   vbr,@-rn --> __0100nnnn00100011\n");
    exit(1);
}

void __0100nnnn00110011(SH4Context_t *c, uint16_t op)
{
    /* stc.l   ssr,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc.l   ssr,@-rn --> __0100nnnn00110011\n");
    exit(1);
}

void __0100nnnn01000011(SH4Context_t *c, uint16_t op)
{
    /* stc.l   spc,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc.l   spc,@-rn --> __0100nnnn01000011\n");
    exit(1);
}

void __0100nnnn00110010(SH4Context_t *c, uint16_t op)
{
    /* stc.l   sgr,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc.l   sgr,@-rn --> __0100nnnn00110010\n");
    exit(1);
}

void __0100nnnn11110010(SH4Context_t *c, uint16_t op)
{
    /* stc.l   dbr,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc.l   dbr,@-rn --> __0100nnnn11110010\n");
    exit(1);
}

void __0100nnnn1mmm0011(SH4Context_t *c, uint16_t op)
{
    /* stc.l   rm_bank,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] stc.l   rm_bank,@-rn --> __0100nnnn1mmm0011\n");
    exit(1);
}

void __0000nnnn00001010(SH4Context_t *c, uint16_t op)
{
    /* sts     mach,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sts     mach,rn --> __0000nnnn00001010\n");
    exit(1);
}

void __0000nnnn00011010(SH4Context_t *c, uint16_t op)
{
    /* sts     macl,rn */
    int8_t n = (op>>8)&0xf;
    _R(n) = c->regs.MACL;
}

void __0000nnnn00101010(SH4Context_t *c, uint16_t op)
{
    /* sts   pr,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sts   pr,rn --> __0000nnnn00101010\n");
    exit(1);
}

void __0100nnnn00000010(SH4Context_t *c, uint16_t op)
{
    /* sts.l   mach,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sts.l   mach,@-rn --> __0100nnnn00000010\n");
    exit(1);
}

void __0100nnnn00010010(SH4Context_t *c, uint16_t op)
{
    /* sts.l   macl,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sts.l   macl,@-rn --> __0100nnnn00010010\n");
    exit(1);
}

void __0100nnnn00100010(SH4Context_t *c, uint16_t op)
{
    /* sts.l   pr,@-rn */
    int8_t n = (op>>8)&0xf;
    _R(n) -= 4;
    SH4_MMU_WriteU32(c, c->regs.PR, _R(n));
}

void __11000011iiiiiiii(SH4Context_t *c, uint16_t op)
{
    /* trapa   #i */
    int8_t i = op&0xff;
    static int ignore = 4;
    return;
    if (ignore-- == 0) {
        SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] trapa   #i --> __11000011iiiiiiii %d\n", ignore);
        exit(1);
    }
}

void __1111nnnn10001101(SH4Context_t *c, uint16_t op)
{
    /* fldi0   frn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fldi0   frn --> __1111nnnn10001101\n");
    exit(1);
}

void __1111nnnn10011101(SH4Context_t *c, uint16_t op)
{
    /* fldi1   frn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fldi1   frn --> __1111nnnn10011101\n");
    exit(1);
}

void __1111nnnnmmmm1100(SH4Context_t *c, uint16_t op)
{
    /* fmov    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    frm,frn --> __1111nnnnmmmm1100\n");
    exit(1);
}

void __1111nnnnmmmm1000(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  @rm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov.s  @rm,frn --> __1111nnnnmmmm1000\n");
    exit(1);
}

void __1111nnnnmmmm0110(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  @(r0,rm),frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov.s  @(r0,rm),frn --> __1111nnnnmmmm0110\n");
    exit(1);
}

void __1111nnnnmmmm1001(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  @rm+,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov.s  @rm+,frn --> __1111nnnnmmmm1001\n");
    exit(1);
}

void __1111nnnnmmmm1010(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  frm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov.s  frm,@rn --> __1111nnnnmmmm1010\n");
    exit(1);
}

void __1111nnnnmmmm1011(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  frm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov.s  frm,@-rn --> __1111nnnnmmmm1011\n");
    exit(1);
}

void __1111nnnnmmmm0111(SH4Context_t *c, uint16_t op)
{
    /* fmov.s  frm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov.s  frm,@(r0,rn) --> __1111nnnnmmmm0111\n");
    exit(1);
}

void __1111nnn0mmm01100(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    drm,drn --> __1111nnn0mmm01100\n");
    exit(1);
}

void __1111nnn0mmmm1000(SH4Context_t *c, uint16_t op)
{
    /* fmov    @rm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    @rm,drn --> __1111nnn0mmmm1000\n");
    exit(1);
}

void __1111nnn0mmmm0110(SH4Context_t *c, uint16_t op)
{
    /* fmov    @(r0,rm),drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    @(r0,rm),drn --> __1111nnn0mmmm0110\n");
    exit(1);
}

void __1111nnn0mmmm1001(SH4Context_t *c, uint16_t op)
{
    /* fmov    @rm+,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    @rm+,drn --> __1111nnn0mmmm1001\n");
    exit(1);
}

void __1111nnnnmmm01010(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    drm,@rn --> __1111nnnnmmm01010\n");
    exit(1);
}

void __1111nnnnmmm01011(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    drm,@-rn --> __1111nnnnmmm01011\n");
    exit(1);
}

void __1111nnnnmmm00111(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    drm,@(r0,rn) --> __1111nnnnmmm00111\n");
    exit(1);
}

void __1111mmmm00011101(SH4Context_t *c, uint16_t op)
{
    /* flds    frm,fpul */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] flds    frm,fpul --> __1111mmmm00011101\n");
    exit(1);
}

void __1111nnnn00001101(SH4Context_t *c, uint16_t op)
{
    /* fsts    fpul,frn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fsts    fpul,frn --> __1111nnnn00001101\n");
    exit(1);
}

void __1111nnnn01011101(SH4Context_t *c, uint16_t op)
{
    /* fabs    frn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fabs    frn --> __1111nnnn01011101\n");
    exit(1);
}

void __1111nnnnmmmm0000(SH4Context_t *c, uint16_t op)
{
    /* fadd    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fadd    frm,frn --> __1111nnnnmmmm0000\n");
    exit(1);
}

void __1111nnnnmmmm0100(SH4Context_t *c, uint16_t op)
{
    /* fcmp/eq frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fcmp/eq frm,frn --> __1111nnnnmmmm0100\n");
    exit(1);
}

void __1111nnnnmmmm0101(SH4Context_t *c, uint16_t op)
{
    /* fcmp/gt frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fcmp/gt frm,frn --> __1111nnnnmmmm0101\n");
    exit(1);
}

void __1111nnnnmmmm0011(SH4Context_t *c, uint16_t op)
{
    /* fdiv    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fdiv    frm,frn --> __1111nnnnmmmm0011\n");
    exit(1);
}

void __1111nnnn00101101(SH4Context_t *c, uint16_t op)
{
    /* float   fpul,frn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] float   fpul,frn --> __1111nnnn00101101\n");
    exit(1);
}

void __1111nnnnmmmm1110(SH4Context_t *c, uint16_t op)
{
    /* fmac    fr0,frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmac    fr0,frm,frn --> __1111nnnnmmmm1110\n");
    exit(1);
}

void __1111nnnnmmmm0010(SH4Context_t *c, uint16_t op)
{
    /* fmul    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmul    frm,frn --> __1111nnnnmmmm0010\n");
    exit(1);
}

void __1111nnnn01001101(SH4Context_t *c, uint16_t op)
{
    /* fneg    frn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fneg    frn --> __1111nnnn01001101\n");
    exit(1);
}

void __1111nnnn01101101(SH4Context_t *c, uint16_t op)
{
    /* fsqrt   frn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fsqrt   frn --> __1111nnnn01101101\n");
    exit(1);
}

void __1111nnnnmmmm0001(SH4Context_t *c, uint16_t op)
{
    /* fsub    frm,frn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fsub    frm,frn --> __1111nnnnmmmm0001\n");
    exit(1);
}

void __1111mmmm00111101(SH4Context_t *c, uint16_t op)
{
    /* ftrc    frm,fpul */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ftrc    frm,fpul --> __1111mmmm00111101\n");
    exit(1);
}

void __1111nnn001011101(SH4Context_t *c, uint16_t op)
{
    /* fabs    drn */
    int8_t n = (op>>9)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fabs    drn --> __1111nnn001011101\n");
    exit(1);
}

void __1111nnn0mmm00000(SH4Context_t *c, uint16_t op)
{
    /* fadd    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fadd    drm,drn --> __1111nnn0mmm00000\n");
    exit(1);
}

void __1111nnn0mmm00100(SH4Context_t *c, uint16_t op)
{
    /* fcmp/eq drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fcmp/eq drm,drn --> __1111nnn0mmm00100\n");
    exit(1);
}

void __1111nnn0mmm00101(SH4Context_t *c, uint16_t op)
{
    /* fcmp/gt drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fcmp/gt drm,drn --> __1111nnn0mmm00101\n");
    exit(1);
}

void __1111nnn0mmm00011(SH4Context_t *c, uint16_t op)
{
    /* fdiv    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fdiv    drm,drn --> __1111nnn0mmm00011\n");
    exit(1);
}

void __1111mmm010111101(SH4Context_t *c, uint16_t op)
{
    /* fcnvds  drm,fpul */
    int8_t m = (op>>9)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fcnvds  drm,fpul --> __1111mmm010111101\n");
    exit(1);
}

void __1111nnn010101101(SH4Context_t *c, uint16_t op)
{
    /* fcnvsd  fpul,drn */
    int8_t n = (op>>9)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fcnvsd  fpul,drn --> __1111nnn010101101\n");
    exit(1);
}

void __1111nnn000101101(SH4Context_t *c, uint16_t op)
{
    /* float   fpul,drn */
    int8_t n = (op>>9)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] float   fpul,drn --> __1111nnn000101101\n");
    exit(1);
}

void __1111nnn0mmm00010(SH4Context_t *c, uint16_t op)
{
    /* fmul    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmul    drm,drn --> __1111nnn0mmm00010\n");
    exit(1);
}

void __1111nnn001001101(SH4Context_t *c, uint16_t op)
{
    /* fneg    drn */
    int8_t n = (op>>9)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fneg    drn --> __1111nnn001001101\n");
    exit(1);
}

void __1111nnn001101101(SH4Context_t *c, uint16_t op)
{
    /* fsqrt   drn */
    int8_t n = (op>>9)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fsqrt   drn --> __1111nnn001101101\n");
    exit(1);
}

void __1111nnn0mmm00001(SH4Context_t *c, uint16_t op)
{
    /* fsub    drm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fsub    drm,drn --> __1111nnn0mmm00001\n");
    exit(1);
}

void __1111mmm000111101(SH4Context_t *c, uint16_t op)
{
    /* ftrc    drm,fpul */
    int8_t m = (op>>9)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ftrc    drm,fpul --> __1111mmm000111101\n");
    exit(1);
}

void __0100mmmm01101010(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,fpscr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] lds     rm,fpscr --> __0100mmmm01101010\n");
    exit(1);
}

void __0100mmmm01011010(SH4Context_t *c, uint16_t op)
{
    /* lds     rm,fpul */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] lds     rm,fpul --> __0100mmmm01011010\n");
    exit(1);
}

void __0100mmmm01100110(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,fpscr */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] lds.l   @rm+,fpscr --> __0100mmmm01100110\n");
    exit(1);
}

void __0100mmmm01010110(SH4Context_t *c, uint16_t op)
{
    /* lds.l   @rm+,fpul */
    int8_t m = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] lds.l   @rm+,fpul --> __0100mmmm01010110\n");
    exit(1);
}

void __0000nnnn01101010(SH4Context_t *c, uint16_t op)
{
    /* sts     fpscr,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sts     fpscr,rn --> __0000nnnn01101010\n");
    exit(1);
}

void __0000nnnn01011010(SH4Context_t *c, uint16_t op)
{
    /* sts     fpul,rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sts     fpul,rn --> __0000nnnn01011010\n");
    exit(1);
}

void __0100nnnn01100010(SH4Context_t *c, uint16_t op)
{
    /* sts.l   fpscr,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sts.l   fpscr,@-rn --> __0100nnnn01100010\n");
    exit(1);
}

void __0100nnnn01010010(SH4Context_t *c, uint16_t op)
{
    /* sts.l   fpul,@-rn */
    int8_t n = (op>>8)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] sts.l   fpul,@-rn --> __0100nnnn01010010\n");
    exit(1);
}

void __1111nnn1mmm01100(SH4Context_t *c, uint16_t op)
{
    /* fmov    drm,xdn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    drm,xdn --> __1111nnn1mmm01100\n");
    exit(1);
}

void __1111nnn0mmm11100(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    xdm,drn --> __1111nnn0mmm11100\n");
    exit(1);
}

void __1111nnn1mmm11100(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,xdn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    xdm,xdn --> __1111nnn1mmm11100\n");
    exit(1);
}

void __1111nnn1mmmm1000(SH4Context_t *c, uint16_t op)
{
    /* fmov    @rm,xdn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    @rm,xdn --> __1111nnn1mmmm1000\n");
    exit(1);
}

void __1111nnn1mmmm1001(SH4Context_t *c, uint16_t op)
{
    /* fmov    @rm+,xdn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    @rm+,xdn --> __1111nnn1mmmm1001\n");
    exit(1);
}

void __1111nnn1mmmm0110(SH4Context_t *c, uint16_t op)
{
    /* fmov    @(r0,rm),drn */
    int8_t n = (op>>9)&0x7;
    int8_t m = (op>>4)&0xf;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    @(r0,rm),drn --> __1111nnn1mmmm0110\n");
    exit(1);
}

void __1111nnnnmmm11010(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,@rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    xdm,@rn --> __1111nnnnmmm11010\n");
    exit(1);
}

void __1111nnnnmmm11011(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,@-rn */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    xdm,@-rn --> __1111nnnnmmm11011\n");
    exit(1);
}

void __1111nnnnmmm10111(SH4Context_t *c, uint16_t op)
{
    /* fmov    xdm,@(r0,rn) */
    int8_t n = (op>>8)&0xf;
    int8_t m = (op>>5)&0x7;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fmov    xdm,@(r0,rn) --> __1111nnnnmmm10111\n");
    exit(1);
}

void __1111nnmm11101101(SH4Context_t *c, uint16_t op)
{
    /* fipr    fvm,fvn */
    int8_t n = (op>>10)&0x3;
    int8_t m = (op>>8)&0x3;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fipr    fvm,fvn --> __1111nnmm11101101\n");
    exit(1);
}

void __1111nn0111111101(SH4Context_t *c, uint16_t op)
{
    /* ftrv    xmtrx,fvn */
    int8_t n = (op>>10)&0x3;
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] ftrv    xmtrx,fvn --> __1111nn0111111101\n");
    exit(1);
}

void __1111101111111101(SH4Context_t *c, uint16_t op)
{
    /* frchg */
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] frchg --> __1111101111111101\n");
    exit(1);
}

void __1111001111111101(SH4Context_t *c, uint16_t op)
{
    /* fschg */
    SH4_Log(SH4_LOG_ERROR, "[NOT IMPLEMENTED!] fschg --> __1111001111111101\n");
    exit(1);
}

