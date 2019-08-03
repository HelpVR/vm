#pragma once

#include <stdint.h>
#include <stdbool.h>

#define ADDRESSES 65536
#define REGISTERS 16

#define NOP 0x00
#define LDI 0x01
#define ADD 0x02
#define HLT 0x0f