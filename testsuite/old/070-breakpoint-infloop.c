#include <stdio.h>

extern void asmjs_breakpoint(void);
extern int breakpoint3(void);

int main(void)
{
  int ret = 42;

  //asmjs_breakpoint();
  breakpoint3();

  while (1) {
    ret += printf("hello world: %d\n", ret);
    fflush (stdout);
  }
}
