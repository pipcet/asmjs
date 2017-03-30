#include <stdio.h>
#include <stdarg.h>

int f(int count, ...)
{
  char buf[1024];
  va_list ap;

  va_start(ap,count);
  vsprintf(buf, "%g %g %g %g  %g %g %g %g  %g %g %g %g  %g %g %g %g\n", ap);

  va_end(ap);

  fprintf(stderr, "%s\n", buf);

  return 0;
}

int main(void)
{
  f(16, 1.0, 2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0);

  return 0;
}
