#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <alloca.h>

int f(int x, long long y, double z, const char *str)
{
  fprintf(stderr, "%d %lld %f %s\n", x, y, z, str);

  return (int)__builtin_frame_address(0);
}

__attribute__((jsexport)) typeof(f) f;

const char *stringstring(const char *str)
{
  char *ret;

  asprintf(&ret, "%s%s", str, str);

  return ret;
}

__attribute__((jsexport)) typeof(stringstring) stringstring;

__attribute__((jsexport)) typedef typeof(stringstring) x;

asm(".include \"import-macros.s\"");
asm(".import3 thinthin,queue_peek,__thinthin_queue_peek");
asm(".import3 thinthin,queue_pop,__thinthin_queue_pop");
asm(".import3 thinthin,queue_return,__thinthin_queue_return");

extern "C"
__attribute__((stackcall))
int
__thinthin_queue_peek();

extern "C"
__attribute__((stackcall))
int
__thinthin_queue_pop(void (**)(long, long, void *, double *),
                     void *,
                     void *);

extern "C"
__attribute__((stackcall))
int
__thinthin_queue_return(void *);


int main(void)
{
  printf("in main(2)\n");
  printf("in main\n");
  void (***pptr0)() = (void (***)())(4096*4);
  void (***pptr1)() = (void (***)())(4096*4 + 4);

  void (**ptr)() = *pptr0;

  while (ptr < *pptr1) {
    printf("calling %p\n", *ptr);
    try {
      (**ptr)();
    } catch (...) {
      printf("Exception!\n");
    }
    ptr++;
  }

  int size;
  while (1) {
    printf("peeking...\n");
    if ((size = __thinthin_queue_peek()) > 0) {
      double stack[1+size];
      void (*apply)(long, long, void *, double *);
      void *fun;

      memset(stack, 0, (1+size) * sizeof(double));

      __thinthin_queue_pop(&apply, &fun, stack+1);

      //printf("queue pop returned %d %p %p [%f] %p\n", size, apply, fun,
      //stack[1], stack);

      apply(0, 0, fun, stack);

      //printf("rv %08x\n", (int)stack[0]);

      __thinthin_queue_return(stack);
    }
  }
}
