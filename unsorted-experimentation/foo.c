#include <stdlib.h>
__attribute__((stackcall)) extern int f(int a, int b);

__attribute__((stackcall, regparm(3))) __attribute__((always_inline)) extern int g(int);

__attribute__((stackcall)) __attribute__((jsexport)) int h(int, long long);
__attribute__((stackcall)) __attribute__((jsexport)) int k(int, long long);

  __attribute__((jsexport)) typeof(qsort) qsort;

int main(void)
{
}
