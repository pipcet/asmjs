template<class T, T a> class X {
  T x;
  int i;
};

X<int X::*,&X::x> x;
