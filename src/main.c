#include "execute.h"
#include "signal.h"

#include <stdbool.h>

bool running;

uint32_t mem[65536];
uint32_t reg[16];
uint32_t stack[16];

#define SP reg[13] // Stack Pointer
#define PC reg[15] // Program Counter

uint32_t fetch() { return mem[PC++]; }

volatile sig_atomic_t signal_status;

int main() {
  signal(SIGINT, signal_handler);

  mem[0x3000] = 0x10000001; // mov r0, #1
  mem[0x3001] = 0x10010002; // mov r1, #2
  mem[0x3002] = 0x60020001; // add r2, r0, r1
  mem[0x3003] = 0xff000000; // halt

  SP = 0x0000;
  PC = 0x3000;

  running = true;

  while (running) {
    uint32_t instruction = fetch();
    execute(instruction);
  }

  return 0;
}
