#include <stdio.h>

int main(void)
{
  volatile long x = 0x6000000000000000LL;
  volatile long y = 0xc000000000000000LL;

  printf("%lx %lx\n",
         x / y, x % y);

  return 0;
}
