#include <experimental/any>

using std::experimental::any;

template<typename R, typename... Ts>
class FPtr {
public:
  R (*f)(Ts...);

  FPtr(R (*f)(Ts...))
    : f(f)
  {
  }
};

template<typename F, F f>
class Foo {
};

template<typename R, typename ...S, FPtr<R,S...> x>
Foo<decltype(x.f),x.f>
foo()
{
  return Foo<x.f,x.f>();
}

int (*x)() = nullptr;
int main()
{
  foo<&x>();
}
