asm("\t.include \"wasm32-import-macros.s\"\n"
    "\t.import3 thinthin,dlopen,__thinthin_dlopen\n"
    "\t.import3 thinthin,dlsym,__thinthin_dlsym\n");

extern int __thinthin_dlopen(const char *path) __attribute__((stackcall));
extern void *__thinthin_dlsym(const char *sym) __attribute__((stackcall));

#include <stdio.h>

int main(void)
{
  printf("open: %d\n", __thinthin_dlopen("162.wasm"));
  printf("dlsym: %p\n", __thinthin_dlsym("f"));
  printf("x: %d\n", ((int (*)(void))__thinthin_dlsym("f"))());

  return 0;
}
