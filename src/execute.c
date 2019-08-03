#include "execute.h"
#include "memory.h"
#include "core.h"

#include <stdio.h>

extern uint32_t mem[ADDRESSES];
extern uint16_t reg[REGISTERS];

extern bool running;

void execute(uint32_t instruction) {
  uint16_t op = (instruction & 0xff000000) >> 24;
  uint16_t r1 = (instruction & 0x00ff0000) >> 16;
  uint16_t r2 = (instruction & 0x0000ff00) >> 8;
  uint16_t r3 = (instruction & 0x000000ff);
  uint16_t imm = (instruction & 0x000ffff);

  switch (op) {
  case NOP:
    printf("NOP\n");
    break;
  case LDI:
    printf("LDI R%d, %d\n", r1, imm);
    reg[r1] = imm;
    break;
  case LDR:
    printf("LDR R%d, R%d\n", r1, r3);
    reg[r1] = reg[r3];
    break;
  case LDA:
    printf("LDA R%d, %d\n", r1, imm);
    reg[r1] = mem[imm];
    break;
  case ADD:
    printf("ADD R%d, R%d, R%d\n", r1, r2, r3);
    reg[r1] = reg[r2] + reg[r3];
    break;
  case HLT:
    printf("HLT\n");
    running = false;
    break;
  }
}
