#include <stdio.h>
extern int signal(int, int);

void f(void)
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
}

int main(void)
{
  f();
  f();

  return 0;
}
