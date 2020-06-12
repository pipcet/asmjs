#include <stdio.h>

int main(void)
{
  __SIZE_TYPE__ s = 0;
  size_t s2 = 0;
  
  fprintf(stderr, "%d\n", sizeof(s));
}
