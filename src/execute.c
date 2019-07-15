#include "execute.h"
#include "memory.h"
#include "core.h"

#include <stdio.h>

extern uint16_t mem[ADDRESSES];
extern uint16_t reg[REGISTERS];

extern bool running;

void execute(uint16_t instruction) {
  int op = (instruction & 0xf000) >> 12;
  int r1 = (instruction & 0x0f00) >> 8;
  int r2 = (instruction & 0x00f0) >> 4;
  int r3 = (instruction & 0x000f);
  int imm = (instruction & 0x00ff);

  switch (op) {
  case 0:
    printf("halt\n");
    running = false;
    break;
  case 1:
    printf("loadi r%d #%d\n", r1, imm);
    reg[r1] = imm;
    break;
  case 2:
    printf("add r%d r%d r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] + reg[r3];
    break;
  case 3:
    printf("sub r%d r%d r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] - reg[r3];
    break;
  case 4:
    printf("mul r%d r%d r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] * reg[r3];
    break;
  case 5:
    printf("div r%d r%d r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] / reg[r3];
    break;
  case 6:
    printf("mod r%d r%d r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] % reg[r3];
    break;
  }
}