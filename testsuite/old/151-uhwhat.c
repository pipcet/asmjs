#include <stdio.h>

int main(void)
{
  volatile unsigned long x = 0x280000000L;
  volatile unsigned long y = 0x280000000L;
  printf("%d\n", x < y);

  return 0;
}
