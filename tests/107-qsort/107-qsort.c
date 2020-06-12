#include <stdlib.h>
#include <stdio.h>

int compar(const int *ap, const int *bp)
{
  printf("comparing %p/%d and %p/%d\n", ap, *ap, bp, *bp);
  //fprintf(stderr, "comparing %p/%d and %p/%d\n", ap, *ap, bp, *bp);

  return *ap - *bp;
}

int main(void)
{
  int array[] = { 5, 1, 13, 14, 12, 13, 9, 0 };
  volatile int k = 1;

  if (k)
    qsort(array, 8, 4, compar);

  for (int i = 0; i < 8; i++)
    printf("el %d: %d\n", i, array[i]);
}
