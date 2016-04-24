#include <stdio.h>
extern int signal(int, int);
int main(void)
{
  signal(8, 1);
  signal(8, 1);
  signal(8, 1);
  signal(8, 1);
  signal(8, 1);
  signal(8, 1);
  signal(8, 1);
  signal(8, 1);
  signal(8, 1);

  puts("done");
  return 0;
}
