#include <stdio.h>

#include <SDL/SDL.h>

#include <i8080-core/i8080.h>
#include <i8080-core/i8080_hal.h>

// This is the speed/cycles per frame
// taken from MAME: http://mamedev.org/source/src/mame/includes/mw8080bw.h.html
#define MW8080BW_MASTER_CLOCK             (19968000.0)

// secretly including this so that i can easily call RSTs
extern int i8080_execute(int opcode);

int shift_register;
int shift_offset;

// These two functions implement the hardware shift register
// that is used to move the aliens around the screen, as well
// as the key inputs
int i8080_hal_io_input(int port) {
  if(port == 3) {
    return (shift_register >> (8 - shift_offset)) & 0xFF;
  }
  
  if(port == 1) {
    return ((1&(rand()%2)&(rand()%2)&(rand()%2))<<((rand()%7))) | (1<<3);
  }
  
  return 0;
}

void i8080_hal_io_output(int port, int value) {
  if(port == 4) {
    shift_register >>= 8;
    shift_register |= (value << 8) & 0xFF00;
  }
  else if(port == 2) {
    shift_offset = value & 0x7;
  }
}

// Copies the video portion of memory onto the pixel buffer
// so we can see the game
// We loop over the bits of the VRAM and work out the right
// x,y coordinate for the color it describes
void map_vram_to_screen(unsigned char *pixel) {
  int x, y;
  int v, b;
  
#define BIT(n,b) ((n>>b)&1)
  
  x = 0; y = 0;
  for(v = 0x2400; v < 0x4000; v++) {
    for(b = 0; b < 8; b++) {
      pixel[x + 224*(256-1-y)] = BIT(i8080_hal_memory_read_byte(v),b) ? 0xFF : 0x00;
      
      y++;
      if(y >= 256) {
        y = 0;
        x++;
      }
    }
  }
}

// Reads a ROM segment from a file into the
// ROM location of memory
int read_rom_segment(char *rom_name, int offset) {
  FILE *fptr;
  unsigned char *mem;
  
  mem = i8080_hal_memory();
  fptr = fopen(rom_name, "rb");
  
  if(!fptr) {
    printf("%s not found\n", rom_name);
    return -1;
  }
  
  if(fread(mem+offset, 0x0800, 1, fptr) != 1) {
    puts("%s could not be read\n");
    return -1;
  }
  
  fclose(fptr);
  
  return 0;
}

void handle_events(void) {
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
}

int main(void) {
  int timer, cycles;
  int vblank = 0;
  
  if(read_rom_segment("rom/invaders.h", 0x0000)) return EXIT_FAILURE;
  if(read_rom_segment("rom/invaders.g", 0x0800)) return EXIT_FAILURE;
  if(read_rom_segment("rom/invaders.f", 0x1000)) return EXIT_FAILURE;
  if(read_rom_segment("rom/invaders.e", 0x1800)) return EXIT_FAILURE;
  
  i8080_init();
  i8080_jump(0x0);
  
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) {
    printf("Cannot initialize SDL\n");
    return EXIT_FAILURE;
  }
  SDL_Surface *screen = SDL_SetVideoMode(224, 256, 8, SDL_DOUBLEBUF);
  
  while(1) {
    timer = SDL_GetTicks();
    for(cycles = 0; cycles < MW8080BW_MASTER_CLOCK/120; cycles += i8080_instruction());
    handle_events();
    timer = SDL_GetTicks() - timer;
    if(timer < 1000/120) {
      SDL_Delay(1000/120 - timer);
    }
    
    vblank = !vblank;
    if(vblank) {
      i8080_execute(0xD7); // RST 0x10
    }
    else {
      i8080_execute(0xCF); // RST 0x08
      continue;
    }
    SDL_LockSurface(screen);
    map_vram_to_screen(screen->pixels);
    SDL_UnlockSurface(screen);
    SDL_Flip(screen);
  }
  
  return EXIT_SUCCESS;
}

