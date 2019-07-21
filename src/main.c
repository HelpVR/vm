#include "core.h"
#include "execute.h"
#include "signal.h"

bool running;

uint16_t mem[ADDRESSES]; // Memory
uint16_t reg[REGISTERS]; // Registers

uint16_t acc; // Accumulator
uint16_t iar; // Instruction Address Register

uint16_t fetch() { return mem[iar++]; }

volatile sig_atomic_t signal_status;

int main() {
  signal(SIGINT, signal_handler);

  mem[0x3000] = 0x1064; // LDI R0, #100
  mem[0x3001] = 0x11c8; // LDI R1, #200
  mem[0x3002] = 0x2201; // ADD R2, R0, R1
  mem[0x3003] = 0xf000; // HLT

  iar = 0x3000;

  running = true;

  while (running) {
    uint16_t instruction = fetch();
    execute(instruction);
  }

  return 0;
}