/**
 * ncurses based debugger with some gdb-like functionality
 *
 * @author Roberto Cano <http://www.robertocano.es>
 */
#include "sh4.h"
#include "sh4opcode.h"
#include <ncurses.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

void SH4_DBG_Init(IN SH4Context_t *c)
{
    initscr();
    cbreak();
    noecho();
}

static void SH4_DBG_DumpRegs(IN SH4Context_t *c)
{
    int row = 2, col = 2;

    mvprintw(row++, col, "[GP Regs]");
    mvprintw(row++, col, "  R0  =%08x R1  =%08x R2  =%08x R3  =%08x", _R(0), _R(1), _R(2), _R(3));
    mvprintw(row++, col, "  R4  =%08x R5  =%08x R6  =%08x R7  =%08x", _R(4), _R(5), _R(6), _R(7));
    mvprintw(row++, col, "  R8  =%08x R9  =%08x R10 =%08x R11 =%08x", _R(8), _R(9), _R(10), _R(11));
    mvprintw(row++, col, "  R12 =%08x R13 =%08x R14 =%08x R15 =%08x", _R(12), _R(13), _R(14), _R(15));
    mvprintw(row++, col, "[System Regs]");
    mvprintw(row++, col, "  PC  =%08x NPC =%08x NNPC=%08x", c->regs.PC, c->regs.NPC, c->regs.NNPC);
    mvprintw(row++, col, "  PR  =%08x VBR =%08x", c->regs.PR, c->regs.VBR);
    mvprintw(row++, col, "  MACL=%08x MACH=%08x", c->regs.MACL, c->regs.MACH);
    mvprintw(row++, col, "[SSR]:");
    mvprintw(row++, col, "  MD  =%d        RB  =%d        BL  =%d        FD  =%d", c->regs.SR.MD, c->regs.SR.RB,
            c->regs.SR.BL, c->regs.SR.FD);
    mvprintw(row++, col, "  M   =%d        Q   =%d        S   =%d        T   =%d", c->regs.SR.M, c->regs.SR.Q,
            c->regs.SR.S, c->regs.SR.T);
    //mvprintw(row++, col, "gbp=%08x, gbpn=%08x", c->globalbp, c->globalbp_next);
}

static int symbol_entry_cmp(const void *a, const void *b) {
    struct __sh4_symbol_entry *l = (struct __sh4_symbol_entry *)a;
    struct __sh4_symbol_entry *r = (struct __sh4_symbol_entry *)b;
    return l->address < r->address ? -1 : (l->address > r->address) ? 1 : 0;
}
static void SH4_DBG_DumpDisasm(IN SH4Context_t *c)
{
    uint32_t PC, i;
    uint16_t op;
    int row, col;
    int xpos = 70, ypos = 4;
    struct __sh4_symbol_entry crit;
    struct __sh4_symbol_entry *item;

    getmaxyx(stdscr, row, col);
    (void)col;

    attron(A_STANDOUT);
    if (c->debug_mode == 's') {
        mvprintw(2, xpos, "EXECUTE: STEP");
    } else if (c->debug_mode == 'n') {
        mvprintw(2, xpos, "EXECUTE: NEXT");
    } else if (c->debug_mode == 'r') {
        mvprintw(2, xpos, "EXECUTE: RUNNING");
    } else {
        mvprintw(2, xpos, "EXECUTE: UNKNOWN");
    }
    attroff(A_STANDOUT);

    PC = c->regs.PC - 2*((row-4)/3);
    for (i=4; i<row-2; ++i, PC+=2) {
        op = *(uint16_t*)(c->memory+PC);

        /* Search the address in the symbols table */
        crit.address = PC;
        item = (struct __sh4_symbol_entry*)bsearch((void*)&crit, c->symbTable, c->symbTableLen, sizeof *c->symbTable, symbol_entry_cmp);
        if (item) {
            mvprintw(ypos, xpos-4, "%08x <%s>:", PC, item->name);
            if (i == row-3) {
                break;
            }
            ypos++;
            i++;
        }

        if (PC == c->regs.PC) {
            attron(A_BOLD);
            mvprintw(ypos, xpos-7, "->");
        }
        mvprintw(ypos, xpos, "%04x: ", PC);
        SH7750DisasmLUT[op](c, op);
        if (PC == c->regs.PC) {
            mvprintw(ypos, xpos+30, "<-");
            attroff(A_BOLD);
        }
        ypos++;
    }
}

static void SH4_DBG_DumpMem(IN SH4Context_t *c)
{
    uint32_t i, size, stop;
    int row, col, ypos = 16, xpos = 2;
#define MEMDUMP_BYTES_PER_ROW 16
    getmaxyx(stdscr, row, col);
    (void)col;

    mvprintw(ypos++, xpos, "[MEMORY]");

    if (c->dispmem > c->memsize) {
        mvprintw(ypos++, xpos, "    Address 0x%08x is out of bounds!", c->dispmem);
        return;
    }

    size = (row-16-4)*MEMDUMP_BYTES_PER_ROW;
    stop = c->dispmem+size;

    if (stop > c->memsize) {
        stop = c->memsize&0xfffffff0;
    }

    mvprintw(ypos++, xpos, "            ");
    for (i=0; i<MEMDUMP_BYTES_PER_ROW; ++i) {
        printw("%02x", (c->dispmem+i)&0xff);
        if (i%4 == 3) {
            printw(" ");
        }
    }
    for (i=c->dispmem; i<stop; i+=MEMDUMP_BYTES_PER_ROW) {
        mvprintw(ypos++, xpos, "  %08x: %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x",
                i, c->memory[i], c->memory[i+1], c->memory[i+2], c->memory[i+3],
                c->memory[i+4], c->memory[i+5], c->memory[i+6], c->memory[i+7],
                c->memory[i+8], c->memory[i+9], c->memory[i+10], c->memory[i+11],
                c->memory[i+12], c->memory[i+13], c->memory[i+14], c->memory[i+15]);
    }
    if (c->dispmem+size > c->memsize) {
        mvprintw(ypos, xpos, "    %08x: ", i);
        for (; i<c->memsize; i++) {
            printw("%02x", c->memory[i]);
        }
    }
}

static void SH4_DBG_DumpVars(IN SH4Context_t *c)
{
    uint32_t i, size, stop;
    int row, col, ypos = 2, xpos = 120;

    mvprintw(ypos++, xpos, "[32-bit vars]");
    for (i=0; i<c->d32listLen; ++i) {
        move(ypos, xpos);

        printw("  %d: [%08x]", i, c->d32list[i]);
        if (c->d32list[i] >= c->memsize-3) {
            printw(" out of bounds");
        } else {
            uint32_t var = *(uint32_t*)(c->memory+c->d32list[i]);
            printw(" %08x / %u / %d", var, var, var);
        }
        ypos++;
    }
    if (i == 0) {
        mvprintw(ypos++, xpos, "  No vars selected");
    }

    mvprintw(ypos++, xpos, "[16-bit vars]");
    for (i=0; i<c->d16listLen; ++i) {
        move(ypos, xpos);

        printw("  %d: [%08x]", i, c->d16list[i]);
        if (c->d16list[i] >= c->memsize-1) {
            printw(" out of bounds");
        } else {
            uint16_t var = *(uint16_t*)(c->memory+c->d16list[i]);
            printw(" %08x / %u / %d", var, var, var);
        }
        ypos++;
    }
    if (i == 0) {
        mvprintw(ypos++, xpos, "  No vars selected");
    }

    mvprintw(ypos++, xpos, "[8-bit vars]");
    for (i=0; i<c->d8listLen; ++i) {
        move(ypos, xpos);

        printw("  %d: [%08x]", i, c->d8list[i]);
        if (c->d8list[i] >= c->memsize) {
            printw(" out of bounds");
        } else {
            uint8_t var = *(uint8_t*)(c->memory+c->d8list[i]);
            printw(" %08x / %u / %d", var, var, var);
        }
        ypos++;
    }
    if (i == 0) {
        mvprintw(ypos++, xpos, "  No vars selected");
    }

    mvprintw(ypos++, xpos, "[string vars]");
    for (i=0; i<c->dslistLen; ++i) {
        move(ypos, xpos);

        printw("  %d: [%08x]", i, c->dslist[i]);
        if (c->dslist[i] >= c->memsize) {
            printw(" out of bounds");
        } else {
            char tmp[16];
            uint32_t str_len = sizeof tmp - 1 <= c->memsize - c->dslist[i] ? sizeof tmp - 1 : c->memsize - c->dslist[i];
            strncpy(tmp, (char*)(c->memory+c->dslist[i]), str_len);
            tmp[str_len] = '\0';
            printw(" %s", tmp);
        }
        ypos++;
    }
    if (i == 0) {
        mvprintw(ypos++, xpos, "  No vars selected");
    }

    mvprintw(ypos++, xpos, "[Breakpoints]");
    for (i=0; i<c->bpListLen; ++i) {
        mvprintw(ypos++, xpos, "  %d: [%08x] <%s>", i, c->bpList[i].addr, c->bpList[i].name ? c->bpList[i].name : "unknown");
    }
    if (i==0) {
        mvprintw(ypos++, xpos, "  No breakpoints defined");
    }
}

void SH4_DBG_Show(SH4Context_t *c)
{
    uint32_t i;
    int row, col;
    char lastError[256] = { '\0' };
    static char lastCommand[256] = { 's', '\0' };

    getmaxyx(stdscr,row,col);
    (void)col;

    if (c->debug_mode == 'r' || (c->globalbp != 0 && c->regs.PC != c->globalbp)) {
        for (i=0; i<c->bpListLen; ++i) {
            if (c->regs.PC == c->bpList[i].addr) {
                break;
            }
        }
        if (i == c->bpListLen) {
            attron(A_STANDOUT);
            move(row-1, 0);
            clrtoeol();
            printw("Running...");
            attroff(A_STANDOUT);
            refresh();
            return;
        }
    }

    c->globalbp = c->globalbp_next;
    c->globalbp_next = 0;

    for (;;) { /* Break only when continue or run commands are given */
        char command[256];
        uint32_t len = 0;
        int ch;

        clear();

        SH4_DBG_DumpRegs(c);
        SH4_DBG_DumpDisasm(c);
        SH4_DBG_DumpMem(c);
        SH4_DBG_DumpVars(c);
        refresh();

        attron(A_STANDOUT);
        mvprintw(row-1, 0, lastError);
        attroff(A_STANDOUT);
        attron(A_BOLD);
        mvprintw(row-2, 0, "Command: ");
        attroff(A_BOLD);
        refresh();

        command[0] = '\0';
        for (;;) {
            ch = getch();
            if (ch == KEY_ENTER || ch == '\n' || ch == '\r') {
                break;
            }
            if (ch == KEY_BACKSPACE || ch == 127) {
                if (len > 0) {
                    len--;
                }
            } else if (isprint(ch)) {
                command[len++] = ch;
            }
            if (len == sizeof(command)) {
                len--;
            }
            command[len] = '\0';
            move(row-2, 9);
            clrtoeol();
            printw("%s", command);
            refresh();
        }
        lastError[0] = '\0';

        if (command[0] == '\0') {
            if (lastCommand[0] == '\0') {
                continue;
            }
            strcpy(command, lastCommand);
        }
        if (strncmp(command, "s", 2)==0) {
            c->debug_mode = 's';
            strcpy(lastCommand, command);
            break;
        } else if (strncmp(command, "n", 2)==0) {
            c->debug_mode = 'n';
            strcpy(lastCommand, command);
            break;
        } else if (strcmp(command, "r")==0) {
            lastCommand[0] = '\0';
            c->debug_mode = 'r';
            c->globalbp = 0;
            c->globalbp_next = 0;
            break;
        } else if (len>2 && strncmp(command, "m ", 2)==0) {
            c->dispmem = strtol(command+2, NULL, 0);
        } else if (len>2 && strncmp(command, "d ", 2)==0) {
            if (c->d32listLen == sizeof c->d32list/sizeof *c->d32list) {
                strncpy(lastError, "32-bit display list is full", sizeof lastError);
            } else {
                long long tmp = strtoll(command+2, NULL, 0);
                if (tmp == LLONG_MIN || tmp == LLONG_MAX) {
                    strncpy(lastError, "Invalid parameter for argument", sizeof lastError);
                } else {
                    c->d32list[c->d32listLen++] = (uint32_t)tmp;
                }
            }
        } else if (len>3 && strncmp(command, "dw ", 3)==0) {
            if (c->d16listLen == sizeof c->d16list/sizeof *c->d16list) {
                strncpy(lastError, "16-bit display list is full", sizeof lastError);
            } else {
                long long tmp = strtoll(command+3, NULL, 0);
                if (tmp == LLONG_MIN || tmp == LLONG_MAX) {
                    strncpy(lastError, "Invalid parameter for argument", sizeof lastError);
                } else {
                    c->d16list[c->d16listLen++] = (uint32_t)tmp;
                }
            }
        } else if (len>3 && strncmp(command, "db ", 3)==0) {
            if (c->d8listLen == sizeof c->d8list/sizeof *c->d8list) {
                strncpy(lastError, "8-bit display list is full", sizeof lastError);
            } else {
                long long tmp = strtoll(command+3, NULL, 0);
                if (tmp == LLONG_MIN || tmp == LLONG_MAX) {
                    strncpy(lastError, "Invalid parameter for argument", sizeof lastError);
                } else {
                    c->d8list[c->d8listLen++] = (uint32_t)tmp;
                }
            }
        } else if (len>3 && strncmp(command, "ds ", 3)==0) {
            if (c->dslistLen == sizeof c->dslist/sizeof *c->dslist) {
                strncpy(lastError, "string display list is full", sizeof lastError);
            } else {
                long long tmp = strtoll(command+3, NULL, 0);
                if (tmp == LLONG_MIN || tmp == LLONG_MAX) {
                    strncpy(lastError, "Invalid parameter for argument", sizeof lastError);
                } else {
                    c->dslist[c->dslistLen++] = (uint32_t)tmp;
                }
            }
        } else if (len>3 && strncmp(command, "rd ", 3)==0) {
            uint8_t pos = strtol(command+3, NULL, 0);
            if (pos >= c->d32listLen) {
                strncpy(lastError, "Invalid position for 32-bit list", sizeof lastError);
            } else {
                memmove(c->d32list + pos, c->d32list + pos + 1, (sizeof *c->d32list)*(c->d32listLen - pos - 1));
                c->d32listLen--;
            }
        } else if (len>4 && strncmp(command, "rdw ", 4)==0) {
            uint8_t pos = strtol(command+4, NULL, 0);
            if (pos >= c->d16listLen) {
                strncpy(lastError, "Invalid position for 16-bit list", sizeof lastError);
            } else {
                memmove(c->d16list + pos, c->d16list + pos + 1, (sizeof *c->d16list)*(c->d16listLen - pos - 1));
                c->d16listLen--;
            }
        } else if (len>4 && strncmp(command, "rdb ", 4)==0) {
            uint8_t pos = strtol(command+4, NULL, 0);
            if (pos >= c->d8listLen) {
                strncpy(lastError, "Invalid position for 8-bit list", sizeof lastError);
            } else {
                memmove(c->d8list + pos, c->d8list + pos + 1, (sizeof *c->d8list)*(c->d8listLen - pos - 1));
                c->d8listLen--;
            }
        } else if (len>4 && strncmp(command, "rds ", 4)==0) {
            uint8_t pos = strtol(command+4, NULL, 0);
            if (pos >= c->dslistLen) {
                strncpy(lastError, "Invalid position for string var list", sizeof lastError);
            } else {
                memmove(c->dslist + pos, c->dslist + pos + 1, (sizeof *c->dslist)*(c->dslistLen - pos - 1));
                c->dslistLen--;
            }
        } else if (len>2 && strncmp(command, "b ", 2)==0) {
            if (c->bpListLen == sizeof c->bpList/sizeof *c->bpList) {
                strncpy(lastError, "Maximum number of breakpoints reached", sizeof lastError);
            } else {
                char *endptr;
                long long tmp = strtoll(command+2, &endptr, 0);
                if (endptr==(command+2)) {
                    /* Check function name */
                    for (i=0; i<c->symbTableLen; ++i) {
                        if (strcmp(command+2, c->symbTable[i].name) == 0) {
                            c->bpList[c->bpListLen].addr = (uint32_t)c->symbTable[i].address;
                            c->bpList[c->bpListLen].name = c->symbTable[i].name;
                            c->bpListLen++;
                            break;
                        }
                    }
                    if (i == c->symbTableLen) {
                        sprintf(lastError, "Symbol name not found: %s", command+2);
                    }
                } else if (endptr == (command + strlen(command))) {
                    /* Check function address */
                    for (i=0; i<c->symbTableLen; ++i) {
                        if (tmp == c->symbTable[i].address) {
                            c->bpList[c->bpListLen].addr = (uint32_t)c->symbTable[i].address;
                            c->bpList[c->bpListLen].name = c->symbTable[i].name;
                            c->bpListLen++;
                            break;
                        }
                    }
                    if (i == c->symbTableLen) {
                        c->bpList[c->bpListLen].addr = (uint32_t)tmp;
                        c->bpList[c->bpListLen].name = NULL;
                        c->bpListLen++;
                    }
                } else {
                    sprintf(lastError, "Invalid parameter for argument: %s", command+2);
                }
            }
        } else if (len>3 && strncmp(command, "rb ", 3)==0) {
            uint8_t pos = strtol(command+3, NULL, 0);
            if (pos >= c->bpListLen) {
                strncpy(lastError, "Invalid position for breakpoint list", sizeof lastError);
            } else {
                memmove(c->bpList + pos, c->bpList + pos + 1, (sizeof *c->bpList)*(c->bpListLen - pos - 1));
                c->bpListLen--;
            }
        }
    }
}

void SH4_DBG_Finalize(SH4Context_t *c)
{
    endwin();
}
