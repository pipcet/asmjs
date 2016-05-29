#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

#define always_inline __attribute__((always_inline))

class ccc {
  const char * const c;
  std::size_t sz;
public:
  template<std::size_t N>
  constexpr ccc(const char (&c)[N])
    : c(c), sz(N-1)
  {
  }

  constexpr const char *ptr() const
  {
    return c;
  }

  constexpr int
  test() const
  {
    return __builtin_constant_p(ptr());
  }
};


// literal class
class conststr {
    const char* p;
    std::size_t sz;
public:
    template<std::size_t N>
    constexpr conststr(const char(&a)[N]): p(a), sz(N - 1) {}
 
    // constexpr functions signal errors by throwing exceptions
    // in C++11, they must do so from the conditional operator ?:
    constexpr char operator[](std::size_t n) const
    {
        return n < sz? p[n] : throw std::out_of_range("");
    }
    constexpr std::size_t size() const { return sz; }
};

const char * const const_string = "0";

int main()
{
  while (!__builtin_constant_p("0"))
    std::cout << "oh!\n";

  //while (!__builtin_constant_p(const_string))
  //  std::cout << "oh 2!\n";

  constexpr ccc c("0");

  while (!c.test())
    std::cout << "what?\n";
}
