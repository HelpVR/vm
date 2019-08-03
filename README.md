# vm: work in progress

## Example
```c
  mem[0x3000] = 0x10000064; // LDI R0, #100
  mem[0x3001] = 0x100100c8; // LDI R1, #200
  mem[0x3002] = 0x20020001; // ADD R2, R0, R1
  mem[0x3003] = 0x11030002; // LDR R3, R2
  mem[0x3004] = 0xff000000; // HLT
```