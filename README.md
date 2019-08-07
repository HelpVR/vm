![image](https://user-images.githubusercontent.com/1548352/62435938-a37d4380-b746-11e9-9182-47da9c8184a6.png)

[![Build Status](https://travis-ci.org/xorz57/vm.svg?branch=master)](https://travis-ci.org/xorz57/vm)
[![CodeFactor](https://www.codefactor.io/repository/github/xorz57/vm/badge)](https://www.codefactor.io/repository/github/xorz57/vm)

## Example 1
```c
  mem[0x1000] = 0x0000ffff; // 0x0000ffff
  mem[0x1001] = 0x00000001; // 0x00000001
  mem[0x3000] = 0x10001000; // ldi r0, 0x1000
  mem[0x3001] = 0x10011001; // ldi r1, 0x1001
  mem[0x3002] = 0x50020001; // add r2, r0, r1
  mem[0x3003] = 0x20001003; // str r0, 0x1003
  mem[0x3004] = 0xff000000; // halt
```

## Example 2
```c
  mem[0x1000] = 0x0000ffff; // 0x0000ffff
  mem[0x1001] = 0x00000001; // 0x00000001
  mem[0x3000] = 0x10001000; // ldi r0, 0x1000
  mem[0x3001] = 0x10011001; // ldi r1, 0x1001
  mem[0x3002] = 0x30000000; // push r0
  mem[0x3003] = 0x30010000; // push r1
  mem[0x3004] = 0x40000000; // pop r0
  mem[0x3005] = 0x40010000; // pop r1
  mem[0x3006] = 0xff000000; // halt
```

## Credits
- Icon made by Roundicons from www.flaticon.com
