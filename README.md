# Dreamcast Emulator
Main goal of this project is to create a Dreamcast emulator supporting dynarec, HLE
and, perhaps, static binary recompilation. The main target of this is the game
Soul Calibur, which is one of the best fight games ever developed.

## Goal and approach
The short term goal stands on creating an efficient sh7750h emulator. To do
so the following approach is taken:

- Create sh7750h disassembler and compare this with public disassemblers
- Implement the sh775h interpreter and cross-check functionality using
  programs that do not use system calls, hardware, etc... just basic
  data processing with program input/output
- Refactor the interpreter to apply dynamic recompilation techniques
- Implement HLE to execute sh7750h applications that make use of the libc
  so they run under Mac/Linux using high level resources like syscalls,
  printf, memory allocation, etc...

From that point on the real Dreamcast development would start trying to reuse
the emulator for Dreamcast emulation. More information have to be gathered
first before tackling that task.

# How to compile it
For now compilation is quite simple:

    $ make

That should generate the opcode generation tool (sh4opgen) and the disassembler
(sh4disassembler).

To clean all the generated artifacts:

    $ make clean

# Opcode generation tool
The opcode generation tools is a helper tool used to generate the following files:

- sh4opcode.h
- sh4opcodeLUT.c
- sh4opcodedis.c
- sh4opcodeemu.c

To generate those files the file sh4opcode.def is used. That files has the definition
of all opcodes for the sh7750h. Please check the file for more information on the
format. Then the tool takes the file and generates a lookup table to decode any
16-bit opcode into the corresponding processing function.

There are 2 lookup tables, one for disassembling and the other one for interpreting.
The disassembler tool makes use of this tables to perform its task.

# Disassembler
The disassembler, at this stage, takes a binary files with 16-bit opcodes and decodes
them, printing out the disassembler mnemonics. In the future it will support ELF
format and smarter static code parsing to determine which parts are code and which
ones data.
