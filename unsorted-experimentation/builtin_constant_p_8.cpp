#include <iostream>
//#include <string>
#include <stdio.h>
#include <string.h>

#define always_inline __attribute__((always_inline))
int gexpression;

class JSX2 {
public:
  const char * const expression;

  inline
  constexpr JSX2(const char *str)
  always_inline
    : expression(str)
  {
  }

  inline
  always_inline
  operator const int() const
  {
    asm volatile(expression : : "i" (__builtin_constant_p("0")));

    return 0;
  }
};

const char * const str0 = "0123456789";

extern const char *savestring;
extern const char * const *savestring2;
  
int main()
{
  const JSX2 nul("17f");
  constexpr const char * const str1 = "xxx";
  constexpr const char * const str2 = "yyy";

  //asm(str);

  (int)(nul);

  return 0;
}
