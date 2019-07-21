#pragma once

#include <stdint.h>
#include <stdbool.h>

#define ADDRESSES UINT16_MAX
#define REGISTERS 16

#define NOP 0x0000
#define LDI 0x0001
#define ADD 0x0002
#define HLT 0x000f