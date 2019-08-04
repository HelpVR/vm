#pragma once

#include <stdint.h>
#include <stdbool.h>

#define ADDRESSES 65536
#define REGISTERS 16
#define STACK_SIZE 16

#define NOP 0x00
#define LDR 0x10
#define STR 0x20
#define PSH 0x30
#define POP 0x40
#define ADD 0x50
#define SUB 0x60
#define AND 0x70
#define HLT 0xff
