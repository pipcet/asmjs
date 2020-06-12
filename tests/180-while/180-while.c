void f(void)
{
  for(;;);
}

int main(void)
{
  volatile int cond;

  while (cond) {
    f();
  }
}
