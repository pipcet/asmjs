void _start(void)
{
  volatile char x = 0;

  while (++x)
    asm volatile("%0\n\t%0\n\t%0\n\t%0\n\tcall_import[4] $extcall"
                 : : "r" (0xdeadbeef));
}
