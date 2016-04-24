#include <stdio.h>

int foo[4];
int *foop = foo;

int main(void)
{
  printf("%p\n", foop);
  printf("%p\n", foo);
  foo[0] = 0;
  printf("%p\n", foop);
  printf("%p\n", foo);
  return 0;
}
