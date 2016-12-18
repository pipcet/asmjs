#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int main(void)
{
  printf("%p\n", dlopen);
  void *handle = dlopen("003-f.wasm", RTLD_NOW);

  int (*f)(void) = dlsym(handle, "f");

  printf("f: %d\n", f());

  return 0;
}
