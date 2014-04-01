#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <SDL/SDL.h>

#include "z80.h"

// http://www.computerarcheology.com/wiki/wiki/Arcade/SpaceInvaders/Hardware

uint8_t mem[0x4000];
uint8_t tmp;

// 0000-1FFF 8K ROM
// 2000-23FF 1K RAM
// 2400-3FFF 7K Video RAM
// 4000- RAM mirror 

uint8_t mem_read8(MEMORY mem, uint16_t addr) {
  if(addr >= 0x4000) {
    puts("RAM MIRROR READ\n");
    exit(0);
  }
  return mem[addr];
}
int8_t mem_read8_signed(MEMORY mem, uint16_t addr) { tmp = mem_read8(mem, addr); return *(int8_t*)&tmp; }
uint16_t mem_read16(MEMORY mem, uint16_t addr) { return mem[addr] | mem[addr+1] << 8; }
void mem_write8(MEMORY mem, uint16_t addr, uint8_t value) {
  if(addr >= 0x4000) {
    puts("RAM MIRROR WRITE\n");
    exit(0);
  }
  if(addr >= 0x2000) {
    mem[addr] = value;
  }
}
void mem_write16(MEMORY mem, uint16_t addr, uint16_t value) { mem_write8(mem, addr, value & 0xFF); mem_write8(mem, addr+1, value >> 8); }

int main(int argc, char **argv) {
  FILE *fptr;
  
  // invaders.h 0000-07FF
  // invaders.g 0800-0FFF
  // invaders.f 1000-17FF
  // invaders.e 1800-1FFF 
  
  fptr = fopen("invaders.h", "rb");
  if(!fptr) { puts("invaders.h not found"); return EXIT_FAILURE; }
  if(fread(mem+0x0000, 0x0800, 1, fptr) != 1) { puts("h"); return EXIT_FAILURE; }
  fclose(fptr);
  
  fptr = fopen("invaders.g", "rb");
  if(!fptr) { puts("invaders.g not found"); return EXIT_FAILURE; }
  if(fread(mem+0x0800, 0x0800, 1, fptr) != 1) { puts("g"); return EXIT_FAILURE; }
  fclose(fptr);
  
  fptr = fopen("invaders.f", "rb");
  if(!fptr) { puts("invaders.f not found"); return EXIT_FAILURE; }
  if(fread(mem+0x1000, 0x0800, 1, fptr) != 1) { puts("f"); return EXIT_FAILURE; }
  fclose(fptr);
  
  fptr = fopen("invaders.e", "rb");
  if(!fptr) { puts("invaders.e not found"); return EXIT_FAILURE; }
  if(fread(mem+0x1800, 0x0800, 1, fptr) != 1) { puts("e"); return EXIT_FAILURE; }
  fclose(fptr);
  
  {
    z80 cpu;
    int  instructions= 0;
    
    initialize_cpu(&cpu);
    
    printf("0x%.4x: ", cpu.pc);
    disassemble_instruction(8, mem+cpu.pc);
    while(emulate_instruction(&cpu, mem) > 0) {
      trace_cpu_state(&cpu);
      //
      printf("0x%.4x: ", cpu.pc);
      disassemble_instruction(8, mem+cpu.pc);
      if(mem[cpu.pc] == 0x76) break; // HALT
      
      instructions++;
      printf("%d !!\n", instructions);
      if(instructions == 42038) {
      break;
      }
    }
    //printf("emulated %d bytes\n", );
  }
  
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) {
    printf("Cannot initialize SDL\n");
    exit(0);
  }
  SDL_Surface *screen = SDL_SetVideoMode(224, 256, 8, SDL_DOUBLEBUF);
  SDL_LockSurface(screen);
  {
    uint8_t *screenPtr = screen->pixels;
    
    int b;
    int vramPtr;
    int x,y;
    
    y = 256-1;
    x = 0;
    for (vramPtr = 0; vramPtr < 0x4000 - 0x2400; vramPtr++) { 
      for (b=0;b<8;b++) {
	screenPtr[224*y + x] = ((mem[0x2400 + vramPtr] >> b)&1) ? 0xFF : 0x00;
	y--;
	if(y < 0) {
	  y = 256-1;
	  x++;
	}
      }
    }
  }
  SDL_UnlockSurface(screen);
  SDL_Flip(screen);
  SDL_Event ev;
  while(1){
  while (SDL_PollEvent(&ev)) {
    switch (ev.type) {
    case SDL_QUIT:
      exit(0);
      break;
    default:
      break;
    }
  }
  }
  
  return EXIT_SUCCESS;
}
