void f(void)
{
  __builtin_eh_return(0xdeadbeef, 0xc0dec0de);
}

int main(void)
{
  f();

  return 0;
}
