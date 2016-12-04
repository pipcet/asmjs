int x = 42;

int g(void)
{
  return x;
}
#include <stdio.h>

extern int g(void);

int main(void)
{
  printf("%d\n", g());
}
