all: tmp test8 test16 testexch testarith testgeneral testarith16 testjump testcallret testio
	echo "all tests passed!"

tmp:
	mkdir -p tmp

test8:
	csi -q -I .. ../dis.scm 8-bit-load-instructions > tmp/8_bit_load_instructions.h
	diff tmp/8_bit_load_instructions.h headers/8_bit_load_instructions.h
	echo "passed!"

test16:
	csi -q -I .. ../dis.scm 16-bit-load-instructions > tmp/16_bit_load_instructions.h
	diff tmp/16_bit_load_instructions.h headers/16_bit_load_instructions.h
	echo "passed!"

testexch:
	csi -q -I .. ../dis.scm exchange-block-transfer-search-instructions > tmp/exchange_block_transfer_search_instructions.h
	diff tmp/exchange_block_transfer_search_instructions.h headers/exchange_block_transfer_search_instructions.h
	echo "passed!"

testarith:
	csi -q -I .. ../dis.scm 8-bit-arithmetic-instructions > tmp/8_bit_arithmetic_instructions.h
	diff tmp/8_bit_arithmetic_instructions.h headers/8_bit_arithmetic_instructions.h
	echo "passed!"

testgeneral:
	csi -q -I .. ../dis.scm general-purpose-control-instructions > tmp/general_purpose_control_instructions.h
	diff tmp/general_purpose_control_instructions.h headers/general_purpose_control_instructions.h
	echo "passed!"

testarith16:
	csi -q -I .. ../dis.scm 16-bit-arithmetic-instructions > tmp/16_bit_arithmetic_instructions.h
	diff tmp/16_bit_arithmetic_instructions.h headers/16_bit_arithmetic_instructions.h
	echo "passed!"

#testrotshf:
#	cd ..
#	csi -q -I .. ../dis.scm rotate-and-shift-instructions > tmp/rotate_and_shift_instructions.h
#	diff tmp/rotate_and_shift_instructions.h headers/rotate_and_shift_instructions.h
#	echo "passed!"

testjump:
	csi -q -I .. ../dis.scm jump-instructions > tmp/jump_instructions.h
	diff tmp/jump_instructions.h headers/jump_instructions.h
	echo "passed!"

testcallret:
	csi -q -I .. ../dis.scm call-and-return-instructions > tmp/call_and_return_instructions.h
	diff tmp/call_and_return_instructions.h headers/call_and_return_instructions.h
	echo "passed!"

testio:
	csi -q -I .. ../dis.scm input-output-instructions > tmp/input_output_instructions.h
	diff tmp/input_output_instructions.h headers/input_output_instructions.h
	echo "passed!"
