#include <stdio.h>

int g(void)
{
  fprintf(stderr, "ra(g): %p %p %p\n",
          __builtin_return_address (0),
          __builtin_return_address (1),
          __builtin_return_address (2));

  return 0;
}

int f(void)
{
  fprintf(stderr, "ra(f): %p %p %p\n",
          __builtin_return_address (0),
          __builtin_return_address (1),
          __builtin_return_address (2));

  g();

  return 0;
}

int main(void)
{
  f();
  return 0;
}
