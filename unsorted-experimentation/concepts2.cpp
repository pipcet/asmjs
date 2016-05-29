template<typename T> concept bool ptmable =
  requires(auto T::* a) {
  a;
  };

struct S {
};

bool
f(ptmable s)
{
  int typeof(s)::* x;
}
