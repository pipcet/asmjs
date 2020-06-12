#include <stdio.h>

int f(int a, int b)
{
  return 2 * a - b;
}

int main(int argc, char **argv)
{
  printf("stderr is %p\n", stderr);
  fprintf(stderr, "argc: %d\n", argc);
  fprintf(stderr, "argv: %p\n", argv);
  fprintf(stderr, "arg0: %s\n", argv[0]);

  return 0;
}
