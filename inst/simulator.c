#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "z80.h"

uint8_t mem[0x10000];
uint8_t mem_read8(MEMORY mem, uint16_t addr) { return mem[addr]; }
uint16_t mem_read16(MEMORY mem, uint16_t addr) { return mem[addr] | mem[addr+1] << 8; }
void mem_write8(MEMORY mem, uint16_t addr, uint8_t value) {
  // TODO: make an example ROM and RAM
  mem[addr] = value;
}
void mem_write16(MEMORY mem, uint16_t addr, uint16_t value) { mem_write8(mem, addr, value & 0xFF); mem_write8(mem, addr+1, value >> 8); }

int main(int argc, char **argv) {
  FILE *fptr;
  long size;
  uint8_t *data;
  
  if(argc != 2 && argc != 3) {
    puts("usage: z80 <file.bin> [$offset]");
    return EXIT_FAILURE;
  }
  
  fptr = fopen(argv[1], "rb");
  if(!fptr) {
    puts("file not file");
    return EXIT_FAILURE;
  }
  fseek(fptr, 0, SEEK_END);
  size = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  data = malloc(size);
  fread(data, size, 1, fptr);
  fclose(fptr);
  
  if(argc == 3) {
    size -= strtol(argv[2], NULL, 16);
    data += strtol(argv[2], NULL, 16);
  }
  
  {
    z80 cpu;
    
    initialize_cpu(&cpu);
    
    int result, bytes;
    bytes = 0;
    printf("0x%.4x: ", bytes);
    disassemble_instruction(size, data);
    while((result = emulate_instruction(&cpu, NULL, size, data)) > 0) {
      size -= result;
      data += result;
      bytes += result;
      trace_cpu_state(&cpu);
      //
      printf("0x%.4x: ", bytes);
      disassemble_instruction(size, data);
    }
    printf("emulated %d bytes\n", bytes);
  }
  
  return EXIT_SUCCESS;
}
