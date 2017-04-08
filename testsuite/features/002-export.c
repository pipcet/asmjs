int f(int x)
{
  return 0;
}

int f(int) __attribute__((export));

int x __attribute__((export("y")));

int main(void)
{
  return 0;
}
