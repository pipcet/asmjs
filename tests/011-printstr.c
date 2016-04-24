#include <stdio.h>

int f(int a, int b)
{
  return 2 * a - b;
}

int printstr(const char *string)
{
  asm("Module.print('string should be ' + HEAPU32[($bp +        20 )>>2]);");
  return fprintf(stderr, "string: %s\n", string);
}

int main(int argc, char **argv)
{
  int i;

  for(i = 0; i<1024; i++) {
    fprintf(stderr, "%d\n", i);
    asm("Module.printErr('sp ' + $sp);\n");
  }

  return 0;
}
