#include <stdlib.h>

int main(void)
{
  volatile void *p = malloc(512);

  return p != 0;
}
