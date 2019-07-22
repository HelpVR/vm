# vm

## System Specifications
- 65536 Addresses (16-bit)
- 16 Registers (16-bit)

## Example
```c
  mem[0x3000] = 0x1064; // LDI R0, #100
  mem[0x3001] = 0x11c8; // LDI R1, #200
  mem[0x3002] = 0x2201; // ADD R2, R0, R1
  mem[0x3003] = 0xf000; // HLT
```
