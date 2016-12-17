#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

asm(".include \"wasm32-import-macros.s\"");

asm(".import3_pic thinthin,dlload,__thinthin_dlload");
asm(".import3_pic thinthin,dlreaddep,__thinthin_dlreaddep");
asm(".import3_pic thinthin,dlinstantiate,__thinthin_dlinstantiate");

extern long __thinthin_dlload(const char *path, unsigned long *memp)
  __attribute__((stackcall));
extern long __thinthin_dlreaddep(long modi, char *mem, unsigned long len)
  __attribute__((stackcall));
extern long __thinthin_dlinstantiate(long modi, void *mem)
  __attribute__((stackcall));

int main(void)
{
  long modi;
  unsigned long mem;
  char *buf;
  long off;
  long len;

  printf("starting\n");

  modi = __thinthin_dlload("002-x.wasm", &mem);

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

  printf("inst %ld\n", __thinthin_dlinstantiate(modi, malloc(mem)));

  return 0;
}
