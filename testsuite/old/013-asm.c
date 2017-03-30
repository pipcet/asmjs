int main(void)
{
  asm("\n\n/* %0 %1 */\n"
      :
      : "p"(0), "P"(0));

  return 0;
}
