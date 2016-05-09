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
