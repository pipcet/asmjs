#include <alloca.h>
#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...)
{
  va_list args;

  va_start(args, format);
  printf("args is %p %p\n", args, *(void **)args);
  vprintf(format, args);
  vfprintf(stdout, format, args);
  va_end(args);

  return ;
}

void my_fprintf(FILE *f, const char *format, ...)
{
  va_list args;

  va_start(args, format);
  printf("args is %p %p\n", args, *(void **)args);
  vfprintf(f, format, args);
  va_end(args);

  return ;
}

void my_fprintf2(void *dummy, FILE *f, const char *format, ...)
{
  va_list args;

  va_start(args, format);
  printf("args is %p %p\n", args, *(void **)args);
  vfprintf(f, format, args);
  va_end(args);

  return ;
}

void my_fprintf3(void *dummy, void *dummy2, FILE *f, const char *format, ...)
{
  va_list args;

  va_start(args, format);
  printf("args is %p %p\n", args, *(void **)args);
  vfprintf(f, format, args);
  va_end(args);

  return ;
}

void my_fprintf4(void *dummy, void *dummy2, void *dummy3, FILE *f, const char *format, ...)
{
  va_list args;

  va_start(args, format);
  printf("args is %p %p\n", args, *(void **)args);
  vfprintf(f, format, args);
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

  my_fprintf(stdout, "hi %p=%s, %s, %s, %d %x %o %p %d %p\n",
             main, "hi", "there", "this", 10, 10, 10, main, 10, main);

  my_fprintf2(NULL, stdout, "hi %p=%s, %s, %s, %d %x %o %p %d %p\n",
             main, "hi", "there", "this", 10, 10, 10, main, 10, main);

  my_fprintf3(NULL, NULL, stdout, "hi %p=%s, %s, %s, %d %x %o %p %d %p\n",
             main, "hi", "there", "this", 10, 10, 10, main, 10, main);

  my_fprintf4(NULL, NULL, NULL, stdout, "hi %p=%s, %s, %s, %d %x %o %p %d %p\n",
             main, "hi", "there", "this", 10, 10, 10, main, 10, main);
}
