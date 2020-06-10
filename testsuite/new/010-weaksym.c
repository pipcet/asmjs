#include <stdio.h>

asm("createsig FiiE");

extern int f(int) __attribute__((weak));

int main(void)
{
  void (*g)(void) __attribute__((rawcall)) = 0;

  printf("%p\n", f);

  f(0);
}
