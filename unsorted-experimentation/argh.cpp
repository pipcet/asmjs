template<typename T>
class offsets {
  template<typename S>
  requires(__is_class(T))
  unsigned long offset(S T::* x)
  {
    return 42;
  }
};

int main(void)
{
  offsets<int> x;
}
