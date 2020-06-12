#include <stdio.h>

int main(void)
{
  (void)__builtin_return_address (1);

  fprintf(stderr, "ra: %p\n",
          __builtin_return_address (0),
          __builtin_return_address (1));

  return 0;
}
