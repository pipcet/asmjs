#include <string>
#include <stdio.h>

int main()
{
  constexpr const char * const str = "ab";
  
  printf("%d\n", __builtin_constant_p(str));
}
