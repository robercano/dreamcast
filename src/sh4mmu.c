/**
 * Main API functions not belonging to any other subsystem
 *
 * @author Roberto Cano <http://www.robertocano.es>
 */
#include "sh4.h"
#include "sh4opcode.h"
#include <stdlib.h>
#include <arpa/inet.h>

void SH4_MMU_WriteU64(IN SH4Context_t *context, IN uint64_t value, uint32_t address)
{
    if (address >= context->memsize-7) {
        SH4_Log(SH4_LOG_ERROR, "MEMORY WRITE EXCEPTION AT ADDRESS %04x (PC=%08x)\n", address, context->regs.PC);
        if (context->abortOnException) {
            exit(1);
        }
        return;
    }
    *(uint64_t*)(context->memory+address) = value;
}

void SH4_MMU_WriteU32(IN SH4Context_t *context, IN uint32_t value, uint32_t address)
{
    if (address >= context->memsize-3) {
        SH4_Log(SH4_LOG_ERROR, "MEMORY WRITE EXCEPTION AT ADDRESS %04x (PC=%08x)\n", address, context->regs.PC);
        if (context->abortOnException) {
            exit(1);
        }
        return;
    }
    *(uint32_t*)(context->memory+address) = value;
}

void SH4_MMU_WriteU16(IN SH4Context_t *context, IN uint16_t value, uint32_t address)
{
    if (address >= context->memsize-1) {
        SH4_Log(SH4_LOG_ERROR, "MEMORY WRITE EXCEPTION AT ADDRESS %04x (PC=%08x)\n", address, context->regs.PC);
        if (context->abortOnException) {
            exit(1);
        }
        return;
    }
    *(uint16_t*)(context->memory+address) = value;
}

void SH4_MMU_WriteU8(IN SH4Context_t *context, IN uint8_t value, uint32_t address)
{
    if (address >= context->memsize) {
        SH4_Log(SH4_LOG_ERROR, "MEMORY WRITE EXCEPTION AT ADDRESS %04x (PC=%08x)\n", address, context->regs.PC);
        if (context->abortOnException) {
            exit(1);
        }
        return;
    }
    *(uint8_t*)(context->memory+address) = value;
}

uint64_t SH4_MMU_ReadU64(IN SH4Context_t *context, IN uint32_t address)
{
    if (address >= context->memsize-7) {
        SH4_Log(SH4_LOG_ERROR, "MEMORY READ EXCEPTION AT ADDRESS %04x\n", address);
        if (context->abortOnException) {
            exit(1);
        }
        return 0;
    }
    return *(uint64_t*)(context->memory+address);
}

uint32_t SH4_MMU_ReadU32(IN SH4Context_t *context, IN uint32_t address)
{
    if (address >= context->memsize-3) {
        SH4_Log(SH4_LOG_ERROR, "MEMORY READ EXCEPTION AT ADDRESS %04x\n", address);
        if (context->abortOnException) {
            exit(1);
        }
        return 0;
    }
    return *(uint32_t*)(context->memory+address);
}

int16_t SH4_MMU_ReadS16(IN SH4Context_t *context, IN uint32_t address)
{
    if (address >= context->memsize-1) {
        SH4_Log(SH4_LOG_ERROR, "MEMORY READ EXCEPTION AT ADDRESS %04x\n", address);
        if (context->abortOnException) {
            exit(1);
        }
        return 0;
    }
    return (int16_t)*(uint32_t*)(context->memory+address);
}

int8_t SH4_MMU_ReadS8(IN SH4Context_t *context, IN uint32_t address)
{
    if (address >= context->memsize-1) {
        SH4_Log(SH4_LOG_ERROR, "MEMORY READ EXCEPTION AT ADDRESS %04x\n", address);
        if (context->abortOnException) {
            exit(1);
        }
        return 0;
    }
    return (int8_t)context->memory[address];
}
