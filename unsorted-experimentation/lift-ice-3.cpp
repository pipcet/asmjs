extern int fn();

template<class F>
class X {
public:
  template<F f> class Y {};
  template<F f> void y() {}
  X(F f)
  {
    Y<"hi"> y;

    y.value();
  }
};

int main() { const X<decltype(&fn)> x(nullptr); }
