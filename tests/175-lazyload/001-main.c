#include <stdio.h>
#include <dlfcn.h>

extern void __wasm_lazyload_stub(void);

int main(void)
{
  *(void **)12416 = (void *)__wasm_lazyload_stub;
  printf("hi\n");

  volatile int dodl = 0;

  if (dodl)
    dlopen("hi", 0);

  printf("bye\n");

  return 0;
}
