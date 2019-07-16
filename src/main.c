#include "core.h"
#include "execute.h"
#include "signal.h"

bool running;

uint16_t mem[ADDRESSES];
uint16_t reg[REGISTERS];

uint16_t pc;

uint16_t fetch() { return mem[pc++]; }

volatile sig_atomic_t signal_status;

int main() {
  signal(SIGINT, signal_handler);

  pc = 0x3000;

  mem[0x3000] = 0x1064;
  mem[0x3001] = 0x11c8;
  mem[0x3002] = 0x2201;
  mem[0x3003] = 0x0000;

  running = true;

  while (running) {
    uint16_t instruction = fetch();
    execute(instruction);
  }

  return 0;
}