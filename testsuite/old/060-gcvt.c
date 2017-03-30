#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* first test linking with glibc */

int my_errno = 0;

int *__errno_location(void)
{
  return &my_errno;
}

void *
__emutls_get_address (struct __emutls_object *obj)
{
#if 0
  if (! __gthread_active_p ())
    {
      if (__builtin_expect (obj->loc.ptr == NULL, 0))
	obj->loc.ptr = emutls_alloc (obj);
      return obj->loc.ptr;
    }

  abort ();
#endif
}

extern ssize_t __wrap_write(int, void *, ssize_t);

int __unorddf2(double a, double b)
{
  return 0;
}

int main(void)
{
  int ret = 42;
  char buf[1024];
  char buf2[1024];

  while (ret == 42) {
    ret += sprintf(buf, "hello world: %f %s\n", 1.0/3.0, gcvt(3.5, 10, buf2));
    __wrap_write(1, buf, strlen(buf));
  }

  return 0;
}
