extern void f(void) __attribute__((weak));

int main(void)
{
  if (f)
    f();
}
