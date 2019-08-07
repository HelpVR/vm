#include "execute.h"
#include "memory.h"

#include <stdbool.h>
#include <stdio.h>

enum Code {
  NOP = 0x00,
  LDR = 0x10,
  STR = 0x20,
  PUSH = 0x30,
  POP = 0x40,
  ADD = 0x50,
  SUB = 0x60,
  MUL = 0x70,
  AND = 0x80,
  ORR = 0x90,
  EOR = 0xa0,
  HALT = 0xff
};

extern bool running;

extern uint32_t mem[65536];
extern uint32_t reg[16];
extern uint32_t stack[16];

#define SP reg[13] // Stack Pointer
#define PC reg[15] // Program Counter

void execute(uint32_t instruction) {
  uint16_t op = (instruction & 0xff000000) >> 24;
  uint16_t r1 = (instruction & 0x00ff0000) >> 16;
  uint16_t r2 = (instruction & 0x0000ff00) >> 8;
  uint16_t r3 = (instruction & 0x000000ff);
  uint16_t imm = (instruction & 0x000ffff);

  switch (op) {
  case NOP:
    printf("nop\n");
    break;
  case LDR:
    printf("ldr r%d, 0x%04x\n", r1, imm);
    reg[r1] = mem[imm];
    break;
  case STR:
    printf("str r%d, 0x%04x\n", r1, imm);
    mem[imm] = reg[r1];
    break;
  case PUSH:
    printf("push r%d\n",r1);
    stack[SP++] = reg[r1];
    break;
  case POP:
    printf("pop r%d\n",r1);
    reg[r1] = stack[--SP];
    break;
  case ADD:
    printf("add r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] + reg[r3];
    break;
  case SUB:
    printf("sub r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] - reg[r3];
    break;
  case MUL:
    printf("mul r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] * reg[r3];
    break;
  case AND:
    printf("and r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] & reg[r3];
    break;
  case ORR:
    printf("orr r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] | reg[r3];
    break;
  case EOR:
    printf("eor r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] ^ reg[r3];
    break;
  case HALT:
    printf("halt\n");
    running = false;
    break;
  default:
    // TODO
    break;
  }
}
