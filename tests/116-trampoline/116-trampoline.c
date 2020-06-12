#include <stdio.h>

int f(int (*sum)(void))
{
  return fprintf(stderr, "%d\n", sum());
}

int main(void)
{
  volatile int x = 7;
  volatile int y = 13;
  int sum(void) {
    return x + y;
  }

  f(sum);
}
