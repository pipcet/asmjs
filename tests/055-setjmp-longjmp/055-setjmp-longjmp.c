#include <setjmp.h>
#include <stdio.h>

extern int __wrap_setjmp(jmp_buf);
extern void __wrap_longjmp(jmp_buf, int);

int main(void)
{
  jmp_buf env;
  printf("about to setjmp\n");
  fflush(stdout);
  printf("fp %p\n", __builtin_frame_address(0));
  if (__wrap_setjmp(env)) {
    printf("second return\n");
  } else {
    printf("first return\n");
    __wrap_longjmp(env, 1);
    printf("notreached\n");
  }

  return 0;
}
