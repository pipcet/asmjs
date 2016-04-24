#include <stdio.h>

int f(int a, int b)
{
  return 2 * a - b;
}

int main(int argc, char **argv)
{
  fprintf(stderr, "arg0: %p %s\n", argv+0, argv[0]);
  fprintf(stderr, "arg1: %p %s\n", argv+1, argv[1]);
  fprintf(stderr, "arg2: %p %s\n", argv+2, argv[2]);
  fprintf(stderr, "arg3: %p %s\n", argv+3, argv[3]);
  fprintf(stderr, "arg4: %p %s\n", argv+4, argv[4]);
  fprintf(stderr, "arg5: %p %s\n", argv+5, argv[5]);
  fprintf(stderr, "arg6: %p %s\n", argv+6, argv[6]);
  fprintf(stderr, "arg7: %p %s\n", argv+7, argv[7]);
  fprintf(stderr, "argc: %d\n", argc);
  fprintf(stderr, "argv: %p\n", argv);

  return 0;
}
