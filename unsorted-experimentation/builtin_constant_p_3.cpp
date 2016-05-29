#include <string>
#include <stdio.h>
#include <string.h>

int main()
{
  constexpr const char * const str1 = "xxx";
  constexpr const char * const str2 = "yyy";
  const char * const str = __builtin_concat(str1, str2);

  asm(&str[0]);
}
