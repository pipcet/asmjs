extern float ldexpf(float, int);

#include <stdio.h>

int main(void)
{
  printf("%f\n", ldexpf(1.0, 6));

  return 0;
}
