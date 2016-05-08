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
  std::cout << "HEAP32[" << abi::__cxa_demangle(typeid(T).name(), 0, 0, &status) << "+" << off << ">>2] = 0;\n";
}

template<typename T>
void clear(long long T::*x)
{
  T* ptr = nullptr;
  unsigned long off = (unsigned long)&(ptr->*x);
  int status;
  std::cout << "HEAP32[" << abi::__cxa_demangle(typeid(T).name(), 0, 0, &status) << "+" << off << ">>2] = 0;\n";
}

template<typename T, typename I>
class field {
public:
  unsigned long off;
  unsigned long size;
  field(I T::* x)
  {
    T* ptr = nullptr;
    off = (unsigned long)&(ptr->*x);
    size = sizeof(ptr->*x);
  }

  field(T *p = nullptr)
  {
    T* ptr = nullptr;
    off = (unsigned long)ptr;
    size = sizeof(*ptr);
  }
};

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
    field<T,I> f(a);
    return (*this)[f];
  }

  str(std::string s)
    : s(s)
  {
  }

  operator std::string()
  {
    return s;
  }
  
  elt operator[](str i);
};

class elt {
public:
  str s;
  str i;

  elt(str s, str i)
    : s(s), i(i)
  {
  }

  elt(str s)
    : s(s), i("")
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
    field<T,I> f(a);
    return (*this)[f];
  }
};

elt
str::operator[](str i)
{
  return elt(*this, i);
}

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
    if (v.size() > 1)
      v[1] = "0";
  }

  range(std::string base)
    : v(NWORDS(sizeof(I)))
  {
    v[0] = str(base);
    if (v.size() > 1)
      v[1] = "0";
  }

  range(const char *base)
    : v(NWORDS(sizeof(I)))
  {
    v[0] = str(base);
    if (v.size() > 1)
      v[1] = "0";
  }

  template<typename T>
  range(elt base, field<T,I> f)
    : v(NWORDS(sizeof(I)))
  {
    unsigned long off = f.off;
    unsigned long size = f.size;
    std::string infix("");
    size_t i = 0;

    if (std::string(base.i) != "")
      infix = "+" + std::string(base.i) + "*" + to_string(sizeof(T));
    while (size >= 4) {
      v[i++] = "HEAP32[" + std::string(base.s) + infix + "+" + to_string(off) + ">>2]";
      off += 4;
      size -= 4;
    }
    if (size >= 2) {
      v[i++] = "HEAP16[" + std::string(base.s) + infix + "+" + to_string(off) + ">>1]";
      off += 2;
      size -= 2;
    }
    if (size >= 1) {
      v[i++] = "HEAP8[" + std::string(base.s) + infix + "+" + to_string(off) + "]";
      off += 1;
      size -= 1;
    }
  }

  template<typename T>
  range(elt base, I T::* a)
    : v(NWORDS(sizeof(I)))
  {
    field<T,I> f(a);
    range(base, f);
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
