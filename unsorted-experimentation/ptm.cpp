#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <string>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <cxxabi.h>
#include <vector>

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
    return s + "+" + std::to_string(a.off) + "-" + std::to_string(a.size);
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
  
  elt operator[](size_t i);
};

class elt {
public:
  str s;
  size_t i;

  elt(str s, size_t i)
    : s(s), i(i)
  {
  }

  elt(str s)
    : s(s), i(0)
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
str::operator[](size_t i)
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
      v[i++] = std::to_string(word);
      size -= 4;
      off += 4;
    }
    if (size >= 2) {
      short word = *(short *)((char *)(&iv) + off);
      v[i++] = std::to_string(word);
      size -= 2;
      off += 2;
    }
    if (size >= 1) {
      signed char word = *(signed char *)((char *)(&iv) + off);
      v[i++] = std::to_string(word);
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
    unsigned long off = base.i * sizeof(T) + f.off;
    unsigned long size = f.size;
    size_t i = 0;
    while (size >= 4) {
      v[i++] = "HEAP32[" + std::string(base.s)  + "+" + std::to_string(off) + ">>2]";
      off += 4;
      size -= 4;
    }
    if (size >= 2) {
      v[i++] = "HEAP16[" + std::string(base.s)  + "+" + std::to_string(off) + ">>1]";
      off += 2;
      size -= 2;
    }
    if (size >= 1) {
      v[i++] = "HEAP8[" + std::string(base.s)  + "+" + std::to_string(off) + "]";
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

  range<I>
  operator=(range<I> val)
  {
    range<I> ret(*this);

    for (size_t i = 0; i < ret.v.size(); i++) {
      ret.v[i] += " = " + val.v[i] + ";";
      if (i < ret.v.size() - 1)
        ret.v[i] += " ";
    }

    return ret;
  }

  operator std::string()
  {
    std::string ret;

    for (size_t i = 0; i < v.size(); i++)
      ret += v[i];

    return ret;
  }
};

struct a {
  int x;
  int y;
  int z;
  long long w;
};

struct b {
  int x;
  short y;
  char z;
};

struct c {
  a x;
  b y;
  b z;
};

str tvptr("tvptr");
str tvptr2("tvptr2");

int main(void)
{
  std::cout << std::string(tvptr[&a::z] = 7) << "\n";
  std::cout << std::string(tvptr[&a::w] = -8) << "\n";
  std::cout << std::string(tvptr2[&a::x] = tvptr[&a::y]) << "\n";
  std::cout << std::string(tvptr2[&a::w] = tvptr[&a::w]) << "\n";
  std::cout << std::string(tvptr[&c::y] = tvptr[&c::z]) << "\n";
  std::cout << sizeof(c) << "\n";
  std::cout << std::string(tvptr[3][&c::y] = tvptr[&c::z]) << "\n";
}
