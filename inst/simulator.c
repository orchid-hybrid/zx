#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "z80.h"

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
    while((result = emulate_instruction(&cpu, size, data)) > 0) {
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
