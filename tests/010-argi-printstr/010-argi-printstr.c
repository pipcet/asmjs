#include <stdio.h>

int f(int a, int b)
{
  return 2 * a - b;
}

int printstr(const char *string)
{
  //asm("Module.print('string should be ' + HEAPU32[(fp +        20 )>>2]);");
  return fprintf(stderr, "string: %s\n", string);
}

int main(int argc, char **argv)
{
  fprintf(stderr, "arg0: %p %p %s\n", argv+0, argv[0], argv[0]);
  fprintf(stderr, "arg0: %p %p %s\n", argv+0, argv[0], argv[0]);
  fprintf(stderr, "arg1: %p %p %s\n", argv+1, argv[1], argv[1]);
  fprintf(stderr, "arg2: %p %p %s\n", argv+2, argv[2], argv[2]);
  fprintf(stderr, "arg3: %p %p %s\n", argv+3, argv[3], argv[3]);
  fprintf(stderr, "arg4: %p %p %s\n", argv+4, argv[4], argv[4]);
  fprintf(stderr, "arg5: %p %p %s\n", argv+5, argv[5], argv[5]);
  fprintf(stderr, "arg6: %p %p %s\n", argv+6, argv[6], argv[6]);
  fprintf(stderr, "arg7: %p %p %s\n", argv+7, argv[7], argv[7]);
  fprintf(stderr, "argc: %d\n", argc);
  fprintf(stderr, "argv: %p\n", argv);
  fprintf(stderr, "string0: %p\n", argv[0]);

  //asm("Module.print('string0 should be ' + HEAPU32[(HEAPU32[(fp +        28 )>>2])>>2]);");
  printstr(argv[0]);
  printstr(argv[1]);
  printstr(argv[2]);
  printstr(argv[3]);
  printstr(argv[4]);
  printstr(argv[5]);
  printstr(argv[6]);
  printstr(argv[7]);

  return 0;
}
