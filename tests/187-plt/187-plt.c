#include <stdio.h>

int main(void)
{
  void *f = printf;
  asm("" : "+r" (f));
  if (f)
    printf("hi\n");

  return 0;
}
