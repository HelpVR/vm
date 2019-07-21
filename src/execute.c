#include "execute.h"
#include "memory.h"
#include "core.h"

#include <stdio.h>

extern uint16_t mem[ADDRESSES];
extern uint16_t reg[REGISTERS];

extern uint16_t acc;

extern bool running;

void execute(uint16_t instruction) {
  uint16_t op = (instruction & 0xf000) >> 12;
  uint16_t r1 = (instruction & 0x0f00) >> 8;
  uint16_t r2 = (instruction & 0x00f0) >> 4;
  uint16_t r3 = (instruction & 0x000f);
  uint16_t imm = (instruction & 0x00ff);

  switch (op) {
  case NOP:
    printf("NOP\n");
    break;
  case LDI:
    printf("LDI R%d, #%d\n", r1, imm);
    reg[r1] = imm;
    break;
  case ADD:
    printf("ADD R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] + reg[r3];
    break;
  case HLT:
    printf("HLT\n");
    running = false;
    break;
  }
}