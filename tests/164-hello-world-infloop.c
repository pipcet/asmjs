#include <stdio.h>

asm(".include \"wasm32-import-macros.s\"");

asm(".import3 thinthin,syscall,__thinthin_syscall");

extern long __thinthin_syscall(long n, ...) __attribute__((stackcall));

long long __wasm_syscall(long long n, long long a1, long long a2, long long a3, long long a4, long long a5, long long a6) __attribute__((stackcall));


long long __wasm_syscall(long long n, long long a1, long long a2, long long a3, long long a4, long long a5, long long a6) {
  return __thinthin_syscall(n, a1, a2, a3, a4, a5, a6);
}
int main(void)
{
  int (*p)(const char *) = puts;
  for (;;)
    p("hello world");
}
