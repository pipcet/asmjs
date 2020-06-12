#include <setjmp.h>
#include <stdio.h>

jmp_buf env;

int dummy(void)
{
    longjmp(env, 1);
}

int main(void)
{
  printf("about to setjmp\n");
  fflush(stdout);
  printf("fp %p\n", __builtin_frame_address(0));
  if (setjmp(env)) {
    printf("second return\n");
  } else {
    printf("first return\n");
    fflush(stdout);
    dummy();
    printf("notreached\n");
  }

  return 0;
}
