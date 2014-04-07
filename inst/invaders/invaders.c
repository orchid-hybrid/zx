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
    puts("RAM MIRROR READ 8\n");
    exit(0);
  }
  return mem[addr];
}
int8_t mem_read8_signed(MEMORY mem, uint16_t addr) { tmp = mem_read8(mem, addr); return *(int8_t*)&tmp; }
uint16_t mem_read16(MEMORY mem, uint16_t addr) {
    if(addr >= 0x4000-1) {
    puts("RAM MIRROR READ 16\n");
      exit(0);
    }
    return mem[addr] | mem[addr+1] << 8;
}
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
    
    float speedup = 1;//1/3.0;
    
    // more debugging the ROM jumpout
    int inst_counts[0xFF] = {0};
    
    while(1) {
      
#define TWOMEGA 2000000
      
    t1 = SDL_GetTicks();
    t = 0;
    while(t < (TWOMEGA/120)) {
    //while((SDL_GetTicks() - t1) < (1000/120)) {
      
      // printf("0x%.4x: ", cpu.pc); disassemble_instruction(8, mem+cpu.pc); trace_cpu_state(&cpu);
      
      // debugging jump out of rom bug

      // execution from 0x0262 seems to be okay
      // so the question is why is (hl) 03BB
      if(1 && instructions >= 2358034-100) {
	int lowest, insts_printed;
	int i;
	int seen;
	insts_printed = 0;
	lowest = 1;
	while(insts_printed < 0x50) {
	  seen = 0;
	  for(i = 0; i < 0xFF; i++) {
	    if(inst_counts[i] == lowest) {
	      insts_printed++;
	      if(!seen) {
		seen = 1;
		printf("\n%d:", lowest);
	      }
	      printf(" 0x%02X", i);
	    }
	  }
	  lowest++;
	}
	puts("");
	
	/*
1: 0x16 0x2A 0x31 0x46 0x78 0xC4 0xF6
2: 0x00 0x2E 0x79
3: 0x07 0x56 0x5E 0x66 0x7A 0x7B
5: 0xD8
6: 0x0E 0x1F 0x4F
7: 0x7E
8: 0x57
9: 0x5F
10: 0x37
12: 0xF5
14: 0x67
16: 0xC6
32: 0x03
34: 0x0A
*/
	exit(0);
	
	//
	
	trace_cpu_state(&cpu);
	// todo align it to 0x10
	for(i = 0; i < 0x20; i+=2) {
	  if(!(i%0x10)) printf("\n0x%.4x: ", cpu.sp-0x10+i);
	  printf("%04X ", *(uint16_t*)(mem+cpu.sp-0x10+i));
	}
	puts("\n");
	printf("0x%.4x: ", cpu.pc); disassemble_instruction(8, mem+cpu.pc);
	puts("\n");
      }
      
      t_cycles = emulate_instruction(&cpu, mem);
      instructions++;
      inst_counts[*(mem+cpu.pc)]++;
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
    if((SDL_GetTicks() - t1) < (1000*speedup/120)) {
      SDL_Delay(((1000*speedup/120) - (SDL_GetTicks() - t1)));
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
