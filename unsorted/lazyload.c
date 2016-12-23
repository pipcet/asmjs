extern void lazyload2(long index);

void lazyload(long arg0, long arg1)
{
  long index;
  asm volatile("%S0\n\ti32.const 0xdeadbeef\n\t%R0" : "=rmt" (index));
  lazyload2(index);
  void (*f)(long, long) = (void *)index;
  f(arg0, arg1);
}
