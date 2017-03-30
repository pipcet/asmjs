int main(void)
{
  asm volatile("nextcase\n\ti32.const 1\n\tget_local $fp\n\ti32.or\n\tset_local $rp\n\tthrow");

  return 0;
}
