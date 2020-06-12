#include <stdio.h>

class A {
  const char *str;
public:
  A(const char *str)
    : str(str)
  {
    printf("%s\n", str);
  }
};

A a("hi there");

int main()
{
  return 0;
}
