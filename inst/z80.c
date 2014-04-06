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
  exit(0);
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

int emulate_instruction(z80 *cpu, MEMORY mem) {
  uint8_t n;
  uint16_t nn;
  int8_t d;
  
  uint8_t x,y,xy;
  
  // NOTE: This is specific to MEMORY being uint8_t and formatted as an array
  uint8_t *unimpl = mem + cpu->pc;
  
#define UPDATE_FLAGS_ADD8 cpu->af.lsb = COMBINE_FLAGS(xy<x,0,(y^x^0x80)&(y^xy)&0x80,(xy&0x0F)<(x&0x0F),!xy,xy&0x80)
#define UPDATE_FLAGS_ADC8 if(cpu->af.lsb&FLAG_C) cpu->af.lsb = COMBINE_FLAGS(xy<=x,0,(y^x^0x80)&(y^xy)&0x80,(xy&0x0F)<=(x&0x0F),!xy,xy&0x80); else UPDATE_FLAGS_ADD8
#define UPDATE_FLAGS_SUB8 cpu->af.lsb = COMBINE_FLAGS(xy>x,1,(y^x^0x80)&(y^xy)&0x80,(xy&0x0F)>(x&0x0F),!xy,xy&0x80)
#define UPDATE_FLAGS_SBC8 if(cpu->af.lsb&FLAG_C) cpu->af.lsb = COMBINE_FLAGS(xy>=x,1,(y^x^0x80)&(y^xy)&0x80,(xy&0x0F)>=(x&0x0F),!xy,xy&0x80); else UPDATE_FLAGS_SUB8

#define UPDATE_FLAGS_BIT8(v) cpu->af.lsb = COMBINE_FLAGS(0,0,(y^x^0x80)&(y^xy)&0x80,v,!xy,xy&0x80)
  
  //http://stackoverflow.com/a/199668
  //http://stackoverflow.com/a/17750382
  
  switch(mem_read8(mem, cpu->pc++)) {
#include "z80_instructions.h"
  default:
    return 0;
  }
}
