#include <stdio.h>

void __wasm_lazyload(unsigned long index)
{
  printf("index is %ld, should be %ld\n", index,
         *(long *)12408);

  asm volatile("i32.const 0xdeadbeef\n\t"
               "%0\n\t"
               "i32.const 0\n\t"
               "i32.const 0\n\t"
               "i32.const 0\n\t"
               "i32.const 0\n\t"
               "call $trace\n\t"
               "drop" : : "r" (index));
}
