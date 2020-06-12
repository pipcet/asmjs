#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int g(void)
{
  fprintf(stderr, "bra: %p\n", __builtin_return_address(0));

  return g();
}

int main(void)
{
  for (;;) {
    write(1, "hi\n", 3);
    int count = fprintf(stderr, "hey there: %p %p\n", stdout, stderr);
    g();
    break;
  }
}
