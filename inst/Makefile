all: disassembler

clean:
	rm -f opcodes.h
	rm -f disassembler

disassembler: disassembler.c opcodes.h
	gcc disassembler.c -o disassembler

opcodes.h: dis.scm inst.scm
	csi -q dis.scm all > opcodes.h

test: tmp test8 test16 testexch testarith testgeneral testarith16 testjump testcallret testio
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

testgeneral:
	csi -q dis.scm general-purpose-control-instructions > tmp/general_purpose_control_instructions.h
	diff tmp/general_purpose_control_instructions.h tests/general_purpose_control_instructions.h
	echo "passed!"

testarith16:
	csi -q dis.scm 16-bit-arithmetic-instructions > tmp/16_bit_arithmetic_instructions.h
	diff tmp/16_bit_arithmetic_instructions.h tests/16_bit_arithmetic_instructions.h
	echo "passed!"

#testrotshf:
#	csi -q dis.scm rotate-and-shift-instructions > tmp/rotate_and_shift_instructions.h
#	diff tmp/rotate_and_shift_instructions.h tests/rotate_and_shift_instructions.h
#	echo "passed!"

testjump:
	csi -q dis.scm jump-instructions > tmp/jump_instructions.h
	diff tmp/jump_instructions.h tests/jump_instructions.h
	echo "passed!"

testcallret:
	csi -q dis.scm call-and-return-instructions > tmp/call_and_return_instructions.h
	diff tmp/call_and_return_instructions.h tests/call_and_return_instructions.h
	echo "passed!"

testio:
	csi -q dis.scm input-output-instructions > tmp/input_output_instructions.h
	diff tmp/input_output_instructions.h tests/input_output_instructions.h
	echo "passed!"
