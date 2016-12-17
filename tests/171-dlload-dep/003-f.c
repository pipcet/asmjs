extern int x;

#include <stdio.h>

int f(void)
{
  printf("x: %p\n", &x);
  printf("\n");

  return x;
}
