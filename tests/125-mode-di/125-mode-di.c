extern int f(void * __attribute__((mode(DI))) p, unsigned long long x);

int main(void)
{
  f((void *)0xdeadbeef, 0x12345678);

  return 0;
}
         
