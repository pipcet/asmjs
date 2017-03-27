#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

extern int breakpoint3();

asm("createsig FiiE");

asm(".globl f\n\t"
    "defun f FiiE\n\t"
    "get_local 0\n\t"
    "get_local 0\n\t"
    "i32.add\n\t"
    "return\n\t"
    "end\n\t"
    "endefun f\n\t");

int f(int) __attribute__((rawcall));

int main(void)
{
  int (__attribute__((rawcall)) *f2)(int) ;
  f2 = (volatile void *)f;
  int ret = f(41);

  while (1)
    ret += printf("hello world: %d\n", ret);
}
