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
CFLAGS = -Iinclude -Wall -Werror -Wno-unused-variable -O3
CXXFLAGS = -Iinclude -Wall -Werror -Wno-unused-variable -O3

# SH4 opcode generation tool
SH4OPGEN_SRC := sh4opgen.c
SH4OPGEN_OBJ := $(patsubst %.c, obj/%.o, $(SH4OPGEN_SRC))

# SH4 interpreter tool
SH4INTERP_SRC := sh4interpreter.c sh4core.c sh4mmu.c sh4log.c \
	             sh4elf.c sh4opcodeemuLUT.c sh4opcodedisLUT.c \
				 sh4opcodeemu.c sh4opcodedis.c sh4debugger.c
SH4INTERP_OBJ := $(patsubst %.c, obj/%.o, $(SH4INTERP_SRC))

# Machine selection
ifeq ($(shell uname),Linux)
MACHINE := linux
else
MACHINE := osx
endif

all: createdirs $(TOOLSDIR)/sh4interpreter
	@echo All done!

sh4opgen: $(TOOLSDIR)/sh4opgen

createdirs:
	@echo -n - Creating directories...
	@mkdir -p $(OBJDIR)
	@mkdir -p $(TOOLSDIR)
	@echo done!

BuildInterpreter:
	@echo -n - Building interpreter...

BuildOpgen:
	@echo -n - Building opcode generator...

$(TOOLSDIR)/sh4opgen: BuildOpgen $(SH4OPGEN_OBJ)
$(TOOLSDIR)/sh4interpreter: CFLAGS += -Ilib/$(MACHINE)/
$(TOOLSDIR)/sh4interpreter: LDFLAGS += lib/$(MACHINE)/libbfd.a lib/$(MACHINE)/libiberty.a -lz -lncurses
$(TOOLSDIR)/sh4interpreter: BuildInterpreter $(SH4INTERP_OBJ)
	@$(CXX) -o $@ $(filter-out $<,$^) $(LDFLAGS)
	@echo done!

clean:
	@echo -n Cleaning everything...
	@rm -rf $(OBJDIR)
	@rm -rf $(TOOLSDIR)
	@echo done!

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

obj/%.o: src/%.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: createdirs sh4opgen BuildInterpreter BuildOpgen
