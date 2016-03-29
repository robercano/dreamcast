/**
 * Logging subsystem
 *
 * @author Roberto Cano <http://www.robertocano.es>
 */
#include "sh4.h"
#include <stdarg.h>
#include <stdio.h>

static SH4LogLevel_t __current_log_level__ = SH4_LOG_DEBUG;

const char *__SH4_ErrorToString(SH4Error error)
{
    switch (error)
    {
        case SH4_SUCCESS:
            return "No error";
        case SH4_ERROR_BAD_PARAMS:
            return "Bad parameters";
        case SH4_ERROR_FILE_NOT_FOUND:
            return "File not found";
        case SH4_ERROR_WRONG_FORMAT:
            return "Wrong file format";
        case SH4_ERROR_OOM:
            return "Out of memory";
        case SH4_ERROR_BAD_MODE:
            return "Bad processor mode";
        case SH4_ERROR_CODE_TOO_BIG:
            return "Code too big for memory";
        default:
            return "Unknown error";
    }
}
void SH4_LogInit()
{
}

void SH4_SetLogLevel(SH4LogLevel_t level)
{
    __current_log_level__ = level;
}

void SH4_LogEx(SH4LogLevel_t level, const char *format, ...)
{
    va_list args;

    if (level > __current_log_level__) {
        return;
    }

    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
}

void SH4_Log(SH4LogLevel_t level, const char *format, ...)
{
    va_list args;

    if (level > __current_log_level__) {
        return;
    }

    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fprintf(stdout, "\n");
}

void SH4_LogErr(SH4LogLevel_t level, SH4Error err, const char *format, ...)
{
    va_list args;

    if (level > __current_log_level__) {
        return;
    }

    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fprintf(stdout, ": %s\n", __SH4_ErrorToString(err));
}
