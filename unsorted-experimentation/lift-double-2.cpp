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

extern "C" {
  int f(int x, unsigned long y)
  {
    return x + y;
  }
};

struct area {
  void *a0;
  void *a1;

  area(void *a0, void *a1)
    : a0(a0), a1(a1)
  {
  }

  area()
    : a0(nullptr), a1(nullptr)
  {
  }

  void dump()
  {
    printf("area [%p-%p]\n", a0, a1);
  }
};

template<class T>
class Area {
  area a;

public:
  Area(T* ptr0, T* ptr1 = nullptr)
    : a({(void *)ptr0, (void *)(ptr1 ? ptr1 : ptr0+1)})
  {
    if (ptr1 != nullptr && ptr1 != ptr0 + 1)
      throw "bad area";
  }

  Area(area a)
    : Area((T*)a.a0, (T*)a.a1)
  {
  }

  operator T*()
  {
    return (T*)a.a0;
  }

  operator area()
  {
    return a;
  }

  void dump()
  {
    printf("Area ");
    printf("[%s] ", typeid(T).name());
    a.dump();
  }
};

template<class T, size_t N>
class ntuple {
public:
  typedef decltype(std::tuple_cat(std::tuple<T>(), typename ntuple<T, N-1>::tuple())) tuple;
};

template<class T>
class ntuple<T,0> {
public:
  typedef std::tuple<> tuple;
};

template<class...Cs>
class aTuple {
public:
  typedef typename ntuple<area, sizeof...(Cs)>::tuple tt;

  tt tuple;

  template<size_t ...S>
  aTuple(area *aptr, std::index_sequence<S...>)
    : tuple(area(aptr[S].a0, aptr[S].a1)...)
  {
    size_t n;
    for (n = 0; aptr[n].a0 != nullptr && n <= sizeof...(Cs)+1; n++);
    if (n != sizeof...(Cs)) {
      printf("bad area pointer. %ld != %ld\n",
             n, sizeof...(Cs));
      throw "bad area pointer. Maybe you were naughty and tried to call a variadic function?";
    }
 }

  aTuple(area *aptr)
    : aTuple(aptr, std::index_sequence_for<Cs...>())
  {
  }
};

struct St {
  int a;
  int b;
  int c;

  static constexpr auto enumeration = std::make_tuple(&St::a, &St::b, &St::c);
};

template<class X, class...Ts, size_t...S>
auto
members(X *st, std::tuple<Ts...> tuple, std::index_sequence<S...>)
{
  return std::make_tuple(st->*std::get<S>(tuple)...);
}

template<class X, class...Ts>
auto
members(X *st, std::tuple<Ts...> tuple)
{
  return members(st, tuple, std::index_sequence_for<Ts...>());
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

template<class T>
size_t doubles2_length()
{
  return 1;
}

template<>
size_t doubles2_length<long long>()
{
  return 2;
}

template<>
size_t doubles2_length<unsigned long long>()
{
  return 2;
}

template<class T>
requires(std::is_integral<T>::value || std::is_floating_point<T>::value)
T from_double2(double *d)
{
  T ret = T(*d);

  if (double(ret) != *d)
    throw "round-trip conversion failed";

  return ret;
}

template<class T>
requires(std::is_pointer<T>::value)
T from_double2(double *d)
{
  T ret = T(size_t(*d));

  if (double(size_t(ret)) != *d)
    throw "round-trip conversion failed";

  return ret;
}

template<>
long long from_double2(double *d)
{
  long long ret = (long long)d[0] + (1LL<<32) * (long long)d[1];

  return ret;
}

template<class ...Ts>
class from_doubles2b {
public:
  static auto from_doubles2(double *d);
};

template<class T, class ...Ts>
class from_doubles2b<T,Ts...> {
public:
  static auto from_doubles2(double *d)
  {
    return std::tuple_cat(std::make_tuple(from_double2<T>(d)),
                          from_doubles2b<Ts...>::from_doubles2(d + doubles2_length<T>()));
  }
};

template<>
class from_doubles2b<> {
public:
  static auto from_doubles2(double *d)
  {
    return std::make_tuple();
  }
};

template<class...Cs>
class ATuple {
public:
  typedef std::tuple<Area<Cs>...> tt;
  typedef std::tuple<Cs...> bare_tuple_type;

  tt tuple;

  template<size_t ...S>
  ATuple(std::tuple<Cs...> *tp, std::index_sequence<S...>)
    : tuple(Area<typename std::remove_reference<decltype(std::get<S>(*tp))>::type>(&std::get<S>(*tp))...)
  {
  }

  ATuple(std::tuple<Cs...> *tp)
    : ATuple(tp, std::index_sequence_for<Cs...>())
  {
  }

  template<size_t ...S>
  ATuple(aTuple<Cs...> at, std::index_sequence<S...>)
    : tuple(Area<typename std::remove_reference<decltype(std::get<S>(bare_tuple_type()))>::type>(std::get<S>(at.tuple))...)
  {
  }

  ATuple(aTuple<Cs...> at)
    : ATuple(at, std::index_sequence_for<Cs...>())
  {
  }

  template<size_t ...S>
  std::tuple<Cs...>
  deref(std::index_sequence<S...>)
  {
    return std::tuple<Cs...>(*std::get<S>(tuple)...);
  }

  std::tuple<Cs...>
  deref()
  {
    return deref(std::index_sequence_for<Cs...>());
  }

  void
  dump(std::index_sequence<>)
  {
  }

  template<size_t s, size_t ...S>
  void
  dump(std::index_sequence<s, S...>)
  {
    printf("[%d] ", (int)s);
    std::get<s>(tuple).dump();
    dump(std::index_sequence<S...>());
  }

  void
  dump()
  {
    return dump(std::index_sequence_for<Cs...>());
  }
};

template<typename...Ts>
ATuple<Ts...>
atuple(std::tuple<Ts...> *t)
{
  return ATuple<Ts...>(t);
}

template<typename F, typename ATuple, size_t ...S>
decltype(auto) atuple_apply(F&& f, ATuple&& t, std::index_sequence<S...>)
{
  return f(std::get<S>(t.deref())...);
}

template<typename F, typename ATuple>
decltype(auto) atuple_apply(F&& f, ATuple&& t)
{
  std::size_t constexpr n = std::tuple_size<typename std::remove_reference<ATuple>::type::tt>::value;
  return atuple_apply(f, t, std::make_index_sequence<n>());
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

  static void apply_doubles2(F f1, const char *t1, double *d)
  {
    d[0] = tuple_apply(f1, from_doubles2b<Ts...>::from_doubles2(d+1));
  }

  static void apply(F f1, const char *t1, area *params)
  {
    Area<R> retarea(params[0]);
    R ret;

    if (params && params[0].a0) {
      if (params[0].a1 != nullptr && params[0].a1 != (void *)(((R*)params[0].a0) + 1))
        throw "invalid size for return value";
    }

    printf("applying f %p type %s/%s apply %p\n",
           f1, t1, typeid(F).name(), apply);

    ATuple<Ts...> at(params ? params+1 : nullptr);
    at.dump();
    ret = atuple_apply(f1, at);

    if (params && params[0].a0) {
      *(R *)params[0].a0 = ret;
    }
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

  static void apply(F f1, const char *t1, area *params)
  {
    if (params && params[0].a0) {
      if (params[0].a1 != nullptr && params[0].a1 != params[0].a0)
        throw "invalid size for return value";
    }

    printf("applying f %p type %s/%s apply %p\n",
           f1, t1, demangle(&typeid(F)), apply);

    ATuple<Ts...> at(params ? params+1 : nullptr);
    at.dump();
    atuple_apply(f1, at);
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

std::tuple<char, short, int, long, long long>
mt(char, short, int, long, long long)
{
  return std::make_tuple(0, 0, 0, 0, 0);
}

std::tuple<char, short, int, long, long long>
mt2(char, short, int, long, long long)
{
  return std::make_tuple(-1, -1, -1, -1, -1);
}

struct smorgasbord {
  char c; signed char sc; unsigned char uc;
  short s; unsigned short us;
  int i; unsigned int ui;
  long l; unsigned long ul;
  long long ll; unsigned long long ull;
  double d;
  void *ptr;
};

int main()
{
  const char *str = "hello world";
  int ret;
  Area<const char *> A(&str);
  Area<int> A0(&ret);
  area v[3];

  A0.dump();
  A.dump();
  v[0] = area(A0);
  v[1] = area(A);
  v[2] = area(nullptr, nullptr);
  try {
    //lift(&f).apply(&f, typeid(&f).name(), v);
    lift(&puts).apply(&puts, typeid(&puts).name(), v);
  } catch (const char *s) {
    printf("some exception: %s\n", s);
    fflush(stdout);
  }

  lift(fwrite);
  lift(fread);
  lift(puts);
  lift(fflush);
  lift(qsort);
  lift(qsort_r);
  lift(fopen);
  lift(mt);
  lift(mt2);
  lift(__cxxabiv1::__cxa_demangle);

  std::tuple<const void *, size_t, size_t, FILE *> t((const void*)"hi!\n", 4, 1, stdout);
  ATuple<const void*, size_t, size_t, FILE *> at(&t);

  atuple_apply(fwrite, at);
  //atuple_apply(fwrite, atuple(std::make_tuple((const void *)"Hi!\n", 4, 1, stdout)));;
  
  printf("%s\n", std::to_string(3).c_str());
  int status;
  printf("%s\n", __cxxabiv1::__cxa_demangle(typeid(qsort).name(), NULL, NULL, &status));

  St st = { 1, 2, 3 };
  auto t3 = members(&st, std::make_tuple(&St::a, &St::c));

  printf("%d %d\n", std::get<0>(t3), std::get<1>(t3));

  double d[4] = { 0.0, (double)(size_t)"hi %llx!\n", (double)0x01234567, (double)0x89abcdef };
  lift(puts).apply_doubles(puts, typeid(puts).name(), d);

  lift((int (*)(const char *, long long))printf).apply_doubles2((int (*)(const char *, long long))printf, typeid((int (*)(const char *, long long))printf).name(), d);

  printf("%s %s\n", typeid(qsort).name(), demangle(&typeid(qsort)));
  printf("%s %s\n", typeid(void (*)(void*, unsigned int, unsigned int, int (*)(void const*, void const*))  printf("%s %s\n", typeid(lift(qsort)).name(), demangle(&typeid(lift(qsort))));
}
