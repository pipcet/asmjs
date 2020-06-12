#include <alloca.h>
#include <stdarg.h>
#include <stdio.h>

typedef void **my_va_list;
#define my_va_start(v,l) do { \
    v = alloca(4);            \
    __builtin_va_start(*v,l); \
    *v += 4;                  \
} while(0)

#define my_va_end(v) do { \
    __builtin_va_end(*v); \
} while(0)

void my_printf(const char *format, ...)
{
  my_va_list args;

  my_va_start(args, format);
  printf("args is %p %p\n", args, *(void **)args);
  vprintf(format, args);
  my_va_end(args);

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
