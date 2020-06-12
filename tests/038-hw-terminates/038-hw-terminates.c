#include <stdio.h>

int main(void)
{
  int ret = 42;

  while (ret < 10000000)
    ret += printf("hello world: %d\n", ret);
}
