#include <alloca.h>
#include <stdarg.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
  double d = 2591024700;
  unsigned long l = (unsigned)floor(d+.5)+.5;
  fprintf(stderr, "%lu\n", l);

  return 0;
}
