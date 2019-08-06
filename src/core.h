#pragma once

#include <stdint.h>
#include <stdbool.h>

#define ADDRESSES 65536
#define REGISTERS 16
#define STACK_SIZE 16

enum Code {
  NOP = 0x00,
  LDR = 0x10, LDA = 0x11,
  STR = 0x20, STA = 0x21,
  PSH = 0x30,
  POP = 0x40,
  ADD = 0x50,
  SUB = 0x60,
  MUL = 0x70,
  AND = 0x80,
  HLT = 0xff
};

