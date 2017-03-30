#include <stdio.h>

extern int f(void) __attribute__((weak));

int main(void)
{
  if (f)
    fprintf(stderr, "%d\n", f());

  return 0;
}
