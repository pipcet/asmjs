#include <tuple>
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
auto lift2(void *ptrs[])
{
  return lift(f)(ptrs);
}

template<typename F>
inline
__attribute__((always_inline))
auto lift3(F f)
{
  auto ret = lift2<F,f>;

  return ret;
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
    auto (*f)(void **) = lift2<decltype(&puts),puts>;
    auto f2 = lift2<decltype(&fwrite),fwrite>;
    printf("%p\n", f);
    printf("%p\n", f2);

    f(pp);
  }
};

static Lifter __lifter;

int main() {}
