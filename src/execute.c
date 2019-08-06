#include "execute.h"
#include "memory.h"
#include "core.h"

#include <stdio.h>

extern bool running;

extern uint32_t mem[ADDRESSES];
extern uint32_t reg[REGISTERS];
extern uint32_t stack[STACK_SIZE];

extern uint32_t acc;

extern uint16_t sp;

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
  case LDR:
    printf("LDR R%d, 0x%04x\n", r1, imm);
    reg[r1] = mem[imm];
    break;
  case LDA:
    printf("LDA 0x%04x\n", imm);
    acc = mem[imm];
    break;
  case STR:
    printf("STR R%d, 0x%04x\n", r1, imm);
    mem[imm] = reg[r1];
    break;
  case STA:
    printf("STA 0x%04x\n", imm);
    mem[imm] = acc;
    break;
  case PSH:
    printf("PSH R%d\n",r1);
    stack[sp++] = reg[r1];
    break;
  case POP:
    printf("POP R%d\n",r1);
    reg[r1] = stack[--sp];
    break;
  case ADD:
    printf("ADD R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] + reg[r3];
    break;
  case SUB:
    printf("SUB R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] - reg[r3];
    break;
  case MUL:
    printf("MUL R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] * reg[r3];
    break;
  case AND:
    printf("AND R%d, R%d, R%d\n", r1, r2, r3);
    acc = reg[r1] = reg[r2] & reg[r3];
    break;
  case HLT:
    printf("HLT\n");
    running = false;
    break;
  default:
    // TODO
    break;
  }
}
