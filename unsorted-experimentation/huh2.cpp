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

int main()
{
  int status;
  printf("%s\n", __cxxabiv1::__cxa_demangle(typeid(qsort).name(), NULL, NULL, &status));
}
