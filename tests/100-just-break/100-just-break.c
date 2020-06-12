extern unsigned long gdbstub_entry(void *sp, unsigned long rv);

int main(void)
{
  return gdbstub_entry(__builtin_frame_address(0), 0);
}
