#include <stdint.h>
#include <stdbool.h>

// change this to whatever you like
#define MEMORY uint8_t*

// and then implement these
uint8_t mem_read_8(MEMORY mem, uint16_t addr);
uint16_t mem_read_16(MEMORY mem, uint16_t addr);
void mem_write_8(MEMORY mem, uint16_t addr, uint8_t value);
void mem_write_16(MEMORY mem, uint16_t addr, uint16_t value);

typedef union {
  struct {
    uint8_t lsb;
    uint8_t msb;
  };
  uint16_t pair;
} z80_reg_pair;

typedef struct {
  uint16_t ix, iy, sp, pc;
  z80_reg_pair af, bc, de, hl;
  z80_reg_pair afp, bcp, dep, hlp;
  uint8_t i, r;
  bool iff1, iff2;
} z80;

void initialize_cpu(z80 *cpu);
void trace_cpu_state(z80 *cpu);
int disassemble_instruction(long size, uint8_t *data);
int emulate_instruction(z80 *cpu, MEMORY mem, long size, uint8_t *data);
