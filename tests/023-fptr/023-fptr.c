#include <stdio.h>

int foo(void)
{
  return 0;
}

int main(void)
{
  static int (*foop)(void) = foo;
  printf("%p %d\n", foop, foop());
  return 0;
}
