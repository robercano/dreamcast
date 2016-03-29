/**
 * Main API functions not belonging to any other subsystem
 *
 * @author Roberto Cano <http://www.robertocano.es>
 */
#include "sh4.h"
#include "sh4opcode.h"
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

SH4Error SH4_InitContext(IN SH4Context_t *context)
{
    memset(context, 0, sizeof *context);
    SH4_LogInit();
    return SH4_SUCCESS;
}

SH4Error SH4_Reset(IN SH4Context_t *c)
{
    if (c== NULL) {
        return SH4_ERROR_BAD_PARAMS;
    }
    memset(&c->regs, 0, sizeof c->regs);

    c->regs.PC   = c->main;
    c->regs.NPC  = c->main+2;
    c->regs.NNPC = c->main+4;

    c->regs.PR   = 0xffffffff;

    _R(15) = c->stack;

    c->globalbp = 0;
    c->debug_mode = 's';

    return SH4_SUCCESS;
}

SH4Error SH4_EnableDebug(IN SH4Context_t *context)
{
    if (context == NULL) {
        return SH4_ERROR_BAD_PARAMS;
    }
    context->debug = true;
    return SH4_SUCCESS;
}

SH4Error SH4_EnableAbort(IN SH4Context_t *context)
{
    if (context == NULL) {
        return SH4_ERROR_BAD_PARAMS;
    }
    context->abortOnException = true;
    return SH4_SUCCESS;
}

SH4Error SH4_ExecuteStep(SH4Context_t *context)
{
    uint16_t op;

    if (context == NULL) {
        return SH4_ERROR_BAD_PARAMS;
    }

    op = *(uint16_t*)(context->memory+context->regs.PC);

    /* Execute the opcode */
    SH7750InterpLUT[op](context, op);

    context->regs.PC    = context->regs.NPC;
    context->regs.NPC   = context->regs.NNPC;
    context->regs.NNPC += 2;

    if (context->regs.PC > context->memsize) {
        /* If address is 0xffffffff let's assume the program terminated gracefully */
        if (context->regs.PC != 0xffffffff) {
            SH4_Log(SH4_LOG_ERROR, "CODE EXCEPTION, TRYING TO ACCESS ADDRESS 0x%08x\n", context->regs.PC);
        }
        return SH4_CPU_HALTED;
    }
    return SH4_SUCCESS;
}

uint32_t SH4_Execute(SH4Context_t *c, int argc, char **argv)
{
    uint32_t offset = 0, ptroff = 0, i;

    /* Copy the parameters to upper memory for now */
    _R(4) = argc;

    offset = c->memsize - 1024;
    for (i=0; i<argc; ++i) {
        int len = strlen(argv[i])+1;
        memcpy(c->memory + offset, argv[i], len);
        offset += len;
    }

    /* And now prepare the pointers */
    _R(5) = offset;

    ptroff = offset;
    offset = c->memsize - 1024;
    for (i=0; i<argc; ++i) {
        *(uint32_t*)(c->memory + ptroff) = offset;
        offset += strlen(argv[i])+1;
        ptroff += sizeof(uint32_t);
    }

    if (c->debug) {
        SH4_DBG_Init(c);
        do {
            SH4_DBG_Show(c);
        } while (SH4_ExecuteStep(c) == SH4_SUCCESS);
        SH4_DBG_Finalize(c);
    } else {
        while (SH4_ExecuteStep(c) == SH4_SUCCESS);
    }
    return c->regs.R[0].bank[0];
}
