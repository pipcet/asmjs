#include <stdio.h>

int fi(int) __attribute__((rawcall));
long long fl(long long) __attribute__((rawcall));
float ff(float) __attribute__((rawcall));
double fd(double) __attribute__((rawcall));
void fv(void) __attribute__((rawcall));

int fi(int x)
{
  return x * x;
}

long long fl(long long x)
{
  return x * x;
}

float ff(float x)
{
  return x * x;
}

double fd(double x)
{
  return x * x;
}

void fv(void)
{
}

int main(void)
{
  printf("%d\n", fi(42));
  printf("%lld\n", fl(42));
  printf("%f\n", ff(42.5));
  printf("%f\n", fd(42.25));

  fv();

  return 0;
}
