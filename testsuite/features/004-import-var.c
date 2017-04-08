extern int x __attribute__((import("sys")));

#include <stdio.h>

int main(void)
{
  printf("%p\n", &x);
  printf("%d\n", x);

  return 0;
}
