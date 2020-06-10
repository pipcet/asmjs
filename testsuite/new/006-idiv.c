#include <stdio.h>

asm("createsig FdddE");

asm(".globl __idiv");

asm("defun __idiv FdddE\n\t"
    "local.get 0\n\t"
    "local.get 1\n\t"
    "f64.div\n\t"
    "return\n\t"
    "end\n\t"
    "endefun __idiv\n\t");

extern double __idiv(double, double) __attribute__((rawcall));

int main(void)
{
  double x = 3.1415;
  double y = 2.7178;
  double z;
  int i = 0;

  /* 6.238 s
  for (i = 0; i < 100000000; i++)
    __idiv(x,y);  6.238 s
  */

  /* 3.716s
  for (i = 0; i < 100000000; i++)
    asm volatile("%S0\n\t"
                 "%1\n\t"
                 "%2\n\t"
                 "f64.div\n\t"
                 "%R0"
                 : "=rm" (z) : "rm" (x), "rm" (y));
  */

  printf ("%f\n", z);

  return 0;
}
