inst.scm defines the CPUs instruction set

`csi dis.scm` generates the files opcodes.h

`gcc disassembler.c -o disassembler` compiles the disassembler

`wla-z80 -l lds.s` in test/ is used to assemble a file to disassemble to test the 8 bit load instructions

Skips required to test disassembly

* `./disassembler tests/arith16.lib 3A`
* `./disassembler tests/callret.lib 38`
* `./disassembler tests/io.lib 33`
* `./disassembler tests/lib/shftrot.s 3C`


TODO:

* switch the simulator to use the program counter for its execution
