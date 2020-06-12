#include <stdlib.h>

volatile void * volatile p;

int main(void)
{
  p = malloc(2);

  return 0;
}
