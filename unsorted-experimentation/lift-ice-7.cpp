extern int fn();

template<class F>
class X {
public:
  template<F f> class Y {};
  void y() {}
  void y(int) {}
  X(F f)
  {
    Y<f> y;

    y.value();
  }
};

int main() { const X<decltype(&fn)> x(fn); }
