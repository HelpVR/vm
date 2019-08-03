#include "core.h"
#include "execute.h"
#include "signal.h"
#include <stdio.h>

bool running;

uint32_t mem[ADDRESSES]; // Memory
uint32_t reg[REGISTERS]; // Registers

uint16_t iar; // Instruction Address Register

uint32_t fetch() { return mem[iar++]; }

volatile sig_atomic_t signal_status;

int main() {
  signal(SIGINT, signal_handler);

  mem[0x1000] = 0x0000ffff; // 0x0000ffff
  mem[0x1001] = 0x00000001; // 0x00000001

  mem[0x3000] = 0x10001000; // LDI R0, 0x1000
  mem[0x3001] = 0x10011001; // LDI R1, 0x1001
  mem[0x3002] = 0x50020001; // ADD R2, R0, R1
  mem[0x3003] = 0x20001003; // STR R2, 0x1003
  mem[0x3004] = 0xff000000; // HLT

  iar = 0x3000;

  running = true;

  while (running) {
    uint32_t instruction = fetch();
    execute(instruction);
    for (uint16_t ri = 0; ri < REGISTERS; ri++) {
      printf("r%02d: 0x%08x ", ri, reg[ri]);
      if ((ri + 1) % 4 == 0) printf("\n");
    }
    printf("\n");
  }

  return 0;
}
