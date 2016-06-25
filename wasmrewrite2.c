#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define xmalloc malloc
#define xrealloc realloc

typedef unsigned char u8;

u8 *gbuf;
u8 *gmask;

unsigned long roff = 0;
unsigned long woff = 0;

int mgetchar(void)
{
  gmask[roff] = 0;
  return gbuf[roff++];
}

void mputchar(int c)
{
  gmask[woff] = 0xff;
  gbuf[woff++] = c;
}

void mskipchar(void)
{
  woff++;
}

void msetchar(unsigned long off, int c)
{
  gmask[off] = 0xff;
  gbuf[off] = c;
}

void msetuleb128(unsigned long off, unsigned long value)
{
  int i = 0;
  do {
    u8 c = value & 0x7f;
    value >>= 7;
    i++;
    if (gmask[off]) {
      fprintf(stderr, "msetuleb128 %d %ld\n", i, off);
      abort();
    }
    gbuf[off] = (c | (value?0x80:0));
    gmask[off] = 0xff;
    off++;
  } while(value);
}

void mputuleb128(unsigned long value)
{
  do {
    u8 c = value & 0x7fL;
    value >>= 7;
    if (gmask[woff]) {
      fprintf(stderr, "mputuleb128\n");
      abort();
    }
    gbuf[woff] = (c | (value?0x80:0));
    gmask[woff] = 0xff;
    woff++;
  } while(value);
}

unsigned long mgetuleb128(void)
{
  int c;
  long value = 0;
  long shift = 0;
  int i = 0;

  while (1) {
    i++;
    c = mgetchar();
    if (c == EOF)
      exit(1);

    value += (c & 0x7fL) << shift;
    shift += 7;

    if (!(c & 0x80)) {
      //fprintf(stderr, "read %d-byte uleb at %ld\n", i, roff);
      return value;
    }
  }
}

void mputsleb128(long value)
{
  u8 c;
  int more;
  do {
    c = value & 0x7fL;
    value >>= 7;
    if (gmask[woff]) {
      fprintf(stderr, "mputuleb128\n");
      abort();
    }
    more = (value && value != -1) || (!!(c&0x40) != (value < 0));
    gbuf[woff] = (c | (more?0x80:0));
    gmask[woff] = 0xff;
    woff++;
  } while(more);
}

long mgetsleb128(void)
{
  int c;
  long value = 0;
  long shift = 0;

  while (1) {
    c = mgetchar();
    if (c == EOF)
      exit(1);

    value += (c & 0x7fL) << shift;
    shift += 7;

    if (!(c & 0x80)) {
      if (c & 0x40)
        return value | (-1 << shift);
      else
        return value;
    }
  }
}

void msynch(void)
{
  woff = roff;
}

unsigned long mgetsize(unsigned long *off0p, unsigned long *off1p)
{
  unsigned long size;
  *off0p = roff;
  size = mgetuleb128();
  *off1p = roff;

  return size;
}

void msetsize(unsigned long off0, unsigned long off1)
{
  unsigned long off;
  unsigned long len = 0;

  for (off = off1; off < roff; off++)
    if (gmask[off])
      len++;
  msetuleb128(off0, len);
}

char *mgetstring(void)
{
  unsigned long len = mgetuleb128();
  char *ret = xmalloc(len+1);
  char *p = ret;
  unsigned long i = 0;

  while (i++ < len)
    *p++ = mgetchar();

  ret[len] = 0;

  return ret;
}

void mputstring(char *string)
{
  unsigned long len = strlen(string);
  char *p = string;
  unsigned long i = 0;

  mputuleb128(len);

  while (i++ < len)
    mputchar(*p++);

  free(string);
}

char *mgetbytes(unsigned long len)
{
  char *ret = xmalloc(len);
  char *p = ret;

  while (len--)
    *p++ = mgetchar();

  return ret;
}

void mputbytes(char *bytes, unsigned long len)
{
  char *p = bytes;

  while (len--)
    mputchar(*p++);

  free(bytes);
}

void ast(unsigned long len)
{
  unsigned long off0 = roff;
  unsigned long target_count;

  while (roff < off0 + len) {
    u8 c = mgetchar();
    switch (c) {
    case 0x00 ... 0x05:
    case 0x0a:
    case 0x0f:
    case 0x39:
    case 0x3b:
    case 0x40 ... 0xba:
      mputchar(c);
      break;

    case 0x10:
    case 0x11:
      mputchar(c);
      mputsleb128(mgetsleb128());
      msynch();
      break;

    case 0x09:
    case 0x14:
    case 0x15:
      mputchar(c);
      mputuleb128(mgetuleb128());
      msynch();
      break;

    case 0x12:
      mputchar(c);
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      break;

    case 0x13:
      mputchar(c);
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      break;

    case 0x06:
    case 0x07:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x20 ... 0x36:
      mputchar(c);
      mputuleb128(mgetuleb128());
      msynch();
      mputuleb128(mgetuleb128());
      msynch();
      break;

    case 0x08:
      mputchar(c);
      mputuleb128(mgetuleb128());
      msynch();
      mputuleb128(target_count = mgetuleb128());
      msynch();
      target_count++;
      while (target_count--) {
        mputchar(mgetchar());
        mputchar(mgetchar());
        mputchar(mgetchar());
        mputchar(mgetchar());
      }
      break;

    default:
      fprintf(stderr, "ast %02x %lx\n", (int)c, roff);
      for(;;);
      abort();
    }
  }
  static int index = 0;
  fprintf(stderr, "ast read %ld bytes ending at %ld %lx\n", len, roff, index++);
}

void local_entry(void)
{
  unsigned long count;
  mputuleb128(count = mgetuleb128());
  msynch();

  mputchar(mgetchar());
}

void function_body(void)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);
  unsigned long nlocals;
  unsigned long end;

  msynch();

  end = roff + len;

  mputuleb128(nlocals = mgetuleb128());
  msynch();

  while (nlocals--)
    local_entry();

  ast(end - roff);
  msynch();

  msetsize(off0, off1);
  msynch();
}

void section_code(char *name)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);

  if (len) {
    unsigned long count;
    mputstring(name);
    msynch();
    mputuleb128(count = mgetuleb128());
    msynch();
    while (count--)
      function_body();
    msetsize(off0, off1);
  }
}

void type_entry(void)
{
  unsigned long off0, off1;
  unsigned long len;

  mputchar(mgetchar());
  len = mgetsize(&off0, &off1);

  msynch();
  mputbytes(mgetbytes(len), len);
  msetsize(off0, off1);
  
  len = mgetsize(&off0, &off1);
  
  msynch();
  mputbytes(mgetbytes(len), len);
  msetsize(off0, off1);
}

void section_type(char *name)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);
  unsigned long count;

  if (len) {
    mputstring(name);
    msynch();
    mputuleb128(count = mgetuleb128());
    msynch();
    while (count--)
      type_entry();
    msetsize(off0, off1);
  }
}

void import_entry(void)
{
  mputuleb128(mgetuleb128());
  msynch();
  mputstring(mgetstring());
  msynch();
  mputstring(mgetstring());
  msynch();
}

void section_import(char *name)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);
  unsigned long count;

  if (len) {
    mputstring(name);
    msynch();
    mputuleb128(count = mgetuleb128());
    msynch();
    while (count--)
      import_entry();
    msetsize(off0, off1);
  }
}

void export_entry(void)
{
  mputuleb128(mgetuleb128());
  mputstring(mgetstring());
  msynch();
}

void section_export(char *name)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);
  unsigned long count;

  if (len) {
    mputstring(name);
    msynch();
    mputuleb128(count = mgetuleb128());
    msynch();
    while (count--)
      export_entry();
    msetsize(off0, off1);
  }
}

void section_table(char *name)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);
  unsigned long count;

  if (len) {
    mputstring(name);
    msynch();
    mputuleb128(count = mgetuleb128());
    msynch();
    while (count--) {
      mputuleb128(mgetuleb128());
      msynch();
    }
    msetsize(off0, off1);
  }
}

void section_function(char *name)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);
  unsigned long count;

  if (len) {
    mputstring(name);
    msynch();
    mputuleb128(count = mgetuleb128());
    msynch();
    while (count--)
      mputuleb128(mgetuleb128());
    msetsize(off0, off1);
  }
}

void section_simple(char *name)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);

  if (len) {
    mputstring(name);
    msynch();
    mputbytes(mgetbytes(len), len);
    msetsize(off0, off1);
  }
}

void section(void)
{
  char *name = mgetstring();

  if (strcmp(name, "type") == 0) {
    section_type(name);
  } else if (strcmp(name, "import") == 0) {
    section_import(name);
  } else if (strcmp(name, "function") == 0) {
    section_function(name);
  } else if (strcmp(name, "memory") == 0) {
    section_simple(name);
  } else if (strcmp(name, "export") == 0) {
    section_export(name);
  } else if (strcmp(name, "table") == 0) {
    section_table(name);
  } else if (strcmp(name, "code") == 0) {
    section_code(name);
  } else if (strcmp(name, "start") == 0) {
    section_simple(name);
  } else if (strcmp(name, "data") == 0) {
    section_simple(name);
  } else if (strcmp(name, "name") == 0) {
    section_simple(name);
  } else {
    abort();
  }
}
int main(int argc, char **argv)
{
  size_t size = 4096;
  gbuf = xmalloc(size);
  size_t off = 0;
  size_t res = 0;
  FILE *f = fopen(argv[1], "r");

  while (res = fread(gbuf+off, 1, size-off, f)) {
    off += res;
    size *= 2;
    gbuf = xrealloc(gbuf, size);
  }

  gmask = xmalloc(size);
  memset(gmask, 0xff, size);

  mputchar(mgetchar());
  mputchar(mgetchar());
  mputchar(mgetchar());
  mputchar(mgetchar());
  mputchar(mgetchar());
  mputchar(mgetchar());
  mputchar(mgetchar());
  mputchar(mgetchar());
  while (roff < off) {
    section();
  }

  for (woff = 0; woff < off; woff++) {
    if (gmask[woff])
      putchar(gbuf[woff]);
  }

  return 0;
}
