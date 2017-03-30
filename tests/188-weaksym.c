asm("createsig FiiE");

extern int f(int) __attribute__((weak)) __attribute__((rawcall));

int main(void)
{
  if (f)
    f(0);
}
