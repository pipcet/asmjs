#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

extern int breakpoint3();

int f(int) __attribute__((rawcall));
int f(int x) {
  return 42;
}

int main(void)
{
  int (*f2)(int) __attribute__((rawcall));
  f2 = (volatile void *)f;
  int ret = f(41);
  ret = f2(43);

  while (1)
    ret += printf("hello world: %d\n", ret);
}
