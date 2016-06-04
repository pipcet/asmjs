#include <stdlib.h>
#include <stdio.h>

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

  __attribute__((jsexport)) int get_x(int);
  __attribute__((jsexport)) static int get_y(int);
};

int
cl::get_x(int)
{
  return 2;
}

int
cl::get_y(int)
{
  return 3;
}


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

int main(void)
{
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
}

