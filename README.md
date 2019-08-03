# vm: work in progress

## Example
```c
  mem[0x3000] = 0x01000064; // LDI R0, #100
  mem[0x3001] = 0x010100c8; // LDI R1, #200
  mem[0x3002] = 0x02020001; // ADD R2, R0, R1
  mem[0x3003] = 0x0f000000; // HLT
```