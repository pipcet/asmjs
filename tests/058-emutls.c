#include <stdio.h>

/* first test linking with glibc */

int my_errno = 0;

int *__errno_location(void)
{
  return &my_errno;
}

void *__emutls_get_address(void)
{
  return NULL;
}

int main(void)
{
  int ret = 42;

  while (ret == 42)
    ret += _IO_printf("hello world: %d %f %f\n", ret, 1.0/0.0, 3.5);

  fflush (stdout);

  return 0;
}
