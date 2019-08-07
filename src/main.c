#include "core.h"
#include "execute.h"
#include "signal.h"
#include <stdio.h>

bool running;

uint32_t mem[ADDRESSES];
uint32_t reg[REGISTERS];
uint32_t stack[STACK_SIZE];

uint32_t acc; // Accumulator Register

uint16_t iar; // Instruction Address Register

uint16_t sp; // Stack Pointer

uint32_t fetch() { return mem[iar++]; }

volatile sig_atomic_t signal_status;

int main() {
  signal(SIGINT, signal_handler);

  mem[0x1000] = 0x0000ffff; // 0x0000ffff
  mem[0x1001] = 0x00000001; // 0x00000001
  mem[0x3000] = 0x10001000; // ldi r0, 0x1000
  mem[0x3001] = 0x10011001; // ldi r1, 0x1001
  mem[0x3002] = 0x50020001; // add r2, r0, r1
  mem[0x3003] = 0x20021003; // str r2, 0x1003
  mem[0x3004] = 0xff000000; // halt

  iar = 0x3000;

  sp = 0;

  running = true;

  while (running) {
    uint32_t instruction = fetch();
    execute(instruction);
  }

  return 0;
}
