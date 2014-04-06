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
  
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) {
    printf("Cannot initialize SDL\n");
    exit(0);
  }
  SDL_Surface *screen = SDL_SetVideoMode(224, 256, 8, SDL_DOUBLEBUF);
  
  {
    z80 cpu;
    int instructions = 0;
    int t = 0;
    
    int t_cycles;
    
    initialize_cpu(&cpu);
    
    // The CPU runs at 2MHz
    // We trigger interrupts every half frame: 2*60Hz
    
    Uint32 t1, t2;
    
    int vblank = 1;
    
    float speedup = 1/3.0;
    
    while(1) {
      
#define TWOMEGA 2000000
      
    t1 = SDL_GetTicks();
    t = 0;
    while(t < (TWOMEGA/120)*speedup) {
    //while((SDL_GetTicks() - t1) < (1000/120)) {
      
      // printf("0x%.4x: ", cpu.pc); disassemble_instruction(8, mem+cpu.pc); trace_cpu_state(&cpu);
      
      // debugging jump out of rom bug
      if(instructions >= 2358034) {
	printf("0x%.4x: ", cpu.pc); disassemble_instruction(8, mem+cpu.pc); trace_cpu_state(&cpu);
      }
      
      t_cycles = emulate_instruction(&cpu, mem);
      instructions++;
      if(t_cycles < 0) {
	// BAD NEWS
	puts("BAD NEWS");
	break;
      }
      t += t_cycles;
      
      if(cpu.pc >= 0x2000) {
	printf("left ROM at %d\n", instructions);
      }
      
      if(mem[cpu.pc] == 0x76) break; // HALT
      
      //if(instructions == 2500000) {
      //	break;
      //}
    }
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
      switch (ev.type) {
      case SDL_QUIT:
	exit(0);
	break;
      default:
	break;
      }
    }
    if(SDL_GetTicks() - t1 < (1000/120)*speedup) {
      SDL_Delay((1000/120)*speedup - (SDL_GetTicks() - t1));
    }
    else {
      puts("TOOK TOO LONG!!!");
    }
    
    vblank = !vblank;
    if(!vblank) {
      
      cpu.sp -= 2;
      mem_write16(mem, cpu.sp, cpu.pc);
      cpu.pc = 0x8;
      
      continue;
    }
    else {
      cpu.sp -= 2;
      mem_write16(mem, cpu.sp, cpu.pc);
      cpu.pc = 0x10;
    }
  
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
  
    }
  }
  
  /*
  */
  
  return EXIT_SUCCESS;
}
