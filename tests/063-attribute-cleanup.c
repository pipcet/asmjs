#include <stdlib.h>

extern void cu(void**);

void cu2(void **ptrp)
{
  cu(ptrp);
}

int main(void)
{
  void * __attribute__((cleanup(cu2))) ptr = malloc(1024);

  return 0;
}
