#include <stdio.h>

int f()
{
    throw "hello world";
}

int main()
{
  try {
    f();
    throw 7;
  } catch (const char *s) {
    printf("exception: %s\n", s);
  }
}
