#include "execute.h"
#include "memory.h"
#include "core.h"

#include <stdio.h>

extern uint16_t mem[ADDRESSES];
extern uint16_t reg[REGISTERS];

extern uint16_t acc;

extern bool running;

void execute(uint16_t instruction) {
  int op = (instruction & 0xf000) >> 12;
  int r1 = (instruction & 0x0f00) >> 8;
  int r2 = (instruction & 0x00f0) >> 4;
  int r3 = (instruction & 0x000f);
  int imm = (instruction & 0x00ff);

  switch (op) {
  case 0:
    printf("HLT\n");
    running = false;
    break;
  case 1:
    printf("LDI R%d, #%d\n", r1, imm);
    reg[r1] = imm;
    break;
  case 2:
    printf("ADD R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] + reg[r3];
    break;
  case 3:
    printf("SUB R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] - reg[r3];
    break;
  case 4:
    printf("MUL R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] * reg[r3];
    break;
  case 5:
    printf("DIV R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] / reg[r3];
    break;
  case 6:
    printf("MOD R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] % reg[r3];
    break;
  case 7:
    printf("AND R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] & reg[r3];
    break;
  }
}