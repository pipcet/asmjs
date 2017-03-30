extern unsigned long gdbstub_entry(void *sp, unsigned long rv);

int g(void)
{
  return gdbstub_entry(__builtin_frame_address(0), 0);
}

int f(void)
{
  return g();
}

int main(void)
{
  return f();
}
