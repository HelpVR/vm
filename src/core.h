#pragma once

#include <stdint.h>
#include <stdbool.h>

#define ADDRESSES 65536
#define REGISTERS 16

#define NOP 0x00
#define LDI 0x10
#define LDR 0x11
#define LDA 0x12
#define STR 0x20
#define ADD 0x30
#define HLT 0xff
