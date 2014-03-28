all: disassembler

clean:
	rm -f opcodes.h
	rm -f disassembler

disassembler: disassembler.c opcodes.h
	gcc disassembler.c -o disassembler

opcodes.h: dis.scm inst.scm
	csi -q dis.scm all > opcodes.h

test:
	cd tests; make
