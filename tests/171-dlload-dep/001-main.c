#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

void *my_dlopen(const char *path)
{
  long modi;
  unsigned long mem;
  char *buf;
  long off;
  long len;
  char *p;

  printf("starting\n");

  modi = __thinthin_dlload(path, &mem);

  printf("modi %ld mem %lu\n", modi, mem);

  off = 0;
  len = 1;
  buf = malloc(len);
  buf[0] = 0;

  while ((off += __thinthin_dlreaddep(modi, buf + off, len - off)) == len) {
    len *= 2;
    buf = realloc(buf, len);
  }

  printf("buf %ld %s\n", off, buf);

  printf("inst %s %ld\n", path, __thinthin_dlinstantiate(modi, malloc(mem)));

  for (p = buf; p < buf+off; p += strlen(p) + 1)
    my_dlopen(p);

  return (void *)modi;
}

int main(void)
{
  void *handle = my_dlopen("003-f.wasm");

  int (*f)(void) = __thinthin_dlsym((long)handle, "f");

  printf("f: %d\n", f());

  return 0;
}
