#
# Main makefile of the Dreamcast emulator project
#
# @author Roberto Cano <roberto dot cano at google mail>
#
CC=gcc
CXX=g++
MACHINE=$(shell uname)

# Directories
OBJDIR := obj
TOOLSDIR := tools
SRCDIR := src

# General flags
CFLAGS = -Iinclude -Wno-format-extra-args -Wno-format
CXXFLAGS = -Iinclude -Wno-format-extra-args -Wno-format

# SH4 opcode generation tool
SH4OPGEN_SRC := sh4opgen.c
SH4OPGEN_OBJ := $(patsubst %.c, obj/%.o, $(SH4OPGEN_SRC))

# SH4 interpreter tool
SH4INTERP_SRC := sh4interpreter.c sh4core.c sh4mmu.c sh4log.c sh4elf.c sh4opcodeemuLUT.c sh4opcodedisLUT.c
SH4INTERP_OBJ := $(patsubst %.c, obj/%.o, $(SH4INTERP_SRC))

all: createdirs $(TOOLSDIR)/sh4interpreter

sh4opgen: $(TOOLSDIR)/sh4opgen

createdirs:
	mkdir -p $(OBJDIR)
	mkdir -p $(TOOLSDIR)

$(TOOLSDIR)/sh4opgen: $(SH4OPGEN_OBJ)
ifeq ($(MACHINE),Linux)
$(TOOLSDIR)/sh4interpreter: CFLAGS += -Ilib/linux/
$(TOOLSDIR)/sh4interpreter: LDFLAGS += lib/linux/libbfd.a lib/linux/libiberty.a -lz
else
$(TOOLSDIR)/sh4interpreter: CFLAGS += -Ilib/osx/
$(TOOLSDIR)/sh4interpreter: LDFLAGS += -Llib/osx/ -lbfd lib/osx/libiberty.a
endif
$(TOOLSDIR)/sh4interpreter: $(SH4INTERP_OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(TOOLSDIR)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: createdirs sh4opgen
