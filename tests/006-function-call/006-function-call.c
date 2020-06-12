#include <stdio.h>

int f(int a, int b)
{
  printf("a %d b %d\n", a, b);
  return 7 * a - b;
}

int main(void)
{
  puts("hi");
  puts("hi");
  printf("%d\n", f(10, 5));
  printf("%d\n", f(5, 10));
  fprintf(fdopen(1, "w"), "hi there %d\n", 42);

  return 0;
}

const char *string = "this is a constant string";
