![image](https://user-images.githubusercontent.com/1548352/62435938-a37d4380-b746-11e9-9182-47da9c8184a6.png)

[![CodeFactor](https://www.codefactor.io/repository/github/xorz57/vm/badge)](https://www.codefactor.io/repository/github/xorz57/vm)

## Example
```c
  mem[0x1000] = 0x0000ffff; // 0x0000ffff
  mem[0x1001] = 0x00000001; // 0x00000001
  mem[0x3000] = 0x10001000; // LDR R0, 0x1000
  mem[0x3001] = 0x10011001; // LDR R1, 0x1001
  mem[0x3002] = 0x50020001; // ADD R2, R0, R1
  mem[0x3003] = 0x20001003; // STR R0, 0x1003
  mem[0x3004] = 0x30000000; // PSH R0
  mem[0x3005] = 0x30010000; // PSH R1
  mem[0x3006] = 0x40000000; // POP R0
  mem[0x3007] = 0x40010000; // POP R1
  mem[0x3008] = 0xff000000; // HLT
```

# Credits
- Icon made by Roundicons from www.flaticon.com
