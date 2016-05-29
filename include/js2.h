#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <string>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <cxxabi.h>
#include <vector>

/* XXX work out why std::to_string doesn't exist */
std::string to_string(long long b)
{
  char *ret;
  const char *str;
  asprintf(&ret, "%lld", b);
  str = ret;
  return std::string(str);
}

std::string to_string(signed char b)
{
  return to_string((long long)b);
}

std::string to_string(short b)
{
  return to_string((long long)b);
}

std::string to_string(int b)
{
  return to_string((long long)b);
}

std::string to_string(long b)
{
  return to_string((long long)b);
}

std::string to_string(unsigned char b)
{
  return to_string((long long)b);
}

std::string to_string(unsigned short b)
{
  return to_string((long long)b);
}

std::string to_string(unsigned int b)
{
  return to_string((long long)b);
}

std::string to_string(unsigned long b)
{
  return to_string((long long)b);
}

std::string to_string(unsigned long long b)
{
  return to_string((long long)b);
}

template<typename T>
std::string to_string(T t)
{
  return std::string(t);
}

enum class JSCType {
  u8, i8, u16, i16, u32, i32, f32, u64_32, i64_32, u64_f48, i64_f48, f64
};

class Heap {
public:
  std::string prefix;

  Heap(std::string prefix)
    : prefix(prefix)
  {
  }

  std::string describe_heap(JSCType jsctype)
  {
    switch(jsctype) {
    case JSCType::u8:
      return prefix + "U8";
    case JSCType::u16:
      return prefix + "U16";
    case JSCType::u32:
      return prefix + "U32";
    case JSCType::i8:
      return prefix + "8";
    case JSCType::i16:
      return prefix + "16";
    case JSCType::i32:
      return prefix + "32";
    case JSCType::f32:
      return prefix + "F32";
    case JSCType::f64:
      return prefix + "F64";
    }
  }
};

template<typename T>
class Value;

template<typename T>
class ExpressionValue;

class Context {
public:
  Heap *h;

  Context(Heap *h)
    : h(h)
  {
  }

  Heap *
  heap()
  {
    return h;
  }

  template<typename T>
  ExpressionValue<T>
  n(std::string expression)
  {
    return ExpressionValue<T>(this, expression);
  }
};

extern Context context;

template<typename T>
class V;

class BaseValue {
public:
  Context *c;

  void
  setContext(Context *cx)
  {
    c = cx;
  }

  BaseValue()
  {
  }

  BaseValue(Context *cx)
    : c(cx)
  {
  }

  Heap *
  heap()
  {
    return c->heap();
  }

  virtual std::string describe_word()
  {
    return typeid(this).name();
    return this->describe_word();
  }

  virtual std::vector<std::string> describe_words(size_t, size_t)
  {
    std::vector<std::string> ret;

    ret.push_back(this->describe_word());

    return ret;
  }

  operator
  std::string()
  {
    return this->describe_word();
  }
};

template<typename T>
class Value : public BaseValue {
public:
  virtual std::string describe_word()
  {
    return typeid(this).name();
    return this->describe_word();
  }

  V<T>
  operator&()
  {
    return V<T>(this);
  }
};

template<typename T>
class AddValue : public Value<T> {
public:
  Value<T>* a;
  Value<T>* b;

  AddValue(Value<T>* a, Value<T>* b)
    : a(a), b(b)
  {
  }

  virtual std::string
  describe_word() override
  {
    std::string base = a->describe_word();
    std::string offset = b->describe_word();

    if (offset == "0")
      return base;

    if (base == "0")
      return offset;

    return base + "+" + offset;
  }
};

template<typename S,typename T>
class OffValue : public Value<T*> {
public:
  Value<S*> *ptr;
  Value<size_t> *off;

  OffValue(Value<S*>* ptr, Value<size_t>* off)
    : ptr(ptr), off(off)
  {
    this->c = ptr->c;
  }

  virtual std::string
  describe_word() override
  {
    std::string base = ptr->describe_word();
    std::string offset = off->describe_word();

    if (offset == "0")
      return base;

    return base + "+" + offset;
  }
};

class ScaledValue : public Value<size_t> {
public:
  Value<size_t>* a;
  Value<size_t>* b;

  ScaledValue(Value<size_t>* a, Value<size_t>* b)
    : a(a), b(b)
  {
    this->c = a->c;
  }

  virtual std::string
  describe_word() override
  {
    std::string factor_a = a->describe_word();
    std::string factor_b = b->describe_word();

    if (factor_a == "0" || factor_b == "0")
      return "0";

    if (factor_a == "1")
      return factor_b;

    if (factor_b == "1")
      return factor_a;

    return factor_a + "*" + factor_b;
  }
};

template<typename T>
class ImmValue : public Value<T> {
public:
  T v;

  ImmValue(T v)
    : v(v)
  {
  }

  virtual std::string
  describe_word()
  {
    return to_string(v);
  }

  std::vector<std::string>
  describe_words(size_t shift = 0, size_t off = 0)
  {
    char *ptr = (char *)&v;
    size_t len = sizeof(v);
    std::vector<std::string> ret;

    while (len-off >= 4) {
      ret.push_back(ImmValue<unsigned>(*(unsigned *)(ptr + off)).describe_word());
      off += 4;
    }
    while (len-off >= 2) {
      ret.push_back(ImmValue<unsigned short>(*(unsigned short*)(ptr + off)).describe_word());
      off += 2;
    }
    while (len-off >= 1) {
      ret.push_back(ImmValue<unsigned char>(*(unsigned char*)(ptr + off)).describe_word());
      off += 1;
    }

    return ret;
  }
};

template<typename T>
class BasePtrValue : public Value<T> {
public:
  Value<T*> *a;

  BasePtrValue(Value<T*>* a)
    : a(a)
  {
    this->c = a->c;
  }

  virtual std::string
  describe_word()
  {
    JSCType jsctype = JSCType::u8;
    switch(sizeof(T)) {
    case 1:
      return this->heap()->describe_heap(JSCType::i8) + "[" + a->describe_word() + "]";
    case 2:
      return this->heap()->describe_heap(JSCType::i16) + "[" + a->describe_word() + ">>1]";
    case 4:
      return this->heap()->describe_heap(JSCType::i32) + "[" + a->describe_word() + ">>2]";
    case 8:
      /* this is a hack */
      return this->heap()->describe_heap(JSCType::i32) + "[" + a->describe_word() + ">>2]";
    }

    return "unknown size";
  }
};

template<typename T>
class PtrValue : public BasePtrValue<T> {
public:
  PtrValue(Value<T*>* a)
    : BasePtrValue<T>(a)
  {
  }
};

#define PTRVALUE_INTTYPE(TYPE)                                          \
  template<>                                                            \
  class PtrValue<TYPE> : public BasePtrValue<TYPE>                      \
  {                                                                     \
  public:                                                               \
    PtrValue(Value<TYPE*>* a);                                          \
  };                                                                    \
                                                                        \
  template<>                                                            \
  class Value<TYPE*> : public BaseValue                                 \
  {                                                                     \
  public:                                                               \
    template<typename T>                                                \
      Value<T*>*                                                        \
      operator_plus_bytes(Value<size_t>* n, T*)                         \
    {                                                                   \
      return new OffValue<T,T>(this, n);                                \
    }                                                                   \
                                                                        \
    Value<TYPE>*                                                        \
      operator_deref();                                                 \
  };                                                                    \
                                                                        \
  PtrValue<TYPE>::PtrValue(Value<TYPE*>* a)                             \
    : BasePtrValue<TYPE>(a)                                             \
  {                                                                     \
  }                                                                     \
                                                                        \
  Value<TYPE>*                                                          \
  Value<TYPE*>::operator_deref()                                        \
  {                                                                     \
    return new PtrValue<TYPE>(this);                                    \
  }

PTRVALUE_INTTYPE(long long unsigned int)
PTRVALUE_INTTYPE(long unsigned int)
PTRVALUE_INTTYPE(unsigned int)
PTRVALUE_INTTYPE(short unsigned int)
PTRVALUE_INTTYPE(unsigned char)

PTRVALUE_INTTYPE(long long int)
PTRVALUE_INTTYPE(long int)
PTRVALUE_INTTYPE(int)
PTRVALUE_INTTYPE(short int)
PTRVALUE_INTTYPE(signed char)
PTRVALUE_INTTYPE(char)

template<typename T>
class JSV;

template<typename T>
class Value<T*> : public BaseValue {
public:
#if 0
  V<T*>
  operator&()
  {
    return V<T*>(this);
  }

  template<typename I>
  PtrValue<I>
  operator[](I T::* x)
  {
    T* p = nullptr;
    size_t off = (size_t)&(p->*x);

    OffValue<T,I> ov(this, new ImmValue<size_t>(ImmValue<size_t>(off)));

    return *ov;
  }

  PtrValue<T>
  operator[](Value<size_t> i)
  {
    T* p = nullptr;
    size_t size = (size_t)&(p[1]);

    OffValue<T,T> ov(this, new ScaledValue(&i, new ImmValue<size_t>(size)));

    return *ov;
  }

  Value<T*>
  operator+(Value<size_t> i)
  {
    T* p = nullptr;
    size_t size = (size_t)&(p[1]);

    OffValue<T,T> ov(this, new ScaledValue(&i, new ImmValue<size_t>(size)));

    return ov;
  }
#endif

  template<typename I>
  Value<I*>*
  operator_plus_bytes(Value<size_t>* i, I*)
  {
    return new OffValue<T,I>(this, i);
  }

  Value<T*>*
  operator_plus(Value<size_t>* i)
  {
    T* p = nullptr;
    size_t size = (size_t)&(p[1]);

    return new OffValue<T,T>(this, new ScaledValue(i, new ImmValue<size_t>(size)));
  }

  template<typename I>
  Value<I*>*
  operator_plus(I T::* x)
  {
    T* p = nullptr;
    size_t off = (size_t)&(p->*x);

    return new OffValue<T,I>(this, new ImmValue<size_t>(off));
  }

  Value<T>*
  operator_deref()
  {
    return new PtrValue<T>(this);
  }

  template<typename I>
  Value<I>*
  operator_indir(I T::* x)
  {
    return this->operator_plus(x)->operator_deref();
  }

  Value<T>*
  operator_indir(Value<size_t> *i)
  {
    return this->operator_plus(i)->operator_deref();
  }

#if 0
  PtrValue<T>
  operator[](Value<size_t>* i)
  {
    T* p = nullptr;
    size_t size = (size_t)&(p[1]);

    OffValue<T,T> ov(this, new ScaledValue(i, new ImmValue<size_t>(size)));

    return *ov;
  }

  OffValue<T,T>
  operator+(Value<size_t>* i)
  {
    T* p = nullptr;
    size_t size = (size_t)&(p[1]);

    OffValue<T,T> ov(this, new ScaledValue(i, new ImmValue<size_t>(size)));

    return ov;
  }
#endif
};

template<typename T>
class Value<T[]> : public BaseValue {
public:
  Value<T>
  operator_indir(Value<size_t> *i)
  {
    T* p = nullptr;
    size_t size = (size_t)&(p[1]);

    return new PtrValue<T>(new OffValue<T,T>(this, new ScaledValue(i, new ImmValue<size_t>(size))));
  }
};

#if 0
template<typename T,typename I>
PtrValue<I>
operator*(OffValue<T,I> address)
{
  OffValue<T,I>* a = new OffValue<T,I>(address);

  return PtrValue<I>(a);
}

template<typename T>
PtrValue<T>
operator*(Value<T*> address)
{
  Value<T*> *a = new Value<T*>(address);

  return PtrValue<T>(a);
}
#endif

template<typename T>
class ExpressionValue : public Value<T> {
public:
  std::string e;

  ExpressionValue(Context *cx, std::string s)
    : e(std::string(s))
  {
    this->c = cx;
  }

  virtual std::string describe_word()
  {
    return e;
  }
};

template<typename T>
class BaseJSV {
public:
  Value<T>* v;

  BaseJSV(Value<T>* v)
    : v(v)
  {
  }

  BaseJSV(size_t s)
    : v(new ImmValue<size_t>(s))
  {
  }

  BaseJSV(int s)
    : v(new ImmValue<size_t>(s))
  {
  }

  BaseJSV(std::string address)
    : v(new ExpressionValue<T>(&context, address))
  {
  }

  BaseJSV operator[](BaseJSV<size_t> off)
  {
    return v->operator_indir(off.v);
  }

  operator
  std::string()
  {
    return *v;
  }
};

template<typename T>
class JSV : public BaseJSV<T> {
public:
  JSV(Value<T>* v)
    : BaseJSV<T>(v)
  {
  }

  JSV(size_t s)
    : BaseJSV<T>(s)
  {
  }

  JSV(int s)
    : BaseJSV<T>(s)
  {
  }

  JSV(std::string expr)
    : BaseJSV<T>(expr)
  {
  }

  std::string operator=(T);
};

template<typename A,typename B>
class NO;

template<typename T>
class JSV<T*> : public BaseJSV<T*> {
public:
  JSV(Value<T*>* v)
    : BaseJSV<T*>(v)
  {
  }

  JSV(std::string address)
    : BaseJSV<T*>(new ExpressionValue<T*>(&context, address))
  {
  }

  JSV<T*>
  operator+(JSV<size_t> n)
  {
    return JSV<T*>(this->v->operator_plus_bytes(new ScaledValue(n.v, new ImmValue<size_t>(sizeof(T))), (T*)nullptr));
  }

  template<typename I>
  JSV<I*>
  operator+(NO<T,I> off)
  {
    return this->v->operator_plus_bytes(off.off.v, (I*)nullptr);
  }

  JSV<T>
  operator[](JSV<size_t> n)
  {
    return (*this+n).v->operator_deref();
  }

  template<typename I>
  JSV<I>
  operator[](NO<T,I> off)
  {
    return (*this+off).v->operator_deref();
  }

  template<typename I>
  JSV<I*>
  operator+(I T::* x)
  {
    T* p = nullptr;
    size_t s = (size_t)&(p->*x);

    Value<size_t>* v = new ImmValue<size_t>(s);
    return this->v->operator_plus(x);
  }

  template<typename I>
  JSV<I>
  operator[](I T::* x)
  {
    return *(*this + x);
  }

  JSV<T>
  operator[](size_t n)
  {
    return *(*this + n);
  }

  JSV<T>
  operator*()
  {
    return this->v->operator_deref();
  }
};

#define JSV_INTPTR(TYPE)                                                \
  template<>                                                            \
  class JSV<TYPE*> : public BaseJSV<TYPE*> {                            \
  public:                                                               \
                                                                        \
  JSV(Value<TYPE*>* v) : BaseJSV<TYPE*>(v)                              \
    {                                                                   \
    }                                                                   \
                                                                        \
  JSV(std::string expr) : BaseJSV<TYPE*>(expr)                          \
    {                                                                   \
    }                                                                   \
                                                                        \
  JSV                                                                   \
  operator+(JSV<size_t> n)                                              \
    {                                                                   \
      return JSV<TYPE*>(this->v->operator_plus_bytes(new ScaledValue(n.v, new ImmValue<size_t>(sizeof(TYPE))), (TYPE*)nullptr)); \
    }                                                                   \
                                                                        \
  JSV<TYPE>                                                             \
  operator*()                                                           \
    {                                                                   \
      return this->v->operator_deref();                                 \
    }                                                                   \
  };

JSV_INTPTR(long long unsigned int)
JSV_INTPTR(long unsigned int)
JSV_INTPTR(unsigned int)
JSV_INTPTR(short unsigned int)
JSV_INTPTR(unsigned char)

JSV_INTPTR(long long int)
JSV_INTPTR(long int)
JSV_INTPTR(int)
JSV_INTPTR(short int)
JSV_INTPTR(signed char)
JSV_INTPTR(char)

template<>
std::string
JSV<long long unsigned int>::operator=(long long unsigned int r)
{
  return std::string(*this) + " = " + to_string(r);
}

template<typename T>
class JSV<T[]> : public BaseJSV<T[]> {
public:
  JSV(std::string address)
    : BaseJSV<T[]>(new ExpressionValue<T[]>(&context, address))
  {
  }
};

template<typename A,typename B>
class NO {
public:
  JSV<size_t> off;

  NO(JSV<size_t> off)
    : off(off)
  {
  }

  NO(B A::* a)
    : off(new ImmValue<size_t>(0))
  {
    A* p = nullptr;
    off = (size_t)&(p->*a);
  }

  template<typename C>
  NO<A,C>
  operator+(NO<B,C> b)
  {
    return NO<A,C>(new AddValue<size_t>(off.v, b.off.v));
  }

  NO<A,B>
  operator+(JSV<size_t> v)
  {
    return *this + NO<B,B>(v);
  }

  NO<A,B>
  operator+(size_t n)
  {
    return *this + JSV<size_t>(n);
  }
};

template<typename A>
class NO<A,A> {
public:
  JSV<size_t> off;

  NO(size_t n)
    : off(new ImmValue<size_t>(n))
  {
  }

  NO(JSV<size_t> n)
    : off(new ScaledValue(n.v, new ImmValue<size_t>(sizeof(A))))
  {
  }

  template<typename B>
  NO<A,B>
  operator+(NO<A,B> n2)
  {
    return NO<A,B>(new AddValue<size_t>(off.v, n2.off.v));
  }
};

template<typename A,typename B>
NO<A,B>
operator+(JSV<size_t> i, B A::* b)
{
  return NO<A,B>(new AddValue<size_t>(new ScaledValue(i.v, new ImmValue<size_t>(sizeof(A))), NO<A,B>(b).off.v));
}

const char *js_set(const char *base, unsigned off, unsigned len, const char *v)
{
  char *ret;
  switch (len) {
  case 1:
    asprintf(&ret, "this.HEAP8[%s+%d] = %s;", base, off, v); return ret;
  case 2:
    asprintf(&ret, "this.HEAP16[%s+%d>>1] = %s;", base, off, v); return ret;
  case 4:
    asprintf(&ret, "this.HEAP32[%s+%d>>2] = %s;", base, off, v); return ret;
  case 8:
    asprintf(&ret, "this.HEAP32[%s+%d>>2] = %s; this.HEAP32[%s+%d>>2] = 0;", base, off, v, base, off+4, 0); return ret;
  }
  return "XXX";
}

const char *js_set(const char *base, unsigned off, unsigned len, unsigned long long v)
{
  char *ret;
  switch (len) {
  case 1:
    asprintf(&ret, "this.HEAP8[%s+%d] = %d;", base, off, v); return ret;
  case 2:
    asprintf(&ret, "this.HEAP16[%s+%d>>1] = %d;", base, off, v); return ret;
  case 4:
    asprintf(&ret, "this.HEAP32[%s+%d>>2] = %d;", base, off, v); return ret;
  case 8:
    asprintf(&ret, "this.HEAP32[%s+%d>>2] = %d; this.HEAP32[%s+%d>>2] = %d;", base, off, (int)v&0xffffffff, base, off+4, (int)(v>>32)); return ret;
  }
  return "XXX";
}

const char *js_set(const char *base, unsigned off, unsigned len, int v)
{
  return js_set(base, off, len, (unsigned long long)v);
}

const char *js_clear(const char *base, unsigned off, unsigned len)
{
  return js_set(base, off, len, 0);
}

template<typename T>
void p(auto T::* x)
{
    T* ptr = nullptr;
    unsigned long off = (unsigned long)&(ptr->*x);

    std::cout << off << '\n';
}

template<typename T>
void p(T x)
{
  std::cout << x << '\n';
}


template<typename T>
void clear(int T::*x)
{
  T* ptr = nullptr;
  unsigned long off = (unsigned long)&(ptr->*x);
  int status;
  std::cout << "this.HEAP32[" << abi::__cxa_demangle(typeid(T).name(), 0, 0, &status) << "+" << off << ">>2] = 0;\n";
}

template<typename T>
void clear(long long T::*x)
{
  T* ptr = nullptr;
  unsigned long off = (unsigned long)&(ptr->*x);
  int status;
  std::cout << "this.HEAP32[" << abi::__cxa_demangle(typeid(T).name(), 0, 0, &status) << "+" << off << ">>2] = 0;\n";
}

template<typename T, typename I>
class field {
public:
  unsigned long off;
  unsigned long size;

  field(I *p = nullptr, unsigned long o = 0)
  {
    I* ptr = nullptr;
    off = (unsigned long)ptr + o;
    size = sizeof(*ptr);
  }
};

template<typename T>
field<T,T>
construct_field(T* p)
{
  return field<T,T>();
}

template<typename T, typename I>
field<T,I>
construct_field(I T::* x)
{
  T* ptr = nullptr;
  unsigned long off = (unsigned long)&(ptr->*x);
  return field<T,I>(nullptr, off);
}
template<typename I>
class range;

class elt;

class str {
public:
  std::string s;
#if 0
  template<typename T>
  std::string
  operator[](field<T> a)
  {
    return s + "+" + to_string(a.off) + "-" + to_string(a.size);
  }

  template<typename T>
  std::string
  operator[](auto T::* a)
  {
    field<T> f(a);
    return (*this)[f];
  }
#endif
  template<typename T, typename I>
  range<I>
  operator[](field<T,I> f)
  {
    return range<I>(*this, f);
  }

  template<typename T, typename I>
  range<I>
  operator[](I T::* a)
  {
    field<T,I> f(construct_field(a));
    return (*this)[f];
  }

  template<typename T, typename I>
  range<I>
  operator+(field<T,I> f)
  {
    return range<I>(*this, f, true);
  }

  template<typename T, typename I>
  range<I>
  operator+(I T::* a)
  {
    field<T,I> f(a);
    return (*this)+f;
  }

  str(const char s[])
    : s(s)
  {
  }

  str(std::string s)
    : s(s)
  {
  }

  operator std::string()
  {
    return s;
  }
};

template<typename T>
field<T,T>
entire(T* p = nullptr)
{
  return field<T,T>(p);
}

int main();

class elt {
public:
  str s;
  str i;
  str prefix;

  elt(str s, str i, str prefix)
    : s(s), i(i), prefix(prefix)
  {
  }

  elt(str s, str prefix = str("this.HEAP"))
    : s(s), i(""), prefix(prefix)
  {
  }

  template<typename T, typename I>
  range<I>
  operator[](field<T,I> f)
  {
    return range<I>(*this, f);
  }

  template<typename T, typename I>
  range<I>
  operator[](I T::* a)
  {
    field<T,I> f(construct_field(a));
    return (*this)[f];
  }

  template<typename T, typename I>
  range<I>
  operator+(field<T,I> f)
  {
    return range<I>(*this, f, true);
  }

  template<typename T, typename I>
  range<I>
  operator+(I T::* a)
  {
    field<T,I> f(a);
    return (*this)+f;
  }

  template<typename T>
  range<T>
  operator[](void (T::* f)(T&&))
  {
    return (*this)[entire<T>()];
  }

  template<typename T>
  range<T>
  operator[](T*)
  {
    return (*this)[entire<T>()];
  }

  template<typename T>
  range<T>
  operator[](T x)
  {
    return (*this)[entire<T>()] = x;
  }

  template<typename T>
  range<T>
  operator=(T x)
  {
    return (*this)[entire<T>()] = x;
  }

  template<typename T>
  range<T>
  operator<<(T x)
  {
    return (*this)[entire<T>()] = x;
  }

  elt
  operator[](elt index)
  {
    return elt(s, index.s, prefix);
  }

  operator std::string()
  {
    return std::string(s);
  }
};

template <typename T>
class typed: public elt
{
public:
  using elt::elt;

  using elt::operator=;
  using elt::operator[];

  range<T>
  operator*()
  {
    return (*this)[entire<T>()];
  }

  typed& operator=(const typed&) = delete;

  range<T>
  operator[](T x)
  {
    return (*this)[entire<T>()] = x;
  }

  range<T>
  operator()(T x)
  {
    return (*this)[entire<T>()] = x;
  }

  range<T>
  operator()(std::string st)
  {
    return (*this)[entire<T>()] = st;
  }

  range<T>
  operator()()
  {
    return (*this)[entire<T>()] = T();
  }
};

template <typename T>
class typed<T[]>: public elt
{
public:
  using elt::elt;

  using elt::operator=;
  using elt::operator[];

  range<T>
  operator*()
  {
    return (*this)[entire<T>()];
  }

  typed& operator=(const typed&) = delete;

  range<T>
  operator[](T x)
  {
    return (*this)[entire<T>()] = x;
  }

  range<T>
  operator()(T x)
  {
    return (*this)[entire<T>()] = x;
  }

  range<T>
  operator()()
  {
    return (*this)[entire<T>()] = T();
  }

  typed<T>
  operator[](elt index)
  {
    return typed<T>(s, index.s, prefix);
  }
};

#define NWORDS(s) ((s)/4 + ((s)&2)/2 + ((s)&1))

template<typename I>
class range {
public:
  std::vector<std::string> v;
  unsigned long eltsize;

  range(I iv)
    : v(NWORDS(sizeof(I)))
  {
    size_t i = 0;
    unsigned long size = sizeof(I);
    unsigned long off = 0;
    while (size >= 4) {
      int word = *(int *)((char *)(&iv) + off);
      v[i++] = to_string(word);
      size -= 4;
      off += 4;
    }
    if (size >= 2) {
      short word = *(short *)((char *)(&iv) + off);
      v[i++] = to_string(word);
      size -= 2;
      off += 2;
    }
    if (size >= 1) {
      signed char word = *(signed char *)((char *)(&iv) + off);
      v[i++] = to_string(word);
      size -= 1;
      off += 1;
    }
  }

  range(str base)
    : v(NWORDS(sizeof(I)))
  {
    v[0] = base;
    for (size_t i = 1; i < v.size(); i++)
      v[i] = "0";
  }

  range(std::string base)
    : v(NWORDS(sizeof(I)))
  {
    v[0] = str(base);
    for (size_t i = 1; i < v.size(); i++)
      v[i] = "0";
  }

  range(const char *base)
    : v(NWORDS(sizeof(I)))
  {
    v[0] = str(base);
    for (size_t i = 1; i < v.size(); i++)
      v[i] = "0";
  }

  range
  operator()()
  {
    return (*this) = range("0");
  }

  range
  operator&()
  {
    range ret(*this);
    for (size_t i = 0; i < ret.v.size(); i++) {
      size_t first = ret.v[i].find_first_of('[');
      size_t last = ret.v[i].find_last_of(']');

      if (first != last)
        ret.v[i] = ret.v[i].substr(first+1, last-first-1);

      if (ret.v[i].substr(ret.v[i].length() - 3) == ">>3" ||
          ret.v[i].substr(ret.v[i].length() - 3) == ">>2" ||
          ret.v[i].substr(ret.v[i].length() - 3) == ">>1")
        ret.v[i] = ret.v[i].substr(0, ret.v[i].length()-3);
    }

    return ret;
  }

  template<typename T>
  range(elt base, field<T,I> f, bool address = false)
    : v(NWORDS(sizeof(I)))
  {
    unsigned long off = f.off;
    unsigned long size = f.size;
    std::string infix("");
    std::string infix2("");
    size_t i = 0;

    if (std::string(base.i) != "")
      infix = "+" + std::string(base.i) + "*" + to_string(sizeof(T));
    while (size >= 4) {
      if (off != 0)
        infix2 = "+" + to_string(off);
      v[i++] = (address ? "" : std::string(base.prefix) + "32[") +
        std::string(base.s) +
        infix + infix2 +
        (address ? "" : ">>2]");
      off += 4;
      size -= 4;
    }
    if (size >= 2) {
      if (off != 0)
        infix2 = "+" + to_string(off);
      v[i++] = (address ? "" : std::string(base.prefix) + "16[") +
        std::string(base.s) +
        infix + infix2 +
        (address ? "" : ">>1]");
      off += 2;
      size -= 2;
    }
    if (size >= 1) {
      if (off != 0)
        infix2 = "+" + to_string(off);
      v[i++] = (address ? "" : std::string(base.prefix) + "8[") +
        std::string(base.s) +
        infix + infix2 +
        (address ? "" : "]");
      off += 1;
      size -= 1;
    }
  }

  template<typename T>
  range(elt base, I T::* a, bool address = false)
    : v(NWORDS(sizeof(I)))
  {
    field<T,I> f(a);
    range(base, f, address);
  }

  std::string
  operator=(range<I> val)
  {
    std::string ret;

    for (size_t i = 0; i < v.size(); i++) {
      ret += v[i] + " = " + val.v[i] + ";";
      if (i < v.size() - 1)
        ret += " ";
    }

    return ret;
  }

  operator std::string()
  {
    return v[0];
  }
};
