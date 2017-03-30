int main(void)
{
  volatile char str[2];

  str[0] = '!';
  str[1] = 0;
  asm volatile("(call_import $extcall %O0 (i32.const 0) (i32.const 0) (i32.const 0))" : : "r" (str));

  return 0;
}
