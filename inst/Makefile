all: disassembler simulator

clean:
	rm -f opcodes.h
	rm -f z80_instructions.h
	rm -f disassembler
	rm -f simulator

disassembler: disassembler.c opcodes.h
	gcc disassembler.c -o disassembler

opcodes.h: dis.scm inst.scm
	csi -q dis.scm . . all > opcodes.h

simulator: simulator.o z80.o
	gcc simulator.o z80.o -o simulator

simulator.o: simulator.c z80.h z80.c
	gcc -g -c simulator.c

z80.o: z80.c z80.h z80_instructions.h
	gcc -g -c z80.c

z80_instructions.h: inst.scm impl.scm sim.scm
	csi -q sim.scm - - all > z80_instructions.h

test:
	cd tests; make
