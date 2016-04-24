#include <setjmp.h>
#include <stdio.h>

int main(void)
{
  jmp_buf env;
  printf("about to setjmp\n");
  fflush(stdout);
  printf("fp %p\n", __builtin_frame_address(0));
  if (setjmp(env)) {
    printf("second return\n");
  } else {
    printf("first return\n");
    fflush(stdout);
    longjmp(env, 1);
    printf("notreached\n");
  }

  return 0;
}
