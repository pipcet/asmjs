extern int __wrap_write(int, const char *, int) __attribute__((stackcall));

void _start(void)
{
  volatile int x = 0;
  while(++x < 65000);
  {
    volatile int z1, z2, z3;
    z1 += z2 * z3;
  }
  __wrap_write(1, "hi there\n", strlen("hi there\n"));
  for(;;);
}
