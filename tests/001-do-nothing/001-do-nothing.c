#include <stdio.h>

int main(void)
{
  volatile int x = 1;
  if (x != 1) {
    printf("hello world\n");
  }
  return 0;
}
