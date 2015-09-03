#
# Main makefile of the Dreamcast emulator project
#
# @author Roberto Cano <roberto dot cano at google mail>
#
CC=gcc
CXX=g++

# Directories
OBJDIR := obj
TOOLSDIR := tools
SRCDIR := src

# SH4 opcode generation tool
SH4OPGEN_SRC := sh4opgen.c
SH4OPGEN_OBJ := $(patsubst %.c, obj/%.o, $(SH4OPGEN_SRC))

# SH4 disassembler tool
SH4DISASM_SRC := sh4disassembler.c sh4opcodedisLUT.c sh4opcodedis.c
SH4DISASM_OBJ := $(patsubst %.c, obj/%.o, $(SH4DISASM_SRC))

# SH4 interpreter tool
SH4INTERP_SRC := sh4interpreter.c sh4opcodeemuLUT.c sh4opcodedisLUT.c sh4opcodeemu.c sh4opcodedis.c
SH4INTERP_OBJ := $(patsubst %.c, obj/%.o, $(SH4INTERP_SRC))

all: createdirs $(TOOLSDIR)/sh4opgen $(TOOLSDIR)/sh4disassembler $(TOOLSDIR)/sh4interpreter

createdirs:
	mkdir -p $(OBJDIR)
	mkdir -p $(TOOLSDIR)

$(TOOLSDIR)/sh4opgen: $(SH4OPGEN_OBJ)
	$(CXX) -o $@ $^

$(TOOLSDIR)/sh4disassembler: $(SH4DISASM_OBJ)
	$(CXX) -o $@ $^

$(TOOLSDIR)/sh4interpreter: $(SH4INTERP_OBJ)
	$(CXX) -o $@ $^

obj/sh4opcodeLUT.o: .FORCE
	$(CC) $(CFLAGS) -o $@ -c src/sh4opcodeLUT.c
.FORCE:

clean:
	rm -rf $(OBJDIR)
	rm -rf $(TOOLSDIR)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: createdirs .FORCE
