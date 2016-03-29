/**
 * SH4 interpreter
 *
 * Interpreter for the SH7750h (Super-H) processor used in the Dreamcast
 * console. For now this attempts to be just an study of the processor
 * with the target to run simple barebone applications. In future revisions
 * it may be used as the core for a Dreamcast emulator
 *
 * @author Roberto Cano <http://www.robertocano.es>
 * @date 26-Aug-2015
 */
#ifndef __SH4_H__
#define __SH4_H__

#include <stdint.h>
#include <stdbool.h>

/**
 * Error types
 */
typedef enum {
    SH4_SUCCESS = 0,
    SH4_ERROR_BAD_PARAMS          = 0xDCE00001,
    SH4_ERROR_FILE_NOT_FOUND      = 0xDCE00002,
    SH4_ERROR_WRONG_FORMAT        = 0xDCE00003,
    SH4_ERROR_OOM                 = 0xDCE00004,
    SH4_ERROR_BAD_MODE            = 0xDCE00005,
    SH4_ERROR_CODE_TOO_BIG        = 0xDCE00006,
    SH4_CPU_HALTED                = 0xDCE00007,
    SH4_ERROR_SYSTEM              = 0xDCE00008,
    SH4_ERROR_BUFFER_TOO_SMALL    = 0xDCE00009,
} SH4Error;

/**
 * Log levels
 */
typedef enum {
    SH4_LOG_ERROR   = 1,
    SH4_LOG_INFO    = 2,
    SH4_LOG_VERBOSE = 3,
    SH4_LOG_DEBUG   = 4
} SH4LogLevel_t;


/**
 * For API documentation
 */
#define IN
#define OUT
#define INOUT

/**
 * Registers
 *
 * The SH7750h has 24 general purpose registers. However half the registers
 * are banked and are activated depending on the CPU being in user or privileged
 * mode, and in privileged mode depending on the bank selection flag RB
 */
typedef struct __sh7750h_registers
{
	/* General purpose registers */
	struct __sh7750h_gp_register {
		/* The 2 banks are only used by the first 8 registers.
		 * The upper 8 registers only use bank 1 for convenience,
		 * see the _R macro below */
		uint32_t bank[2];
	} R[16];
#define _R(num)     c->regs.R[num].bank[((c->regs.SR.RB)&(c->regs.SR.MD))|(num>>3)]
#define _LDCR(num)  c->regs.R[num].bank[((!c->regs.SR.RB)&(c->regs.SR.MD))|(num>>3)]

	/** Control registers */
	struct __sh7750h_status_register {
		uint8_t MD; /**< Processor mode: 0=user mode, 1=privileged mode */
		uint8_t RB; /**< Register bank specifier in privileged mode */
	    uint8_t BL; /**< 1=interruptions are mask, exception state */
		uint8_t FD; /**< 1=FPU disabled due to exception */
		uint8_t M;  /**< Used by DIV0S, DIV0U and DIV1 */
		uint8_t Q;  /**< Used by DIV0S, DIV0U and DIV1 */
		uint8_t IMASK; /**< Interrupt mask level */
		uint8_t S;  /**< Specifies a saturation operation for a MAC instruction */
		uint8_t T;  /**< True/false or carry/borrow bit */
	} SR,  /**< Status register */
	  SSR; /**< Saved status register: Only accesible in privileged mode */
#define _SR ((((uint32_t)c->regs.SR.MD)<<30) | \
		    (((uint32_t)c->regs.SR.RB)<<29) | \
		    (((uint32_t)c->regs.SR.BL)<<28) | \
		    (((uint32_t)c->regs.SR.FD)<<15) | \
		    (((uint32_t)c->regs.SR.M )<< 9) | \
		    (((uint32_t)c->regs.SR.Q )<< 8) | \
		    (((uint32_t)c->regs.SR.IMASK)<<4) | \
		    (((uint32_t)c->regs.SR.S )<< 1) | \
		    ((uint32_t)c->regs.SR.T))
#define _SRSET(value) { c->regs.SR.MD = (value>>30)&1;\
                        c->regs.SR.RB = (value>>29)&1;\
                        c->regs.SR.BL = (value>>28)&1;\
                        c->regs.SR.FD = (value>>15)&1;\
                        c->regs.SR.M  = (value>>9 )&1;\
                        c->regs.SR.Q  = (value>>8 )&1;\
                        c->regs.SR.IMASK = (value>>4)&0xf;\
                        c->regs.SR.S  = (value>>1)&1;\
                        c->regs.SR.T  = value&1;}

	/* Floating point registers */
	struct __sh7750h_fp_register {
		union {
			float  FR[16];        /**< Single-precision floating register */
			double DR[8];         /**< Double-precision floating register */
			struct {
				uint8_t data[16]; /**< Vector register */
			} FV[4];
			struct {
				uint8_t data[64]; /**< Matrix register */
			} XMTRX;
		} bank[2];                /**< FPRn_BANKi */
	} FPR; /**< Floating-point banked registers */
#define _FR(num) c->regs.FPR.bank[c->regs.FPSCR.FR].FR[num]
#define _DR(num) c->regs.FPR.bank[c->regs.FPSCR.FR].DR[num]
#define _FV(num) c->regs.FPR.bank[c->regs.FPSCR.FR].FV[num].data
#define _XF(num) c->regs.FPR.bank[!c->regs.FPSCR.FR].FR[num]
#define _XD(num) c->regs.FPR.bank[!c->regs.FPSCR.FR].DR[num]
#define _XMTRX   c->regs.FPR.bank[!c->regs.FPSCR.FR].XMTRX.data

	uint32_t SPC; /**< Saved program counter: Only accesible in privileged mode */
	uint32_t GBR; /**< Global Base Register used in GBR-referencing MOV */
	uint32_t VBR; /**< Vector Base Register used as base addres in case of exception,
	                   Only accesible in privileged mode */
	uint32_t SGR; /**< General register 15 is saved here in case of an exception,
	                   Only accesible in privileged mode */
	uint32_t DBR; /**< Debug Base Register used as a branch for a debug break */

	/* System registers */
	uint32_t MACH; /**< Multiply-and-accumulate register high */
	uint32_t MACL; /**< Multiply-and-accumulate register low, used with MACH for
                        MAC instructions */
	uint32_t PR;   /**< Procedure register saves the return address for a subroutine */
	uint32_t PC;   /**< Program counter */
    uint32_t NPC;
    uint32_t NNPC;
	struct __sh7750h_fpscr {
		uint8_t FR;  /**< Floating-point register bank */
		uint8_t SZ;  /**< Transfer size mode 0=FMOV is 32-bit, 1=FMOV is 64-bit (register pair) */
		uint8_t PR;  /**< Precision mode 0=single-precision, 1=double-precision */
		uint8_t DN;  /**< Denormalization mode 0=treat as such (NaN), 1=treat as 0 */
		uint8_t cause;  /**< FPU exception cause */
		uint8_t enable; /**< FPU exception enable */
		uint8_t flag;   /**< FPU exception flag */
		uint8_t RM;     /**< Rounding mode 00=round to nearest, 01=round to zero */
	} FPSCR;
#define _FPSCR ((((uint32_t)c->regs.FPSCR.FR)<<21) | \
		       (((uint32_t)c->regs.FPSCR.SZ)<<20) | \
		       (((uint32_t)c->regs.FPSCR.PR)<<19) | \
		       (((uint32_t)c->regs.FPSCR.DN)<<18) | \
		       (((uint32_t)c->regs.FPSCR.cause)<<12) | \
			   (((uint32_t)c->regs.FPSCR.flag)<<2) | \
		       ((uint32_t)c->regs.FPSCR.RM))

	uint32_t FPUL;  /**< FPU communication register */


} SH4Registers_t;

/**
 * Main context
 */
typedef struct {
    /* Main memory */
    uint8_t *memory;     /**< Memory buffer to hold the loaded ELF */
    uint32_t memsize;    /**< Size of the memory buffer */

    /* Registers */
    SH4Registers_t regs; /**< Main CPU registers */

    /* Useful addresses */
    uint32_t entrypoint; /**< Original entrypoint to start executing */
    uint32_t main;       /**< Address of the main function */
    uint32_t print;      /**< Address of the printf function */
    uint32_t puts;       /**< Address of the puts function */
    uint32_t stack;      /**< Address of the stack section */
    char format[64];     /**< Format of the ELF file */

    /* Symbol table items */
    struct __sh4_symbol_entry {
        char name[32];
        uint32_t address;
    } symbTable[1024];     /**< Symbol table extracted from ELF file */
    uint32_t symbTableLen; /**< Length of the symbol table */

    /* Section table */
    struct __sh4_section_entry {
        char name[32];
        uint32_t lma;
        uint32_t vma;
        uint32_t size;
        bool load;
    } sectTable[64];       /**< Section table extracted from ELF file */
    uint32_t sectTableLen; /**< Length of the section table */

    /* Misc. */
    bool abortOnException; /** Abort execution if an exception is found */
    bool debug;            /**< Enable debug mode. It allows to go step by step
                                and shows comprehensive information on screen */

    /* Debugger */
    uint32_t dispmem;
    uint32_t d32list[10];
    uint32_t d32listLen;
    uint32_t d16list[10];
    uint32_t d16listLen;
    uint32_t d8list[10];
    uint32_t d8listLen;
    uint32_t dslist[10];
    uint32_t dslistLen;
    struct __bplist_item {
        uint32_t addr;
        char *name;
    } bpList[32];
    uint32_t bpListLen;
    uint32_t globalbp;
    uint32_t globalbp_next;
    char debug_mode;

} SH4Context_t;

/*****************************************************************
 * SH4 API
 *
 * All functions of this API return SH4_SUCCESS if the call was
 * succesful and SH4_ERROR_BAD_PARAMS if the parameters of the
 * function are wrong. The rest of the errors are specific to
 * the function
 *
 ******************************************************************/

/**
 * Initializes the given context to be used by the SH4 API
 *
 * @param context  Pointer to the context structure to be initialized
 */
SH4Error SH4_InitContext(IN SH4Context_t *context);


/**********************************
 * Core CPU API
 **********************************/

/**
 * Resets the CPU and initializes the registers to the default values
 *
 * It also uses either main or entrypoint as PC initializer
 *
 * @param context  CPU context
 */
SH4Error SH4_Reset(IN SH4Context_t *context);

/**
 * Enters debug mode allowing step by step execution and
 * showing the internal state of the processor
 *
 * @param context  CPU context
 */
SH4Error SH4_EnableDebug(IN SH4Context_t *context);

/**
 * Enters abort on error behaviour. When an exception is
 * found the CPU aborts and shows the reason of the exception
 *
 * @param context  CPU context
 */
SH4Error SH4_EnableAbort(IN SH4Context_t *context);

/**
 * Shows info relative to the executable passed as a parameter
 *
 * It opens the ELF file, checks it is of the supported type and then
 * prints with INFO level all information related to the executable
 * including all sections.
 *
 * @param context    Context where the ELF will be loaded
 *
 * @return SH4_ERROR_FILE_NOT_FOUND if the file could not be opened
 * @return SH4_ERROR_WRONG_FORMAT if the file is not of the supported type
 */
void SH4_ELF_ShowInfo(IN SH4Context_t *context);

/**
 * Analyzes the given ELF file, allocates enough memory to load the
 * ELF sections into memory and copies all the loadable section.
 *
 * It also initializes the BSS area with zeroes
 *
 * @param context    Context where the ELF will be loaded
 * @param elfname    Path and name of the executable file to be loaded
 * @param maxMemSize Maximum memory size to be allocated
 *
 * @return SH4_ERROR_FILE_NOT_FOUND if the file could not be opened
 * @return SH4_ERROR_WRONG_FORMAT if the file is not of the supported type
 * @return SH4_ERROR_OOM if the memory could not be allocated
 */
SH4Error SH4_ELF_Load(IN SH4Context_t *context, IN const char *elfname, uint32_t maxMemSize);

/**
 * Dumps one line of the regs screen at a time, useful to present
 * a GUI for the debugger
 *
 * @param context  Context containing the registers
 * @param n        Number of line to present
 */
void SH4_DumpRegsLine(IN SH4Context_t *c, uint32_t n);

/**
 * Dumps to screen the contents of the registers with DEBUG level
 *
 * @param context  Context containing the registers
 */
void SH4_DumpRegs(IN SH4Context_t *context);

/**
 * Dumps to screen the contents of the indicated memory region
 *
 * If the indicated area goes beyond the last memory byte the
 * dump will stop at the last available byte of memory
 *
 * @param context  Context containing the memory
 * @param start    Start byte of the memory to show
 * @param size     Number of bytes to show from the starting byte
 */
void SH4_DumpMemory(IN SH4Context_t *context, IN uint32_t start, IN uint32_t size);

/**
 * Shows the debugger screen
 *
 * @param context  Context containing the memory and regs
 */
void SH4_ShowDebugger(IN SH4Context_t *context);

/**
 * Executes a single step on the CPU
 *
 * @param context  Context of the CPU
 */
SH4Error SH4_ExecuteStep(SH4Context_t *context);

/**
 * Performs execution of the loaded ELF
 *
 * @param context  Context of the CPU
 *
 * @return The value of R0
 */
uint32_t SH4_Execute(SH4Context_t *context, int argc, char **argv);


/**********************************
 * Log API
 **********************************/

/**
 * Initializes the logging system
 */
void SH4_LogInit();

/**
 * Sets the maximum log level to be logged
 *
 * @param level  New level for the logging system
 */
void SH4_SetLogLevel(IN SH4LogLevel_t level);

/**
 * Sends the message to the logging system with the required level
 * and does NOT add a new line
 *
 * @param level  Level of the trace
 * @param format Printf like format
 * @param ...    Parameters for the format
 */
void SH4_LogEx(SH4LogLevel_t level, const char *format, ...) __attribute__ ((format (printf, 2, 3)));

/**
 * Sends the message to the logging system with the required level
 * and DOES add a new line
 *
 * @param level  Level of the trace
 * @param format Printf like format
 * @param ...    Parameters for the format
 */
void SH4_Log(SH4LogLevel_t level, const char *format, ...) __attribute__ ((format (printf, 2, 3)));

/**
 * Sends the message to the logging system with the required level
 * and DOES add a new line. It also prints the string associated with
 * the given error after the message string
 *
 * @param level  Level of the trace
 * @param err    Error code
 * @param format Printf like format
 * @param ...    Parameters for the format
 */
void SH4_LogErr(SH4LogLevel_t level, SH4Error err, const char *format, ...) __attribute__ ((format (printf, 3, 4)));

/**********************************
 * MMU API
 **********************************/

/**
 * Writes an unsigned 64-bit number to memory
 *
 * @param context  Context of the CPU
 * @param value    Value to be written to memory
 * @param address  Address in the memory where to write the value
 */
void SH4_MMU_WriteU64(IN SH4Context_t *context, IN uint64_t value, uint32_t address);

/**
 * Writes an unsigned 32-bit number to memory
 *
 * @param context  Context of the CPU
 * @param value    Value to be written to memory
 * @param address  Address in the memory where to write the value
 */
void SH4_MMU_WriteU32(IN SH4Context_t *context, IN uint32_t value, uint32_t address);

/**
 * Writes an unsigned 16-bit number to memory
 *
 * @param context  Context of the CPU
 * @param value    Value to be written to memory
 * @param address  Address in the memory where to write the value
 */
void SH4_MMU_WriteU16(IN SH4Context_t *context, IN uint16_t value, uint32_t address);

/**
 * Writes an unsigned 8-bit number to memory
 *
 * @param context  Context of the CPU
 * @param value    Value to be written to memory
 * @param address  Address in the memory where to write the value
 */
void SH4_MMU_WriteU8(IN SH4Context_t *context, IN uint8_t value, uint32_t address);

/**
 * Reads an unsigned 64-bit number to memory
 *
 * @param context  Context of the CPU
 * @param address  Address in the memory where to write the value
 *
 * @return the 64-bit value read from memory
 */
uint64_t SH4_MMU_ReadU64(IN SH4Context_t *context, IN uint32_t address);

/**
 * Reads an unsigned 32-bit number to memory
 *
 * @param context  Context of the CPU
 * @param address  Address in the memory where to write the value
 *
 * @return the 32-bit value read from memory
 */
uint32_t SH4_MMU_ReadU32(IN SH4Context_t *context, IN uint32_t address);

/**
 * Reads a signed 16-bit number from memory
 *
 * @param context  Context of the CPU
 * @param address  Address in the memory where to read the value from
 *
 * @return the 16-bit signed value read from memory
 */
int16_t SH4_MMU_ReadS16(IN SH4Context_t *context, IN uint32_t address);

/**
 * Reads a signed 8-bit number from memory
 *
 * @param context  Context of the CPU
 * @param address  Address in the memory where to read the value from
 *
 * @return the 8-bit signed value read from memory
 */
int8_t SH4_MMU_ReadS8(IN SH4Context_t *context, IN uint32_t address);

/****************************
 * Debugger API
 ****************************/
void SH4_DBG_Init(SH4Context_t *c);
void SH4_DBG_Show(SH4Context_t *c);
void SH4_DBG_Finalize(SH4Context_t *c);

#endif // __SH4_H__
