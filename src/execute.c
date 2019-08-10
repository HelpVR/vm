#include "execute.h"

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
  AND = 0x80,
  ORR = 0x90,
  EOR = 0xa0,
  LSL = 0xb0,
  LSR = 0xc0,
  HALT = 0xff
};

extern bool running;

extern uint32_t memory[65536];
extern uint32_t reg[16];
extern uint32_t stack[16];

#define SP reg[13] // Stack Pointer
#define PC reg[15] // Program Counter

void execute(uint32_t instruction) {
  uint16_t op = (instruction & 0xff000000) >> 24;

  uint16_t r1 = (instruction & 0x00ff0000) >> 16;
  uint16_t r2 = (instruction & 0x0000ff00) >> 8;
  uint16_t r3 = (instruction & 0x000000ff);

  uint16_t imm16 = (instruction & 0x0000ffff);
  uint16_t imm8  = (instruction & 0x000000ff);

  switch (op) {
  case NOP: // No Operation
    printf("nop\n");
    break;
  case MOV: // Move
    printf("mov r%d, #%d\n", r1, imm8);
    reg[r1] = imm8;
    break;
  case LDR: // Load
    printf("ldr r%d, [r%d]\n", r1, r3);
    reg[r1] = memory[reg[r3]];
    break;
  case STR: // Store
    printf("str r%d, [r%d]\n", r1, r3);
    memory[reg[r3]] = reg[r1];
    break;
  case PUSH: // Push
    printf("push r%d\n",r1);
    stack[SP++] = reg[r1];
    break;
  case POP: // Pop
    printf("pop r%d\n",r1);
    reg[r1] = stack[--SP];
    break;
  case ADD: // Add
    printf("add r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] + reg[r3];
    break;
  case SUB: // Subtract
    printf("sub r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] - reg[r3];
    break;
  case AND: // Logical And
    printf("and r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] & reg[r3];
    break;
  case ORR: // Logical Or
    printf("orr r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] | reg[r3];
    break;
  case EOR: // Exclusive Or
    printf("eor r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] ^ reg[r3];
    break;
  case LSL: // Logical Shift Left
    printf("lsl r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] << reg[r3];
    break;
  case LSR: // Logical Shift Right
    printf("lsr r%d, r%d, r%d\n", r1, r2, r3);
    reg[r1] = reg[r2] >> reg[r3];
    break;
  case HALT: // Halt
    printf("halt\n");
    running = false;
    break;
  default:
    // TODO
    break;
  }
}
