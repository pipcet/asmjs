#include <stdio.h>

extern int dummy(void) asm("$dummy");

int main(void)
{
  volatile double rootthis = 2.0;
  asm volatile("%S0\n\t%1\n\tcall $sqrt\n\t%R0" : "=r" (rootthis) : "r" (rootthis));
  fprintf(stderr, "sqrt(2) is %f\n", rootthis);
  //printf("%p\n", dummy);
  return 0;
}
