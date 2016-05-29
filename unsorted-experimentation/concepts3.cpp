#include <iostream>

template<typename T, typename S>
class ptm {
};

template<typename T, typename S>
requires __is_class(T)
class ptm<T,S> {
public:
  S T::* x;

  ptm<T,S>
  (S T::* x)
  : x(x)
  {
  }
};

template<typename T>
class foo {
};

template<typename T>
requires __is_class(T)
class foo<T> {
public:
  T* p;

  template<typename S>
  long offset(S T::* x) {
    T* ptr = nullptr;
    return (long)&(ptr->*(x));
  }
};

template<typename T>
requires !__is_class(T)
class foo<T> {
public:
  T* p;

  long offset(T *ptr2 = nullptr)
  {
    ptr2 = nullptr;
    return (long)ptr2;
  }
};

struct St {
  int m;
};

int main(void)
{
  foo<St> F;
  foo<int> G;

  std::cout << F.offset(&St::m) << "\n";

  std::cout << G.offset() << "\n";
}
