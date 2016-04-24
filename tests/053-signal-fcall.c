#include <stdio.h>
extern int signal(int, int);

int f(void)
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

int main(void)
{
  f();
  f();

  return 0;
}
