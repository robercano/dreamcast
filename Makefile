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

all: createdirs $(TOOLSDIR)/sh4opgen

createdirs:
	mkdir -p $(OBJDIR)
	mkdir -p $(TOOLSDIR)

$(TOOLSDIR)/sh4opgen: $(SH4OPGEN_OBJ)
	$(CXX) -o $@ $^

clean:
	rm -rf $(OBJDIR)
	rm -rf $(TOOLSDIR)

obj/%.o: src/%.c
	$(CC) -o $@ -c $<

obj/%.o: src/%.cpp
	$(CXX) -o $@ -c $<

.PHONY: createdirs
