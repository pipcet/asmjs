#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define JSEXPORT(what, name, prototype)                          \
  class jsexport_##what {                                        \
    prototype;                                                   \
                                                                 \
  public:                                                        \
  jsexport_##what(prototype)                                     \
    : what(what)                                                 \
    {                                                            \
      printf("%s %s %p\n", name, #prototype, (void *)what);      \
    }                                                            \
  };                                                             \
                                                                 \
  jsexport_##what __jsexport_##what(what);

#define JSEXPORT_OLD(what, name, prototype)                      \
  void jsexport_ ## what (void) __attribute__((constructor));    \
  void jsexport2_ ## what (void *what2)                          \
  {                                                              \
    prototype = nullptr;                                         \
    what = (decltype(what))what2;                                \
    asm(".pushsection .jsexport." name "\n\t"                    \
        ".asciz \"" #what "\"\n\t"                               \
        ".asciz \"" name "\"\n\t"                                \
        ".asciz \"" #prototype "\"\n\t"                          \
        ".popsection");                                          \
                                                                 \
    printf("%s %s %p\n", name, #prototype, (void *)what2);       \
  }                                                              \
                                                                 \
  void jsexport_ ## what (void)                                  \
  {                                                              \
    jsexport2_##what ((void *)what);                             \
  }


struct __attribute__((jsexport)) cl;

struct cl {
  int x;
  int y;
  int z;
#if 1
  int b1 : 7;
  int b2 : 13;
  int b3 : 4;
  int b4 : 31;
  int b5 : 31;
#endif
  __attribute__((jsexport)) int get_x(int);
  __attribute__((jsexport)) static int get_y(int);
  struct cl *next;
};

int
cl::get_x(int)
{
  return x;
}

int
cl::get_y(int)
{
  return 3;
}

__attribute__((jsexport)) cl c0 = { 1, 2, 3 };

__attribute__((jsexport)) void hi();
__attribute__((jsexport)) typeof(malloc) malloc;
__attribute__((jsexport)) static void bye();
void hi()
{
  printf("hi\n");
}

static void bye()
{
  printf("bye\n");
}

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
    while ((size = __thinthin_queue_peek()) >= 0) {
      double stack[1+size];
      void (*apply)(long, long, void *, double *);
      void *fun;

      memset(stack, 0, (1+size) * sizeof(double));

      __thinthin_queue_pop(&apply, &fun, stack+1);

      printf("queue pop returned %p %p [%f]\n", apply, fun,
             stack[1]);

      apply(0, 0, fun, stack);

      printf("rv %f\n", stack[0]);

      __thinthin_queue_return(stack);
    }
  }
}
