inst.scm defines the CPUs instruction set

`csi dis.scm` generates the files opcodes.h

`gcc disassembler.c -o disassembler` compiles the disassembler

`wla-z80 -l lds.s` in test/ is used to assemble a file to disassemble to test the 8 bit load instructions