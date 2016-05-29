/* http://www.cppsamples.com/common-tasks/apply-tuple-to-function.html */
// http://en.cppreference.com/w/cpp/experimental/apply
#include <string>
#include <tuple>
#include <stdio.h>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>

#define always_inline inline __attribute__((always_inline))

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
  JSX(const char *expression)
    : expression(expression)
  {
  }

  always_inline
  operator T() const
  {
    T x;

    asm(paste("%O0 = ", expression, ";")
        : "=rtm" (x));

    return x;
  }
};

int main()
{
  const JSX<unsigned> v0("values[0]");
  
  return unsigned(v0);
}
