#include <functional>
extern int fn();

template<class R, class...Args>
class X {
public:
  template<std::function<R(Args...)> f>
  class Y {
    
  };
};

int main() { const X<decltype(&fn)> x(fn); }
