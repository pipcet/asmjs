int main(void)
{
  const char *str = "hello world\n";

  asm volatile("(call_import $extcall %O0 (i32.const 0) (i32.const 0) (i32.const 0))" : : "r" (str));

  return 0;
}
