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
                        const char *getter, const char *setter);

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

template<class T, class F, unsigned long offset, unsigned long bytesize>
class AsmJSExportField {
public:
  static F *getter(T* p)
  {
    char *p2 = (char *)p;

    p2 += offset;

    return (F *)p2;
  }

  static void setter(T* p, F *v)
  {
    char *p2 = (char *)p;

    p2 += offset;

    memcpy(p2, v, bytesize);
  }

  AsmJSExportField (const char *jsname, const char *fieldname,
                    const char *recordtype, const char *fieldtype)
  {
    char *getter_name;
    char *setter_name;

    asprintf(&getter_name, "%s_%s__getter", jsname, fieldname);
    asprintf(&setter_name, "%s_%s__setter", jsname, fieldname);

    AsmJSExport<decltype(&getter)> jsexport_getter(getter_name, getter, recordtype, fieldtype, typeid(getter).name());
    AsmJSExport<decltype(&setter)> jsexport_setter(setter_name, setter, recordtype, fieldtype, typeid(setter).name());

    __thinthin_export_field(jsname, fieldname,
                            recordtype, fieldtype,
                            getter_name, setter_name);

    free(getter_name);
    free(setter_name);
  }
};

template<class T,class F, unsigned long offset, unsigned long bytesize>
requires(std::is_integral<F>::value || std::is_pointer<F>::value)
class AsmJSExportField<T,F,offset,bytesize> {
public:
  static F getter(T* p)
  {
    char *p2 = (char *)p;

    p2 += offset;

    return *(F *)p2;
  }

  static void setter(T* p, F v)
  {
    char *p2 = (char *)p;

    p2 += offset;

    memcpy(p2, &v, bytesize);
  }

  AsmJSExportField (const char *jsname, const char *fieldname,
                    const char *recordtype, const char *fieldtype)
  {
    char *getter_name;
    char *setter_name;

    asprintf(&getter_name, "%s_%s__getter", jsname, fieldname);
    asprintf(&setter_name, "%s_%s__setter", jsname, fieldname);

    AsmJSExport<decltype(&getter)> jsexport_getter(getter_name, getter, recordtype, fieldtype, typeid(getter).name());
    AsmJSExport<decltype(&setter)> jsexport_setter(setter_name, setter, recordtype, fieldtype, typeid(setter).name());

    __thinthin_export_field(jsname, fieldname,
                            recordtype, fieldtype,
                            getter_name, setter_name);

    free(getter_name);
    free(setter_name);
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
  AsmJSExportVar (const char *jsname, const char *type_jsname, unsigned long address)
  {
    __thinthin_export_var (jsname, type_jsname, address);
  }
};

/* Register a function or method. JSNAME is the JavaScript identifier
   to be used; SUFFIX is a unique symbol suffix for this function;
   FUNCTION is a function pointer; CLASSTYPE is the typeid string for
   either void or a pointer to the class of which this function is a
   method; RETTYPE is the typeid string for the function's return
   type; TYPE is the typeid string for the entire function pointer. */

#define asmjs_register_function(jsname, suffix, function, classtype, rettype, type)           \
  AsmJSExport<decltype(function)> jsexport_##suffix(jsname, (decltype(function))function, classtype, rettype, type);

#define asmjs_register_record_type(jsname, classtype) \
  AsmJSExportType jsexport_##__LINE__(jsname, typeid(classtype *).name());

#define asmjs_register_field(jsname, classtype, fieldtype, fieldname, bitpos, bytesize) \
  AsmJSExportField<classtype,fieldtype,(bitpos/8),bytesize> jsexport_##fieldname(jsname, #fieldname, typeid(classtype *).name(), typeid(fieldtype *).name());

#define asmjs_register_variable(jsname, type_jsname, address) \
  AsmJSExportVar jsexport_##address(jsname, type_jsname, address);
