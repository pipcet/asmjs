#include <setjmp.h>

extern int __dummy(__jmp_buf, int);

int __my_setjmp(__jmp_buf buf)
{
  return __dummy(buf, 0);
}

void __my_longjmp(__jmp_buf buf, int value)
{
  __dummy(buf, value);
  return;
}
