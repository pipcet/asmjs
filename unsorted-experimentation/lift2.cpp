#include <tuple>
#include <typeinfo>
#include <stdio.h>

template<typename... Ts>
class PTuple {
public:
  typedef std::tuple<Ts *...> tt;
  std::tuple<Ts *...> t;

  template<size_t ...S>
  PTuple(std::tuple<Ts...> *v, std::index_sequence<S...>)
    : t(&std::get<S>(*v)...)
  {
  }

  PTuple(std::tuple<Ts...> *v)
    : t(PTuple(v, std::index_sequence_for<Ts...>()).t)
  {
  }

  template<size_t ...S>
  PTuple(void **ptrs, std::index_sequence<S...>)
    : t((typename std::remove_reference<decltype(std::get<S>(t))>::type)ptrs[S]...)
  {
  }

  PTuple(void **ptrs)
    : t(PTuple(ptrs, std::index_sequence_for<Ts...>()).t)
  {
  }

  template<size_t ...S>
  std::tuple<Ts...>
  deref(std::index_sequence<S...>)
  {
    return std::tuple<Ts...>(*std::get<S>(t)...);
  }

  std::tuple<Ts...>
  deref()
  {
    return deref(std::index_sequence_for<Ts...>());
  }
};

template<typename... Ts>
PTuple<Ts...>
ptuple(std::tuple<Ts...> *v)
{
  return PTuple<Ts...>(v);
}

template<typename F, typename PTuple, size_t ...S>
decltype(auto) apply(F&& f, PTuple&& t, std::index_sequence<S...>)
{
  return f(std::get<S>(t.deref())...);
}

template<typename F, typename PTuple>
decltype(auto) apply(F&& f, PTuple&& t)
{
  std::size_t constexpr n = std::tuple_size<typename std::remove_reference<PTuple>::type::tt>::value;
  return apply(f, t, std::make_index_sequence<n>());
}

template<typename F>
class Lift {
  static constexpr F *f0 = 0;
public:
  F f;

  Lift(F f)
    : f(f)
  {
  }

  template<typename... Ts>
  decltype(auto)
  operator() (void *ptrs[sizeof...(Ts)], auto (*fi)(Ts...))
  {
    PTuple<Ts...> pt(ptrs);
    return (*this)(pt);
  }

  template<typename... Ts>
  decltype(auto)
  operator() (void *ptrs[sizeof...(Ts)], auto (*fi)(Ts..., ...))
  {
    PTuple<Ts...> pt(ptrs);
    return (*this)(pt);
  }

  template<typename... Ts>
  decltype(auto)
  operator() (void *ptrs[sizeof...(Ts)])
  {
    return (*this)(ptrs, f);
  }

  template<typename... Ts>
  decltype(auto)
  operator() (PTuple<Ts...> t)
  {
    return apply(f, t);
  }
};

template<typename F>
Lift<F> lift(F f)
{
  return Lift<F>(f);
}

typedef void (*lifted)(void **, void*);

template<typename F, F f>
void lift2(void *ptrs[], void *retp)
{
  auto ret = lift(f)(ptrs);

  if (retp)
    *(decltype(ret) *)retp = ret;
}

template<typename F>
constexpr
inline
__attribute__((always_inline))
lifted lift2b(F f0)
{
  return &lift2<F,f0>;
}

template<typename F>
inline
__attribute__((always_inline))
auto lift3(F f)
{
  auto ret = lift2<F,f>;

  return ret;
}

template<typename R, typename...As>
void lift4(void *ptrs[], void *retp, R (*f)(As...))
{
  R ret = lift(f)(ptrs);

  if (retp)
    *(R *)retp = ret;
}

template<typename R, typename...As>
void lift4(void *ptrs[], void *retp, R (*f)(As..., ...))
{
  R ret = lift(f)(ptrs);

  if (retp)
    *(R *)retp = ret;
}

template<typename F>
class Lift7 {
public:
  constexpr
  inline
  __attribute__((always_inline))
  Lift7(F f)
  {
  }

  template<F f>
  class Lift8 {
public:
    constexpr
    inline
    __attribute__((always_inline))
    Lift8(F f0)
    {
    }

    static constexpr auto
    lifted()
    {
      auto l = lift2<F,f>;

      return l;
    }
  };

  constexpr
  inline
  __attribute__((always_inline))
  auto
  lift7(F f)
  {
    return Lift8<*f>(f);
  }

};

template<typename F>
constexpr
inline
__attribute__((always_inline))
Lift7<F>
lift7(F f)
{
  return Lift7<F>(f).lift7(f);
}

template<typename F>
class Lift5B {
  virtual lifted lfted();
};

template<typename F, F f>
class Lift5 : public Lift5B<F> {
  static constexpr F f0 = f;
public:
  constexpr
  Lift5()
  {
  }

  virtual
  inline
  __attribute__((always_inline))
  lifted
  lfted()
  {
    auto l = lift2<F,f>;

    return l;
  }
};

template<typename F, F f>
constexpr
inline
__attribute__((always_inline))
auto
lift6(F f0)
{
  return lift2b(f0);
}

template<void *f>
constexpr
inline
__attribute__((always_inline))
lifted
lift9()
{
  return lift2<typeid(*f), f>;
}

template<class F>
class Y {
public:
  Y(F f)
  {
  }

  template<F f1> class X {
public:
    X(F f = f1)
    {
    }
    
    lifted value()
    {
      return lift2<F, f1>;
    }
  };

  template<F f1>
  X<f1>
  x(F f = f1)
  {
    return X<f1>(f);
  }


  constexpr
  inline
  __attribute__((always_inline))
  lifted
  lifta(F f)
  {
    X<f> x;

    return x.value();
  }
};

template<class F>
Y<F>
y(F f)
{
  return Y<F>(f);
}

#define z(F) y(F).x<F>()

class Lifter {
public:
  Lifter()
  {
    std::tuple<const char *, int> t("%d\n", 17);

    lift(printf)(ptuple(&t));

    const char *s = "hello world";
    void *p1 = &s;
    void *pp[1] = { p1 };

    lift(puts)(pp);
    void (*f)(void **, void *) = lift2<decltype(&puts),puts>;
    auto f2 = lift2<decltype(&fwrite),fwrite>;
    printf("%p\n", f);
    printf("%s\n", typeid(f2).name());

    f(pp, nullptr);

    lift4(pp, nullptr, puts);
    //lift4(pp, nullptr, printf);

    //printf("%p %s\n", lift6(puts), typeid(lift6(puts)).name());

    Lift5<decltype(&fwrite),fwrite>();

    //printf("%p\n", lift7(fwrite));
    //.Lift8<fwrite>::lifted());
    
    lifted f3 = lift2<decltype(&fwrite),fwrite>;
    //lifted f6 = lift6<decltype(&fwrite),fwrite>(fwrite);

    y(fwrite).x<fwrite>();
    z(fwrite);
    y(fwrite).lifta(fwrite);
  }
};

static Lifter __lifter;

int main() {}
