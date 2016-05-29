#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

#define always_inline __attribute__((always_inline))
always_inline
constexpr const char * const
paste()
{
  return "";
}

template<typename strtype, typename... strtypes>
always_inline
constexpr const char * const
paste(strtype str, strtypes... strs)
{
  const char *str1 = paste(strs...);
  return __builtin_concat(str, str1);
}

template<typename T>
class JSX {
  const char * const expression;
public:

  always_inline
  JSX(const char str[])
    : expression(str)
  {
  }

  always_inline
  operator const T() const
  {
    T x;
    const char * const e = expression;

    if (__builtin_constant_p(expression) == 0)
      for(;;)
        std::cout << "what?\n";

    //asm(paste("%0 = ", &e[0], ";") : "=m" (x));

    return x;
  }
};

class JSX2 {
  const char * const expression;
public:

  always_inline
  JSX2(const char str[])
    : expression(str)
  {
  }

  always_inline
  operator const int() const
  {
    const char * const e = expression;

    std::cout << __builtin_concat(e,e) << "\n";

    if (__builtin_constant_p(expression) == 0)
      for(;;)
        std::cout << "what?\n";

    //asm(paste("%0 = ", &e[0], ";") : "=m" (x));

    return 0;
  }
};

const char * const str0 = "0";

always_inline
const char *
to_string(const int *x)
{
  return "XXX";
}

always_inline
const char *
to_string(const int x)
{
  return "XXX";
}

int main()
{
  constexpr const char * const str1 = "xxx";
  constexpr const char * const str2 = "yyy";
  const char * const str = paste(str1, str2, "xxx", "yyy", "zzz");

  //asm(&str[0]);

  const JSX2 nul(str1);
  
  std::cout << to_string(nul) << "\n";
  
  return 0;

  register const JSX<int *> null(str1);

  std::cout << to_string(null) << "\n";
}
