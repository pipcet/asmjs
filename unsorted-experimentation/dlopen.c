#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  void *handle = dlopen(argv[0], 0);

  printf("%p\n", dlsym(handle, "main"));

  return 0;
}
