![image](https://user-images.githubusercontent.com/1548352/62435938-a37d4380-b746-11e9-9182-47da9c8184a6.png)

[![Build Status](https://travis-ci.org/xorz57/vm.svg?branch=master)](https://travis-ci.org/xorz57/vm)
[![CodeFactor](https://www.codefactor.io/repository/github/xorz57/vm/badge)](https://www.codefactor.io/repository/github/xorz57/vm)

## Example 1
```c
  mem[0x3000] = 0x10000001; // mov r0, #1
  mem[0x3001] = 0x10010002; // mov r1, #2
  mem[0x3002] = 0x60020001; // add r2, r0, r1
  mem[0x3003] = 0xff000000; // halt
```

## Example 2
```c
  mem[0x3000] = 0x10000001; // mov r0, #1
  mem[0x3001] = 0x10010002; // mov r1, #2
  mem[0x3002] = 0x60020001; // add r2, r0, r1
  mem[0x3003] = 0x40000000; // push r0
  mem[0x3004] = 0x40010000; // push r1
  mem[0x3005] = 0x50000000; // pop r0
  mem[0x3006] = 0x50010000; // pop r1
  mem[0x3007] = 0xff000000; // halt
```

## Credits
- Icon made by Roundicons from www.flaticon.com
