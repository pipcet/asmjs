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

template<class F>
class Y {
public:
  Y(F f)
  {
  }

  template<F f1> class X {
  };

  template<F f1>
  X<f1>
  x(F f = f1)
  {
    return X<f1>(f);
  }


  lifted
  lifta(F f)
  {
    X<f> x;

    return x.value();
  }
};

class Lifter {
public:
  Lifter()
  {
    Y<decltype(&fwrite)>(fwrite).lifta(fwrite);
  }
};

