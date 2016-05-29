//#include <iostream>
//#include <string>
//#include <stdio.h>
//#include <string.h>

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

  inline JSX(const char *str)
  always_inline
    : expression(str)
  {
  }

  inline
  operator const T() const
  always_inline
  {
    T x;
    const char * const e = expression;

    //if (__builtin_constant_p(expression) == 0)
    //for(;;)
    //std::cout << "what?\n";

    //asm(paste("%0 = ", &e[0], ";") : "=m" (x));

    return x;
  }
};

const char *gexpression;

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
    const char * const e = expression;
    int x = 0;
    
    gexpression = expression;

    //std::cout << __builtin_concat(e,e) << "\n";

    const char * __restrict__ e2 = __builtin_concat(expression, expression);

    while (!__builtin_constant_p(__builtin_strlen(expression)))
      ;//std::cout << "huh.\n";

    while (!__builtin_constant_p(__builtin_concat(expression, "")[0]))
      ;//;std::cout << "oh dear.\n";

    ;//std::cout << expression[0] << "\n";

    asm volatile(expression : "=m" (x));

    return 0;
  }
};

const char * const str0 = "0123456789";

always_inline inline
const char *
to_string(const int *x)
{
  return "XXX";
}

always_inline inline
const char *
to_string(const int x)
{
  return "XXX";
}

extern const char *savestring;
extern const char * const *savestring2;
  
int main()
{
  constexpr JSX2 nul("aaa0123456789");
  constexpr const char * const str1 = "xxx";
  constexpr const char * const str2 = "yyy";
  const char * str = paste(str1, str2, "xxx", "yyy", "zzz");

  //asm(str);

  (int)(nul);

  while (!__builtin_constant_p(nul.expression[0]))
    ;//std::cout << "huh.\n";

  return 0;

  asm volatile(nul.expression : "=m" (str));
  
  return 0;

  register const JSX<int *> null(str1);

  //std::cout << to_string(null) << "\n";
}
