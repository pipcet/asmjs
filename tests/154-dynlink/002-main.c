#include <stdio.h>

extern int g(void);

int main(void)
{
  printf("%d\n", g());
}
