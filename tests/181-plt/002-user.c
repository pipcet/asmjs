#include <stdio.h>

int main(void)
{
  double d1 = 3.14;
  double d2 = 2.71;
  double d;

  asm("createsig FdddE");

  asm("%S0\n\t%1\n\t%2\n\tcall plus@plt{__sigchar_FdddE}\n\t%R0" : "=r" (d) : "r" (d1), "r" (d2));

  printf("%f\n", d);

  return 0;
}
