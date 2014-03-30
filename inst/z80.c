#include <stdint.h>
#include <stdio.h>

#include "z80.h"

void initialize_cpu(z80 *cpu) {
  *cpu = (z80){
    .af.pair = 0, .bc.pair = 0, .de.pair = 0, .hl.pair = 0,
    .afp.pair = 0, .bcp.pair = 0, .dep.pair = 0, .hlp.pair = 0,
    .i = 0, .r = 0,
    .ix = 0, .iy = 0, .sp = 0, .pc = 0,
    .iff1 = false, .iff2 = false
  };
}

void trace_cpu_state(z80 *cpu) {
  printf("SP  PC  IX  IY : %04X %04X %04X %04X" "\n"
	 "AF  BC  DE  HL : %04X %04X %04X %04X" "\n"
	 "AF' BC' DE' HL': %04X %04X %04X %04X" "\n"
	 "I R IFF1 IFF2  : %02X   %02X   %1d    %1d" "\n"
	 "\n",
	 cpu->sp, cpu->pc, cpu->ix, cpu->iy,
	 cpu->af.pair, cpu->bc.pair, cpu->de.pair, cpu->hl.pair,
	 cpu->afp.pair, cpu->bcp.pair, cpu->dep.pair, cpu->hlp.pair,
	 cpu->i, cpu->r, cpu->iff1, cpu->iff2
	 );
}

int unimplemented_instruction(long size, uint8_t *data) {
  printf("UNIMPLEMENTED OPCODE [0x%02X]\n", data[0]);
  disassemble_instruction(size, data);
}

int disassemble_instruction(long size, uint8_t *data) {
  unsigned char n;
  unsigned int nn;
  int d;
  
  switch(data[0]) {
  #include "opcodes.h"
  default:
    return 0;
  }
}

int emulate_instruction(z80 *cpu, MEMORY mem, long size, uint8_t *data) {
  uint8_t n;
  uint16_t nn;
  int8_t d;
  
  switch(data[0]) {
#include "z80_instructions.h"
  default:
    return 0;
  }
}
