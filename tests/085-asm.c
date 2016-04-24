int main(void)
{
  asm volatile("pc = ${label:%=}; case ${labeldef:%=}:");
}
