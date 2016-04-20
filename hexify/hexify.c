#include <stdio.h>

int main(void)
{
  int c;
  int i = 0;
  while ((c = getchar()) != EOF) {
    printf("0x%02x,%s", c, ((i++&31) == 31) ? "\n" : "");
  }

  return 0;
}
