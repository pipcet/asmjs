#define always_inline __attribute__((always_inline))

class X {
  const int x;

public:
  inline
  always_inline
  X(int x)
    : x(x)
  {
  }

  inline
  always_inline
  int test() const
  {
    long ret;

    asm volatile("movq %1, %0" : "=r" (ret) : "i" (x));

    return ret;
  }
};

int main(void)
{
  const X x(17);

  return x.test();
}
