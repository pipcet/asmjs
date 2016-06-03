#include <stdio.h>

class A {
public:
  A(void *)
  {
    printf("A!\n");
  }
};

A a(NULL);
