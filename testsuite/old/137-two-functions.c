int f(void)
{
  volatile int x;

  x++;
  x++;
  x++;

  return x;
}

int main(void)
{
  return 0;
}
