#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

#define always_inline __attribute__((always_inline))

class ccc {
public:
  const char * const c;
  always_inline
  ccc(const char *c)
    : c(c)
  {
  }

  always_inline
  const char *ptr() __restrict__
  {
    return c;
  }
};

const char *global_string = "0";

int main()
{
  ccc c = ccc("0");

  while (!__builtin_constant_p(c.c))
    std::cout << "what?\n";
}
