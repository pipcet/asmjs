extern int fn();
typedef int F();
template<F f> void y() {}
template<F f> class Y {};
class X {
public:
  X(F f)
  {
    Y<f> y;

    y.value();
  }
};

int main() { const X x(fn); }
