#include <stdio.h>

int f(int a, int b)
{
  return 2 * a - b;
}

int main(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7)
{
  asm("Module.print('in main, sp is ' + sp + ' bp is ' + fp);");
  asm("Module.print('' + HEAP32[(sp+32)>>2]);");
  asm("Module.print('' + HEAP32[(fp+20)>>2]);");
  fprintf(stderr, "arg0: %d\n", arg0);
  fprintf(stderr, "arg1: %d\n", arg1);
  fprintf(stderr, "arg2: %d\n", arg2);
  fprintf(stderr, "arg3: %d\n", arg3);
  fprintf(stderr, "arg4: %d\n", arg4);
  fprintf(stderr, "arg5: %d\n", arg5);
  fprintf(stderr, "arg6: %d\n", arg6);
  fprintf(stderr, "arg7: %d\n", arg7);

  return 0;
}
