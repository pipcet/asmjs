#define _GNU_SOURCE
#define _GLIBCXX_USE_C99_STDIO 1
#include <stdio.h>
#include <typeinfo>
#include <string.h>
#include <tuple>
#include <string>
#include <ext/vstring.h>
#include <bitset>
#include <bits/basic_string.h>
#include <cxxabi.h>
#include <stdlib.h>
#include <type_traits>

const char *demangle(const std::type_info *info)
{
  int status;
  const char *ret = __cxxabiv1::__cxa_demangle(info->name(), NULL, NULL, &status);

  if (status)
    throw "bad";

  return ret;
}

template<class T>
requires(std::is_integral<T>::value || std::is_floating_point<T>::value)
T from_double(double d)
{
  T ret = T(d);

  if (double(ret) != d)
    throw "round-trip conversion failed";

  return ret;
}

template<class T>
requires(std::is_pointer<T>::value)
T from_double(double d)
{
  T ret = T(size_t(d));

  if (double(size_t(ret)) != d)
    throw "round-trip conversion failed";

  return ret;
}

template<class ...Ts, size_t ...S>
std::tuple<Ts...>
from_doubles(double *d, std::index_sequence<S...>)
{
  return std::tuple<Ts...>(from_double<typename std::tuple_element<S, std::tuple<Ts...>>::type>(d[S])...);
}

template<class ...Ts>
std::tuple<Ts...>
from_doubles(double *d)
{
  return from_doubles<Ts...>(d, std::index_sequence_for<Ts...>());
}

template<typename F, typename ATuple, size_t ...S>
decltype(auto) tuple_apply(F&& f, ATuple&& t, std::index_sequence<S...>)
{
  return f(std::get<S>(t)...);
}

template<typename F, typename ATuple>
decltype(auto) tuple_apply(F&& f, ATuple&& t)
{
  std::size_t constexpr n = std::tuple_size<typename std::remove_reference<ATuple>::type>::value;
  return tuple_apply(f, t, std::make_index_sequence<n>());
}

template<class R, class ...Ts>
class Lift {
public:
  R (*f)(Ts...);
  const char *t;
  typedef R F(Ts...);

  static void apply_doubles(F f1, const char *t1, double *d)
  {
    d[0] = tuple_apply(f1, from_doubles<Ts...>(d+1));
  }

  Lift(F f)
    : f(f), t(typeid(*f).name())
  {
    printf("registering f %p type %s apply %p\n",
           f, demangle(&typeid(*f)), apply);
  }
};

template<class ...Ts>
class Lift<void,Ts...> {
public:
  void (*f)(Ts...);
  const char *t;
  typedef void F(Ts...);

  static void apply_doubles(F f1, const char *t1, double *d)
  {
    d[0] = 0;
    tuple_apply(f1, from_doubles<Ts...>(d+1));
  }

  Lift(F f)
    : f(f), t(typeid(*f).name())
  {
    printf("registering f %p type %s apply %p\n",
           f, demangle(&typeid(*f)), apply);
  }
};

template<class R, class ...Ts>
Lift<R, Ts...> lift(R f(Ts...))
{
  return Lift<R, Ts...>(f);
}
