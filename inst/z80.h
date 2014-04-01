#include <stdint.h>
#include <stdbool.h>

// change this to whatever you like
#define MEMORY uint8_t*

// and then implement these
uint8_t mem_read_8(MEMORY mem, uint16_t addr);
int8_t mem_read_8_signed(MEMORY mem, uint16_t addr);
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

// pg76
//  7  6  5  4  3  2    1  0
// [S][Z][X][H][X][P/V][N][C] // [docs wrong, is 4=H right?]

#define FLAG_C 0x01
#define FLAG_N 0x02
#define FLAG_PV 0x04
//
#define FLAG_H 0x10
//
#define FLAG_Z 0x40
#define FLAG_S 0x80
#define COMBINE_FLAGS(c,n,pv,h,z,s) ((c)?FLAG_C:0)|((n)?FLAG_N:0)|((pv)?FLAG_PV:0)|((h)?FLAG_H:0)|((z)?FLAG_Z:0)|((s)?FLAG_S:0)


void initialize_cpu(z80 *cpu);
void trace_cpu_state(z80 *cpu);
int disassemble_instruction(long size, uint8_t *data);
int emulate_instruction(z80 *cpu, MEMORY mem);
