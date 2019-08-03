#include "core.h"
#include "execute.h"
#include "signal.h"

bool running;

uint32_t mem[ADDRESSES]; // Memory
uint16_t reg[REGISTERS]; // Registers

uint16_t iar; // Instruction Address Register

uint32_t fetch() { return mem[iar++]; }

volatile sig_atomic_t signal_status;

int main() {
  signal(SIGINT, signal_handler);

  mem[0x3000] = 0x01000064; // LDI R0, #100
  mem[0x3001] = 0x010100c8; // LDI R1, #200
  mem[0x3002] = 0x02020001; // ADD R2, R0, R1
  mem[0x3003] = 0x0f000000; // HLT

  iar = 0x3000;

  running = true;

  while (running) {
    uint32_t instruction = fetch();
    execute(instruction);
  }

  return 0;
}