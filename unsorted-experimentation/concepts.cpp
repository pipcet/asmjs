template<typename T>
  class foo {
    T* p;

  template<>
  requires __is_class(T)
    long offset(int T::* ptm) {
      T* ptr = nullptr;
      return (long)&(ptr->*ptm);
    }
  };

struct S {
};

int main(void)
{
  foo<S> F;
  foo<int> F2;
}
