int main(void)
{
  volatile int a, b, c;

  c = a + b;
  c = a - b;
  c = a << b;
  c = a >> b;
  c = a != b;
  c = a == b;
  c = a * b;
  b = 1;
  c = a % b;
  c = a / b;

  return c;
}
