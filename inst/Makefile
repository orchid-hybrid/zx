all: disassembler

clean:
	rm -f opcodes.h
	rm -f disassembler

disassembler: disassembler.c opcodes.h
	gcc disassembler.c -o disassembler

opcodes.h: dis.scm inst.scm
	csi -q dis.scm all > opcodes.h

test: tmp test8 test16 testexch testarith
	echo "all tests passed!"

tmp:
	mkdir -p tmp

test8:
	csi -q dis.scm 8-bit-load-instructions > tmp/8_bit_load_instructions.h
	diff tmp/8_bit_load_instructions.h tests/8_bit_load_instructions.h
	echo "passed!"

test16:
	csi -q dis.scm 16-bit-load-instructions > tmp/16_bit_load_instructions.h
	diff tmp/16_bit_load_instructions.h tests/16_bit_load_instructions.h
	echo "passed!"

testexch:
	csi -q dis.scm exchange-block-transfer-search-instructions > tmp/exchange_block_transfer_search_instructions.h
	diff tmp/exchange_block_transfer_search_instructions.h tests/exchange_block_transfer_search_instructions.h
	echo "passed!"

testarith:
	csi -q dis.scm 8-bit-arithmetic-instructions > tmp/8_bit_arithmetic_instructions.h
	diff tmp/8_bit_arithmetic_instructions.h tests/8_bit_arithmetic_instructions.h
	echo "passed!"
