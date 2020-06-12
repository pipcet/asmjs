int main(void)
{
  asm volatile("pc=${label:%=};continue;\n${labeldef:%=}" : : );
}
