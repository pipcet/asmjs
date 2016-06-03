#include <stdio.h>

void hi(int) __attribute__((jsexport));

void hi() __attribute__((jsexport));

void hi()
{
  printf("hi\n");
}

void asmjs_halt()
{
}

int main()
{
  asmjs_halt();
}
