#include <string>
#include <stdio.h>
#include <string.h>

int main()
{
  constexpr const char * const str1 = "xxx";
  constexpr const char * const str2 = "yyy";
  char str[1024];
  char *p = str;
  p = strcpy(p, str1);
  p = strcpy(p, str2);

  asm(&str[0]);
}
