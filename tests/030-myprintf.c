#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...)
{
  __isoc_va_list args;

  va_start(args, format);
  printf("args is %p %p\n", args, *(void **)args);
  vprintf(format, args);
  va_end(args);

  return ;
}

int main(void)
{
  my_printf("hi\n");
  my_printf("hi %d\n", 42);

}
