asm("\t.pushsection .str.lib,\"ams\",1\n"
    "\t.data\n"
    "\t__str_name:\n"
    "\t.ascii \"extname\"\n"
    "\t.byte 0\n"
    "\t__str_module:\n"
    "\t.ascii \"module\"\n"
    "\t.byte 0\n");

int syscall(void)
{
  int res = 0;
  do
    asm volatile("i32.const __str_name\n\tset_local $r0\n\t"
                 "i32.const __str_module\n\tset_local $r1\n\t"
                 "get_local $pc0\n\t"
                 ".dpc .LLimp\n\t"
                 "tee_local $dpc\n\t"
                 "get_local $sp\n\t"
                 "get_local $r0\n\t"
                 "get_local $r1\n\t"
                 "i32.const 3\n\t"
                 "call $syscall\n\t"
                 ".labeldef_internal .LLimp\n\t"
                 "%R0\n\t"
                 : "=r" (res));
  while (res&3);

  return 0;
}
