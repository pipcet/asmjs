#include <tuple>
#include <stdio.h>

template<typename T>
class VPtr {
  T *ptr;
  size_t size;
public:
  VPtr(T *ptr, size_t size)
    : ptr(ptr),size(size)
  {
  }
};

class VPtrs {
  VPtr<void> ps[];
};

template<typename... Ts>
class PTuple {
public:
  typedef std::tuple<VPtr<Ts>...> tt;
  tt t;

  template<size_t ...S>
  PTuple(std::tuple<Ts...> *v, std::index_sequence<S...>)
    : t(VPtr(&std::get<S>(*v), sizeof(std::get<S>(*v)))...)
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

template<typename F, F f>
void lift2(void *ptrs[], void *retp)
{
  auto ret = lift(f)(ptrs);

  if (retp)
    *(decltype(ret) *)retp = ret;
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
    printf("%p\n", f2);

    f(pp, nullptr);

    lift4(pp, nullptr, puts);
    lift4(pp, nullptr, printf);
  }
};

static Lifter __lifter;

int main() {}
