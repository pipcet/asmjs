#include <stdio.h>

int main(void)
{
  int f(int x)
  {
    return x+1;
  }
  printf ("%p\n", f);
  main();
}
