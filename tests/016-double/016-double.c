#include <stdio.h>

int main(void)
{
  double d = 1.0;
  double e = 1.0 + 1.0;
  double f = e - d;

  fprintf(stderr, "d = %f e = %f f = %f\n", d, e, f);

  return 0;
}
