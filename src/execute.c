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
  LSL = 0xc0,
  LSR = 0xd0,
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
  uint16_t rn = (instruction & 0x0000ff00) >> 8;
  uint16_t rm = (instruction & 0x000000ff);
  uint16_t imm16 = (instruction & 0x000ffff);

  switch (op) {
  case NOP: // No Operation
    printf("nop\n");
    break;
  case MOV: // Move
    printf("mov r%d, #%d\n", rd, imm16);
    reg[rd] = imm16;
    break;
  case LDR: // Load
    // TODO
    break;
  case STR: // Store
    // TODO
    break;
  case PUSH: // Push
    printf("push r%d\n",rd);
    stack[SP++] = reg[rd];
    break;
  case POP: // Pop
    printf("pop r%d\n",rd);
    reg[rd] = stack[--SP];
    break;
  case ADD: // Add
    printf("add r%d, r%d, r%d\n", rd, rn, rm);
    reg[rd] = reg[rn] + reg[rm];
    break;
  case SUB: // Subtract
    printf("sub r%d, r%d, r%d\n", rd, rn, rm);
    reg[rd] = reg[rn] - reg[rm];
    break;
  case MUL: // Multiply
    printf("mul r%d, r%d, r%d\n", rd, rn, rm);
    reg[rd] = reg[rn] * reg[rm];
    break;
  case AND: // Logical And
    printf("and r%d, r%d, r%d\n", rd, rn, rm);
    reg[rd] = reg[rn] & reg[rm];
    break;
  case ORR: // Logical Or
    printf("orr r%d, r%d, r%d\n", rd, rn, rm);
    reg[rd] = reg[rn] | reg[rm];
    break;
  case EOR: // Exclusive Or
    printf("eor r%d, r%d, r%d\n", rd, rn, rm);
    reg[rd] = reg[rn] ^ reg[rm];
    break;
  case LSL: // Logical Shift Left
    // TODO
    break;
  case LSR: // Logical Shift Right
    // TODO
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
