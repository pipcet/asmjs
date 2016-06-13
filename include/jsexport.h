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
    {
      printf("round-trip conversion failed; %f != %f\n",
             double(ret), d);
      throw "round-trip conversion failed";
    }

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

template<>
void *from_double<void *>(double d)
{
  void *ret = (void *)(size_t(d));

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

/* By "neutering", we mean replacing all pointers in a function
 * pointer's prototype with void pointers.  That makes debugging
 * potentially harder, but it means we save drastically on template
 * instantiations and compile time, while also making it more likely
 * that additional function pointer types that we only learn about at
 * runtime have a working template instantiation, so we can use
 * them. */

template<class T>
class Neuter1 {
public:
  typedef T type;
  static constexpr T *p = nullptr;
};

#ifdef NEUTER
template<class T>
class Neuter1<T*> {
public:
  typedef void *type;
  static constexpr void **p = nullptr;
};
#endif

template<class T>
requires(!std::is_pointer<T>::value)
class Neuter1<T> {
public:
  typedef T type;
  static constexpr T *p = nullptr;
};

template<class ...Ts>
class Neuter {
};

template<>
class Neuter<> {
public:
  typedef std::tuple<> tuple;
  typedef std::tuple<> orig_tuple;
};

template<class T, class ...Ts>
class Neuter<T*,Ts...> {
public:
  typedef decltype(tuple_cat(std::tuple<void *>(),Neuter<Ts...>::tuple())) tuple;
  typedef decltype(tuple_cat(std::tuple<T*>(), Neuter<Ts...>::orig_tuple())) orig_tuple;
};

template<class T, class ...Ts>
requires(!std::is_pointer<T>::value)
class Neuter<T,Ts...> {
public:
  typedef decltype(tuple_cat(std::tuple<T>(), Neuter<Ts...>::tuple())) tuple;
  typedef decltype(tuple_cat(std::tuple<T>(), Neuter<Ts...>::orig_tuple())) orig_tuple;
};

template<class F>
class NeuterFun {
public:
  F f;
  F f_neutered;

  NeuterFun(F f)
    : f(f), f_neutered(f)
  {
  }
};

template<class R,class ...Ts>
class NeuterFun<R (*)(Ts...)> {
public:
  R (*f)(Ts...);
  typedef typename std::remove_reference<decltype(*Neuter1<R>::p)>::type R_neutered;
  R_neutered (*f_neutered)(typename std::remove_reference<decltype(*Neuter1<Ts>::p)>::type...);

  NeuterFun(decltype(f) f)
    : f(f), f_neutered((decltype(f_neutered))f)
  {
  }
};

template<class ...Ts>
class NeuterFun<void (*)(Ts...)> {
public:
  void (*f)(Ts...);
  void (*f_neutered)(typename std::remove_reference<decltype(*Neuter1<Ts>::p)>::type...);

  NeuterFun(decltype(f) f)
    : f(f), f_neutered((decltype(f_neutered))f)
  {
  }
};

template<class T>
auto
neuter(T *f = nullptr)
{
  return NeuterFun<T *>(f).f_neutered;
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

asm(".include \"asmjs-import-macros.s\"");
asm(".import3 thinthin,export,__thinthin_export");
asm(".import3 thinthin,export_type,__thinthin_export_type");
asm(".import3 thinthin,export_field,__thinthin_export_field");
asm(".import3 thinthin,export_var,__thinthin_export_var");

extern "C"
__attribute__((stackcall))
int
__thinthin_export(const char *name, void *f, const char *type, void *apply,
                  const char *demangled_type, unsigned nargs,
                  const char *rettype);

extern "C"
__attribute__((stackcall))
int
__thinthin_export_type(const char *jsname, const char *typeidstr);

extern "C"
__attribute__((stackcall))
int
__thinthin_export_field(const char *jsname, const char *fieldname,
                        const char *recordtype, const char *fieldtype,
                        const char *getter, const char *setter,
                        const char *get_pointer_name);

extern "C"
__attribute__((stackcall))
int
__thinthin_export_var(const char *jsname, const char *type_jsname,
                      unsigned long address);

template<class F>
class AsmJSExport {
  const char *name;
  const char *type;
  F f;

  public:
  AsmJSExport (const char *name,
               F f,
               const char *classtype,
               const char *rettype,
               const char *type)
    : name(name), f(f), type(type)
  {
    printf("constructing AsmJSExport %s/%s/%s\n",
           classtype, rettype, type);
    auto L(lift(f));
    __thinthin_export(name, (void *)f, type, (void *)L.apply_doubles,
                      demangle(type), count_double_args<decltype(f)>::count(),
                      rettype);
  }
};

template<class T, class FP, unsigned long offset, unsigned long bytesize>
class AsmJSExportField {
public:
  typedef typename std::remove_pointer<FP>::type F;

  static F *get_pointer(T* p)
  {
    char *p2 = (char *)p;

    p2 += offset;

    return (F *)p2;
  }

  AsmJSExportField (const char *jsname, const char *fieldname,
                    const char *recordtype, const char *fieldtype)
  {
    char *get_pointer_name;

    asprintf(&get_pointer_name, "%s_%s__get_pointer", jsname, fieldname);

    AsmJSExport<decltype(&get_pointer)> jsexport_get_pointer(get_pointer_name, get_pointer, recordtype, fieldtype, typeid(get_pointer).name());

    __thinthin_export_field(jsname, fieldname,
                            recordtype, fieldtype,
                            "", "",
                            get_pointer_name);

    free(get_pointer_name);
  }
};

template<class T, class FP, unsigned long offset, unsigned long bytesize>
requires(std::is_scalar<typename std::remove_pointer<FP>::type>::value)
class AsmJSExportField<T,FP,offset,bytesize> {
public:
  typedef typename std::remove_pointer<FP>::type F;

  static F *get_pointer(T* p)
  {
    char *p2 = (char *)p;

    p2 += offset;

    return (F *)p2;
  }

  static F get_value(T* p)
  {
    char *p2 = (char *)p;

    p2 += offset;

    return *(F *)p2;
  }

  static void set_value(T* p, F v)
  {
    char *p2 = (char *)p;

    p2 += offset;

    memcpy(p2, &v, bytesize);
  }

  AsmJSExportField (const char *jsname, const char *fieldname,
                    const char *recordtype, const char *fieldtype)
  {
    char *get_value_name;
    char *set_value_name;
    char *get_pointer_name;

    asprintf(&get_value_name, "%s_%s__get_value", jsname, fieldname);
    asprintf(&set_value_name, "%s_%s__set_value", jsname, fieldname);
    asprintf(&get_pointer_name, "%s_%s__get_pointer", jsname, fieldname);

    AsmJSExport<decltype(neuter(&get_pointer))> jsexport_get_pointer(get_pointer_name, neuter(&get_pointer), recordtype, fieldtype, typeid(neuter(&get_pointer)).name());
    AsmJSExport<decltype(neuter(&get_value))> jsexport_get_value(get_value_name, neuter(&get_value), recordtype, fieldtype + 1, typeid(neuter(&get_value)).name());
    AsmJSExport<decltype(neuter(&set_value))> jsexport_set_value(set_value_name, neuter(&set_value), recordtype, typeid(void).name(), typeid(neuter(&set_value)).name());

    __thinthin_export_field(jsname, fieldname,
                            recordtype, fieldtype,
                            get_value_name, set_value_name,
                            get_pointer_name);

    free(get_value_name);
    free(set_value_name);
    free(get_pointer_name);
  }
};

class AsmJSExportType {
public:
  AsmJSExportType (const char *jsname, const char *type)
  {
    __thinthin_export_type (jsname, type);
  }
};

class AsmJSExportVar {
public:
  AsmJSExportVar (const char *jsname, unsigned long address, const char *type_jsname)
  {
    __thinthin_export_var (jsname, type_jsname, address);
  }
};

/* Register a function or method. JSNAME is the JavaScript identifier
   to be used; FUNCTION is a function pointer; CLASSTYPE is the typeid
   string for either void or a pointer to the class of which this
   function is a method; RETTYPE is the typeid string for the
   function's return type; TYPE is the typeid string for the entire
   function pointer. */

#define PASTE2(a,b) a ## b
#define PASTE(a,b) PASTE2(a, b)
#define UNIQ(x) PASTE(x, __COUNTER__)

#define asmjs_register_function(jsname, function, classtype, rettype, type)           \
  AsmJSExport<decltype(neuter(function))> UNIQ(jsexport_fun)(jsname, (decltype(neuter(function)))neuter(function), typeid(classtype).name(), typeid(rettype).name(), typeid(type).name());

#define asmjs_register_function_type(jsname, rettype, type)     \
  AsmJSExport<type> UNIQ(jsexport_fun)(jsname, NULL, NULL, typeid(rettype).name(), typeid(type).name());

#define asmjs_register_record_type(jsname, classtype) \
  AsmJSExportType UNIQ(jsexport_typ) (jsname, typeid(classtype).name());

#define asmjs_register_field(jsname, fieldname, classtype, fieldtype, bitpos, bytesize) \
  AsmJSExportField<classtype,fieldtype,(bitpos/8),bytesize> UNIQ(jsexport_fld)(jsname, #fieldname, typeid(classtype).name(), typeid(decltype(neuter<fieldtype>())).name());

#define asmjs_register_variable(jsname, type, type_jsname, address) \
  AsmJSExportVar UNIQ(jsexport_var)(jsname, address, typeid(decltype(neuter<type>())).name());
