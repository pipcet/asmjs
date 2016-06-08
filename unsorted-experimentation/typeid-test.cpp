#include <stdio.h>
#include <typeinfo>

int main()
{
  struct { int a; int b; int c; } something;
  printf("%s\n", typeid(something).name());

  return 0;
}
