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
#include <typeinfo>
#include <stdio.h>

const char *demangle(const char *name)
{
  int status;
  const char *ret = __cxxabiv1::__cxa_demangle(name, NULL, NULL, &status);

  if (status)
    throw "bad";

  return ret;
}

template<class...Ts>
class count_doubles;

template<class T, class ...Ts>
class count_doubles<T,Ts...> {
public:
  static size_t count()
  {
    return 1 + count_doubles<Ts...>::count();
  }
};

template<>
class count_doubles<> {
public:
  static size_t count()
  {
    return 0;
  }
};

template<class X>
class count_double_args;

template<class R, class ...Ts>
class count_double_args<R (*)(Ts...)> {
public:
  static size_t count()
  {
    return count_doubles<Ts...>::count();
  }
};

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
    ;//throw "round-trip conversion failed";

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
class to_double {
public:
  static double
  f(T x)
  {
    return double(x);
  }
};

template<class T>
class to_double<T*> {
public:
  static double
  f(T* x)
  {
    return double(unsigned(x));
  }
};

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
  typedef R (*F)(Ts...);

  static void apply_doubles(long, long, F f1, double *d)
  {
    R ret = tuple_apply(f1, from_doubles<Ts...>(d+1));
    d[0] = to_double<R>::f(ret);
  }

  Lift(F f)
    : f(f), t(typeid(*f).name())
  {
    printf("registering f %p type %s apply %p\n",
           f, demangle(typeid(*f).name()), apply_doubles);
  }
};

template<class ...Ts>
class Lift<void,Ts...> {
public:
  void (*f)(Ts...);
  const char *t;
  typedef void (*F)(Ts...);

  static void apply_doubles(long, long, F f1, double *d)
  {
    d[0] = 0;
    tuple_apply(f1, from_doubles<Ts...>(d+1));
  }

  Lift(F f)
    : f(f), t(typeid(*f).name())
  {
    printf("registering f %p type %s apply %p\n",
           f, demangle(typeid(*f).name()), apply_doubles);
  }
};

template<class R, class ...Ts>
Lift<R, Ts...> lift(R f(Ts...))
{
  return Lift<R, Ts...>(f);
}

asm(".include \"import-macros.s\"");
asm(".import3 thinthin,queue_peek,__thinthin_queue_peek");
asm(".import3 thinthin,queue_pop,__thinthin_queue_pop");
asm(".import3 thinthin,export,__thinthin_export");

extern "C"
__attribute__((stackcall))
int
__thinthin_queue_peek();

extern "C"
__attribute__((stackcall))
int
__thinthin_queue_pop(void (**)(long, long, void *, double *),
                     void *,
                     void *);

extern "C"
__attribute__((stackcall))
int
__thinthin_export(const char *name, void *f, const char *type, void *apply,
                  const char *demangled_type, unsigned nargs);

#if 0
int
__thinthin_export(const char *name, void *f, const char *type, void *apply,
                  const char *demangled_type, unsigned nargs)
{
  asm volatile("dpc = \n\t\t.dpc .LI%=\n\t\t\t|0;\n\t"
               "rp = foreign_extcall(%O0|0, %O1|0, 0xdedbeef|0, %O2|0)|0;\n\t"
               "if (rp&3) {\n\t\t"
               "break mainloop;\n\t"
               "}\n\t"
               ".labeldef_internal .LI%="
               : : "r" ("thinthin"), "r" ("export"), "r" (__builtin_frame_address(0)+40));

  return 0;
}
#endif

template<class F>
class AsmJSExport {
  const char *name;
  const char *type;
  F f;

  public:
  AsmJSExport (const char *name,
               F f,
               const char *type)
    : name(name), f(f), type(type)
  {
    printf("constructing AsmJSExport\n");
    auto L(lift(f));
    __thinthin_export(name, (void *)f, type, (void *)L.apply_doubles,
                      demangle(type), count_double_args<decltype(f)>::count());

    int size;
    while ((size = __thinthin_queue_peek()) >= 0) {
      double stack[1+size];
      void (*apply)(long, long, void *, double *);
      void *fun;

      __thinthin_queue_pop(&apply, &fun, stack+1);

      void (*f)() = (void (*)())fun;
      printf("queue pop returned %p %p=%p [%f]\n", apply, fun, f,
             stack[1]);

      apply(0, 0, fun, stack);

      printf("rv %f\n", stack[0]);
    }
  }
};

#define asmjs_register(name, f, f2, type)                           \
  AsmJSExport<decltype(f2)> jsexport_##f(name, (decltype(f2))f2, type);
