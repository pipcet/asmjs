extern int __wrap_write(int, const char *, int) __attribute__((stackcall));

void _start(void)
{
  __wrap_write(1, "hi there\n", strlen("hi there\n"));
}
