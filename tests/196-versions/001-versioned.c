asm(".symver foo,versioned@@VERS_1.0");

int foo(void)
{
  printf("in foo\n");
}
