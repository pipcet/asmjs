#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...)
{
  __isoc_va_list args;
  void *args2;

  va_start(args, format);
  printf("args is %p %p\n", args, *(void **)args);
  args2 = (void *)(*(void **)&args);
  args2 += 4;
  vprintf(format, ((void *)&args2));
  va_end(args);

  return ;
}

int main(void)
{
  my_printf("hi\n");
  my_printf("hi %p=%s, %s, %s, %d %x %o %p %d %p\n",
            main, "hi", "there", "this", 10, 10, 10, main, 10, main);
  printf("hi %p=%s, %s, %s, %d %x %o %p %d %p\n",
         main, "hi", "there", "this", 10, 10, 10, main, 10, main);

}
