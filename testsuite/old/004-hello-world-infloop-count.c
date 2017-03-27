#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

extern int breakpoint3();

int main(void)
{
  int ret = 42;

  while (1)
    ret += printf("hello world: %d\n", ret);
}
