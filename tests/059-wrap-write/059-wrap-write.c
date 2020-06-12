#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* first test linking with glibc */

int my_errno = 0;

int *__errno_location(void)
{
  return &my_errno;
}

void *__emutls_get_address(void)
{
  return 0xdeadbeef;
}

extern ssize_t __wrap_write(int, void *, ssize_t);

int main(void)
{
  int ret = 42;
  char buf[1024];

  while (ret == 42) {
    ret += sprintf(buf, "hello world: %d\n", ret, 1.0/0.0, 3.5);
    __wrap_write(1, buf, strlen(buf));
  }

  return 0;
}
