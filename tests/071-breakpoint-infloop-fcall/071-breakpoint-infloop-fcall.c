#include <stdio.h>

extern void asmjs_breakpoint(void);
extern int breakpoint3(void);

void g(void)
{
  printf("g\n");
}

void f(void)
{
  printf("f\n");
  g();
}

int main(void)
{
  int ret = 42;

  //asmjs_breakpoint();
  breakpoint3();

  while (1) {
    f();
    fflush(stdout);
  }
}
