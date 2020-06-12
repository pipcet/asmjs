#include <setjmp.h>
#include <stdio.h>

extern int __my_setjmp(jmp_buf);
extern void __my_longjmp(jmp_buf, int);

int my_setjmp(jmp_buf env)
{
  return __my_setjmp(env);
}

void my_longjmp(jmp_buf env, int value)
{
  __my_longjmp(env, value);
}

int main(void)
{
  jmp_buf env;
  printf("about to setjmp\n");
  fflush(stdout);
  printf("fp %p\n", __builtin_frame_address(0));
  if (my_setjmp(env)) {
    printf("second return\n");
  } else {
    printf("first return\n");
    fflush(stdout);
    my_longjmp(env, 1);
    printf("notreached\n");
  }

  return 0;
}
