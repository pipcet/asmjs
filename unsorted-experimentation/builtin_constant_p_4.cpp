#include <string>
#include <stdio.h>
#include <string.h>

#define always_inline __attribute__((always_inline))
always_inline
constexpr const char * const
concat()
{
  return "";
}

template<typename strtype, typename... strtypes>
always_inline
constexpr const char * const
concat(strtype str, strtypes... strs)
{
  const char *str1 = concat(strs...);
  return __builtin_concat(str, str1);
}

int main()
{
  constexpr const char * const str1 = "xxx";
  constexpr const char * const str2 = "yyy";
  const char * const str = concat(str1, str2, "xxx", "yyy", "zzz");

  asm(&str[0]);
}
