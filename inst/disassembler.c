#include <stdio.h>
#include <stdlib.h>

int disassemble_instruction(long size, unsigned char *data) {
  unsigned char n;
  unsigned int nn;
  int d;
  
  switch(data[0]) {
  #include "opcodes.h"
  default:
    return 0;
  }
}

int main(int argc, char **argv) {
  FILE *fptr;
  long size;
  unsigned char *data;
  
  if(argc != 2) {
    puts("usage: disassemble <file.bin>");
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
  
  // since wla-dx adds some header stuff
  size -= 0x3E;
  data += 0x3E;
  
  {
    int result, bytes;
    bytes = 0;
    printf("0x%.4x: ", bytes);
    while((result = disassemble_instruction(size, data)) > 0) {
      size -= result;
      data += result;
      bytes += result;
      printf("0x%.4x: ", bytes);
    }
    printf("disassembled %d bytes\n", bytes);
  }
  
  return EXIT_SUCCESS;
}
