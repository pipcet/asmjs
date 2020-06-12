#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

asm(".include \"wasm32-import-macros.s\"");

extern int __thinthin_dlopen(const char *path) __attribute__((stackcall));
extern void *__thinthin_dlsym(const char *sym) __attribute__((stackcall));

asm(".import3 thinthin,syscall,__thinthin_syscall");

extern long __thinthin_syscall(long n, ...) __attribute__((stackcall));

long long __wasm_syscall(long long n, long long a1, long long a2, long long a3, long long a4, long long a5, long long a6) __attribute__((stackcall));


long long __wasm_syscall(long long n, long long a1, long long a2, long long a3, long long a4, long long a5, long long a6) {
  return __thinthin_syscall(n, a1, a2, a3, a4, a5, a6);
}
int main(void)
{
  __thinthin_syscall(1, 1, "hi0\n", 4);
  //__thinthin_dlopen("libc.wasm");
  __thinthin_syscall(1, 1, "hi1\n", 4);
  for (;;) {
    int count = fprintf(stderr, "hey there: %p %p\n", stdout, stderr);
    break;
  }
}
