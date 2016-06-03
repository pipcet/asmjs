#include <stdlib.h>

#define JSEXPORT(what, name, prototype)           \
  asm(".pushsection .jsexport." name "\n\t"       \
      ".linkonce\n\t"                             \
      ".asciz \"" #what "\"\n\t"                  \
      ".asciz \"" name "\"\n\t"                   \
      ".asciz \"" #prototype "\"\n\t"             \
      ".popsection");

__attribute__((stackcall)) extern int f(int a, int b);

__attribute__((stackcall, regparm(3))) __attribute__((always_inline)) extern int g(int);

__attribute__((stackcall)) __attribute__((jsexport)) int h(int, long long);
__attribute__((stackcall)) __attribute__((jsexport)) int k(int, long long);

__attribute__((jsexport("qsort", qsort))) typeof(qsort) qsort;

JSEXPORT(qsort, "qsort", int (*qsort)(void *, size_t, size_t, int (*)(const void *, const void *)))
                                                        
int main(void)
{
}
