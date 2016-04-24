int import()
{
  asm volatile("return foreign_extcall(0xdeadbeef, pc|0, sp|0);");
  
  return 0;
}
