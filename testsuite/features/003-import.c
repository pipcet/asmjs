//int f(int) __attribute__((import("sys", "g")));
int g(int) __attribute__((import("sys"))) __attribute__((rawcall));

int main(void)
{
  //f(42);

  g(84);

  return 0;
}
