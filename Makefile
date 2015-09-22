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
DEPDIR := .deps

$(shell mkdir -p $(OBJDIR) >/dev/null)
$(shell mkdir -p $(TOOLSDIR) >/dev/null)
$(shell mkdir -p $(SRCDIR) >/dev/null)
$(shell mkdir -p $(DEPDIR) >/dev/null)

# General flags
CFLAGS = -Iinclude -Wall -Werror -Wno-unused-variable -O3
CXXFLAGS = -Iinclude -Wall -Werror -Wno-unused-variable -O3
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

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

all: $(TOOLSDIR)/sh4interpreter
	@echo All done!

sh4opgen: $(TOOLSDIR)/sh4opgen

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
	@rm -rf $(DEPDIR)
	@echo done!

obj/%.o: src/%.c $(DEPDIR)/%.d
	@$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<
	 mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d

obj/%.o: src/%.cpp $(DEPDIR)/%.d
	@$(CXX) $(DEPFLAGS) $(CXXFLAGS) -o $@ -c $<
	 mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d

$(DEPDIR)/%.d: ;

-include $(patsubst %,$(DEPDIR)/%.d,$(basename $(SH4INTERP_SRC)))

.PHONY: createdirs sh4opgen BuildInterpreter BuildOpgen
