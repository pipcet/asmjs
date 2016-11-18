#include <stdio.h>

extern void* __curbrk;

static void f(void)
{
  __curbrk = 64 * 1024 * 1024;
}

__attribute__((section(".init_array"))) static void (*f_init)(void) = f;
