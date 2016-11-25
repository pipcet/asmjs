#include <stdio.h>

extern int __thinthin_write (int, void *, int) __attribute__((stackcall));

int main(void)
{
  int i;
  for (i = 0; i < 5; i++)
    __thinthin_write(1, "hi there\n", 9);
}
