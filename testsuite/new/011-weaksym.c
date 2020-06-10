extern int f(int) __attribute__((weak));

int main(void)
{
  int (*g)(int) = f;

  g(0);
}
