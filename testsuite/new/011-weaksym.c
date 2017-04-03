asm("createsig FiiE");

extern int f(int) __attribute__((weak)) __attribute__((rawcall));

int main(void)
{
  void (*g)(void) = 0;

  g();
}
