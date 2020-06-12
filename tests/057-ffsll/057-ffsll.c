#include <stdio.h>
#include <strings.h>

int main(void)
{
  for (int i = 0; i != 0xffffffff; i++) {
    printf("%d %d\n", i, __builtin_ffsll(i));
  }

  return 0;
}
