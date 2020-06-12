#include <stdio.h>

asm("createsig FiiE");

//asm(".hidden f");

extern int f(int) __attribute__((weak)) __attribute__((rawcall));

int main(void)
{
  printf ("%p\n", f);
  if (f)
    f (42);
}
