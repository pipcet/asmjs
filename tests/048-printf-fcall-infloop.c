#include <stdio.h>

int f(int count)
{
  return printf("hi %d\n", count);
}

int main(void)
{
  int x = 0;

  while (1)
    x += f(x);
}
