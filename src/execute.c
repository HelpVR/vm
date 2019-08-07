#include "execute.h"
#include "memory.h"

#include <stdbool.h>
#include <stdio.h>

enum Code {
  NOP = 0x00,
  MOV = 0x10,
  LDR = 0x20,
  STR = 0x30,
  PUSH = 0x40,
  POP = 0x50,
  ADD = 0x60,
  SUB = 0x70,
  MUL = 0x80,
  AND = 0x90,
  ORR = 0xa0,
  EOR = 0xb0,
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
  uint16_t rd = (instruction & 0x00ff0000) >> 16;
  uint16_t r1 = (instruction & 0x0000ff00) >> 8;
  uint16_t r2 = (instruction & 0x000000ff);
  uint16_t imm16 = (instruction & 0x000ffff);

  switch (op) {
  case NOP:
    printf("nop\n");
    break;
  case MOV:
    printf("mov r%d, #%d\n", rd, imm16);
    reg[rd] = imm16;
    break;
  case LDR:
    // TODO
    break;
  case STR:
    // TODO
    break;
  case PUSH:
    printf("push r%d\n",rd);
    stack[SP++] = reg[rd];
    break;
  case POP:
    printf("pop r%d\n",rd);
    reg[rd] = stack[--SP];
    break;
  case ADD:
    printf("add r%d, r%d, r%d\n", rd, r1, r2);
    reg[rd] = reg[r1] + reg[r2];
    break;
  case SUB:
    printf("sub r%d, r%d, r%d\n", rd, r1, r2);
    reg[rd] = reg[r1] - reg[r2];
    break;
  case MUL:
    printf("mul r%d, r%d, r%d\n", rd, r1, r2);
    reg[rd] = reg[r1] * reg[r2];
    break;
  case AND:
    printf("and r%d, r%d, r%d\n", rd, r1, r2);
    reg[rd] = reg[r1] & reg[r2];
    break;
  case ORR:
    printf("orr r%d, r%d, r%d\n", rd, r1, r2);
    reg[rd] = reg[r1] | reg[r2];
    break;
  case EOR:
    printf("eor r%d, r%d, r%d\n", rd, r1, r2);
    reg[rd] = reg[r1] ^ reg[r2];
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
