#include <stdio.h>
#include <unistd.h>

extern int __thinthin_write (int, void *, int) __attribute__((stackcall));

int main(void)
{
  int i;
  for (i = 0; i < 5; i++)
    __thinthin_write(1, "hi there\n", 9);
  for (i = 0; i < 5; i++)
    write(1, "bye there\n", 10);
  for (i = 0; i < 5; i++)
    fprintf(stderr, "hello again\n");
}
