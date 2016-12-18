#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <fcntl.h>

asm(".include \"wasm32-import-macros.s\"");

asm(".import3_pic thinthin,dlload,__thinthin_dlload");
asm(".import3_pic thinthin,dlreaddep,__thinthin_dlreaddep");
asm(".import3_pic thinthin,dlinstantiate,__thinthin_dlinstantiate");
asm(".import3_pic thinthin,dlsym,__thinthin_dlsym");

extern long __thinthin_dlload(const void *data, unsigned long len,
                              unsigned long *memp)
  __attribute__((stackcall));
extern long __thinthin_dlreaddep(long modi, char *mem, unsigned long len)
  __attribute__((stackcall));
extern long __thinthin_dlinstantiate(long modi, void *mem)
  __attribute__((stackcall));
extern void *__thinthin_dlsym(long modi, const char *symbol)
  __attribute__((stackcall));

static void *slurp(const char *path, size_t *lenp)
{
  int fd;
  fd = open(path, O_RDONLY);

  if (fd < 0)
    return NULL;

  size_t off = 0;
  size_t len = 4096;
  void *buf = malloc(len);

  if (!buf)
    return NULL;

  while (1) {
    ssize_t ret = read(fd, buf+off, len-off);

    if (ret < 0) {
      free(buf);
      close(fd);
      return NULL;
    }

    off += ret;

    if (off < len) {
      close(fd);
      buf = realloc(buf, off);
      if (!buf)
        return NULL;
      *lenp = off;
      return buf;
    }

    len *= 2;
    buf = realloc(buf, len);

    if (!buf) {
      close(fd);
      return NULL;
    }
  }
}

void *dlopen(const char *path, int flags)
{
  long modi;
  unsigned long mem;
  char *buf;
  long off;
  long len;
  char *p;

  printf("dlopen %s\n", path);

  if (!(flags & RTLD_LAZY) &&
      !(flags & RTLD_NOW))
    return NULL;

  if (path)
    {
      size_t modlen;
      void *data = slurp(path, &modlen);

      modi = __thinthin_dlload(data, modlen, &mem);

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

char *dlerror(void)
{
  return NULL;
}
