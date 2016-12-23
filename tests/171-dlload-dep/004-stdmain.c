#include <dlfcn.h>
#include <stdio.h>

int main(void)
{
  void *handle = dlopen("003-f.so", RTLD_NOW|RTLD_GLOBAL);
  void *sym = dlsym(handle, "x");

  printf("%p\n", sym);

  return 0;
}
