#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

asm(".include \"wasm32-import-macros.s\"");

asm(".import3_pic thinthin,dlload,__thinthin_dlload");
asm(".import3_pic thinthin,dlreaddep,__thinthin_dlreaddep");
asm(".import3_pic thinthin,dlinstantiate,__thinthin_dlinstantiate");
asm(".import3_pic thinthin,dlsym,__thinthin_dlsym");

extern long __thinthin_dlload(const char *path, unsigned long *memp)
  __attribute__((stackcall));
extern long __thinthin_dlreaddep(long modi, char *mem, unsigned long len)
  __attribute__((stackcall));
extern long __thinthin_dlinstantiate(long modi, void *mem)
  __attribute__((stackcall));
extern void *__thinthin_dlsym(long modi, const char *symbol)
  __attribute__((stackcall));

void *dlopen(const char *path, int flags)
{
  long modi;
  unsigned long mem;
  char *buf;
  long off;
  long len;
  char *p;

  if (!(flags & RTLD_LAZY) &&
      !(flags & RTLD_NOW))
    return NULL;

  if (path)
    {
      modi = __thinthin_dlload(path, &mem);

      off = 0;
      len = 1;
      buf = malloc(len);
      buf[0] = 0;

      while ((off += __thinthin_dlreaddep(modi, buf + off, len - off)) == len)
        {
          len *= 2;
          buf = realloc(buf, len);
        }

      __thinthin_dlinstantiate(modi, mem ? malloc(mem) : NULL);

      for (p = buf; p < buf+off; p += strlen(p) + 1)
        dlopen(p, flags);
    }
  else
    {
      modi = 1;
    }

  return (void *)modi;
}

void *dlsym(void *handle, const char *symbol)
{
  return __thinthin_dlsym((long)handle, symbol);
}

int dlclose(void *handle)
{
  return 0;
}

int main(void)
{
  void *handle = dlopen("003-f.wasm", RTLD_NOW);

  int (*f)(void) = dlsym(handle, "f");

  printf("f: %d\n", f());

  return 0;
}
