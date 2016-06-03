#include <stdlib.h>
#include <stdio.h>

#define JSEXPORT(what, name, prototype)                          \
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
    printf("%s %s %p\n", name, #prototype, (void *)what2);        \
  }                                                              \
                                                                 \
  void jsexport_ ## what (void)                                  \
  {                                                              \
    jsexport2_##what ((void *)what);                             \
  }

__attribute__((stackcall)) extern int f(int a, int b);

__attribute__((stackcall, regparm(3))) __attribute__((always_inline)) extern int g(int);

__attribute__((stackcall)) __attribute__((jsexport)) int h(int, long long);
__attribute__((stackcall)) __attribute__((jsexport)) int k(int, long long);

JSEXPORT(qsort, "qsort", int (*qsort)(void *, size_t, size_t, int (*)(const void *, const void *)))
                                                        
int main(void)
{
}
