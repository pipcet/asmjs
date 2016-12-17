extern int f(void);

#include <stdio.h>

int main(void)
{
  printf("%d %p\n", f(), f);

  return 0;
}
