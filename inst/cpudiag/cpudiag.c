#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "z80.h"

uint8_t mem[0xFFFF];
uint8_t tmp;

uint8_t mem_read8(MEMORY mem, uint16_t addr) {
  if(addr >= 0xFFFF) {
    puts("OOB RAM READ 8\n");
    exit(0);
  }
  return mem[addr];
}
int8_t mem_read8_signed(MEMORY mem, uint16_t addr) { tmp = mem_read8(mem, addr); return *(int8_t*)&tmp; }
uint16_t mem_read16(MEMORY mem, uint16_t addr) {
    if(addr >= 0xFFFF-1) {
    puts("OOB RAM READ 16\n");
      exit(0);
    }
    return mem[addr] | mem[addr+1] << 8;
}
void mem_write8(MEMORY mem, uint16_t addr, uint8_t value) {
  if(addr >= 0xFFFF) {
    puts("OOB RAM WRITE\n");
    exit(0);
  }
  if(addr >= 0x2000) {
    mem[addr] = value;
  }
}
void mem_write16(MEMORY mem, uint16_t addr, uint16_t value) { mem_write8(mem, addr, value & 0xFF); mem_write8(mem, addr+1, value >> 8); }

int main(int argc, char **argv) {
  FILE *fptr;
  
  fptr = fopen("cpudiag.bin", "rb");
  if(!fptr) { puts("cpudiag.bin not found"); return EXIT_FAILURE; }
  if(fread(mem+0x100, 1453, 1, fptr) != 1) { puts("h"); return EXIT_FAILURE; }
  fclose(fptr);
  
  {
    z80 cpu;
    int instructions = 0;
    int t = 0;
    
    int t_cycles;
    
    initialize_cpu(&cpu);
    cpu.pc = 0x100;
    //mem[368] = 0x7;
    // skip DAA
    mem[0x59c] = 0xc3; //JMP
    mem[0x59d] = 0xc2;
    mem[0x59e] = 0x05;
 
    while(1) {
      int i;
      
	trace_cpu_state(&cpu);
	// todo align it to 0x10
	for(i = 0; i < 0x20; i+=2) {
	  if(!(i%0x10)) printf("\n0x%.4x: ", cpu.sp-0x10+i);
	  printf("%04X ", *(uint16_t*)(mem+cpu.sp-0x10+i));
	}
	puts("\n");
	printf("0x%.4x: ", cpu.pc); disassemble_instruction(8, mem+cpu.pc);
	puts("\n");
	
	t_cycles = emulate_instruction(&cpu, mem);
	instructions++;
	if(t_cycles < 0) {
	  // BAD NEWS
	  puts("BAD NEWS");
	  break;
	}
	t += t_cycles;
	
	if(mem[cpu.pc] == 0x76) break; // HALT
    }
  }
  
  return EXIT_SUCCESS;
}
