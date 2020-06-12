#include <stdio.h>

int foo(void)
{
  return 0;
}

extern int main(void);

void *mainp = main;

int main(void)
{
  static int (*foop)(void) = foo;
  printf("%p\n", mainp);
  printf("%p %d\n", foop, foop());
  return 0;
}
