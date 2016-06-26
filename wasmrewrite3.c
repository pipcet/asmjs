#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

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

long msetuleb128(unsigned long off, unsigned long value)
{
  int i = 0;
  long delta = 0;

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
    delta--;
  } while(value);

  return delta;
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

long msynch(void)
{
  long delta = roff - woff;

  woff = roff;

  return delta;
}

unsigned long mgetsize(unsigned long *off0p, unsigned long *off1p)
{
  unsigned long size;
  *off0p = roff;
  size = mgetuleb128();
  *off1p = roff;

  return size;
}

long msetsize(unsigned long off0, unsigned long off1, long delta)
{
  unsigned long off;
  unsigned long len = 0;

  for (off = off1; off < roff; off++)
    if (gmask[off])
      len++;
  assert(len == roff - off0 - delta);
  return msetuleb128(off0, len);
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

char *mpeekstring(void)
{
  unsigned long roff_saved = roff;
  unsigned long len = mgetuleb128();
  char *ret = xmalloc(len+1);
  char *p = ret;
  unsigned long i = 0;

  while (i++ < len)
    *p++ = mgetchar();

  ret[len] = 0;

  roff = roff_saved;

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

long ast(unsigned long len)
{
  unsigned long off0 = roff;
  unsigned long target_count;
  long delta = 0;

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
      delta += msynch();
      break;

    case 0x09:
    case 0x14:
    case 0x15:
      mputchar(c);
      mputuleb128(mgetuleb128());
      delta += msynch();
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
      delta += msynch();
      mputuleb128(mgetuleb128());
      delta += msynch();
      break;

    case 0x08:
      mputchar(c);
      mputuleb128(mgetuleb128());
      delta += msynch();
      mputuleb128(target_count = mgetuleb128());
      delta += msynch();
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
  static long int index = 0;
  fprintf(stderr, "ast read %ld bytes ending at %ld %lx\n", len, roff, index++);

  return delta;
}

long local_entry(void)
{
  unsigned long count;
  long delta = 0;

  mputuleb128(count = mgetuleb128());
  delta += msynch();

  mputchar(mgetchar());
  delta += msynch();

  return delta;
}

long function_body(void)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);
  unsigned long nlocals;
  unsigned long end;
  long delta = 0;

  end = roff + len;

  delta += msynch();
  mputuleb128(nlocals = mgetuleb128());
  delta += msynch();

  while (nlocals--)
    delta += local_entry();

  delta += ast(end - roff);
  delta += msynch();

  delta += msetsize(off0, off1, delta);
  delta += msynch();

  return delta;
}

long section_code()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0;

  mputstring(mgetstring());
  msynch();
  len = mgetsize(&off0, &off1);
  if (len) {
    unsigned long count;
    delta += msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--)
      delta += function_body();
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long data_segment()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta0 = 0, delta = 0;

  mputuleb128(mgetuleb128());
  delta0 += msynch();
  len = mgetsize(&off0, &off1);
  delta += msynch();

  mputbytes(mgetbytes(len), len);
  delta += msetsize(off0, off1, delta);
  delta += msynch();

  return delta0 + delta;
}

long section_data()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0;
  mputstring(mgetstring());
  msynch();
  len = mgetsize(&off0, &off1);
  if (len) {
    unsigned long count;
    delta += msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--)
      delta += data_segment();
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long type_entry(void)
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0, delta2 = 0;

  mputchar(mgetchar());
  len = mgetsize(&off0, &off1);

  delta += msynch();
  mputbytes(mgetbytes(len), len);
  delta += msetsize(off0, off1, delta);

  len = mgetsize(&off0, &off1);

  delta2 += msynch();
  mputbytes(mgetbytes(len), len);
  delta2 += msetsize(off0, off1, delta2);

  return delta + delta2;
}

long section_type()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  mputstring(mgetstring());
  msynch();
  len = mgetsize(&off0, &off1);
  if (len) {
    delta += msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--)
      delta += type_entry();
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long import_entry(void)
{
  long delta = 0;

  mputuleb128(mgetuleb128());
  delta += msynch();
  mputstring(mgetstring());
  delta += msynch();
  mputstring(mgetstring());
  delta += msynch();

  return delta;
}

long section_import()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  mputstring(mgetstring());
  msynch();
  len = mgetsize(&off0, &off1);
  if (len) {
    delta += msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--)
      delta += import_entry();
    delta += msetsize(off0, off1, delta);
  } else {
    delta = msynch();
  }

  return delta;
}

long export_entry(void)
{
  long delta = 0;

  mputuleb128(mgetuleb128());
  delta += msynch();
  mputstring(mgetstring());
  delta += msynch();

  return delta;
}

long section_export()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  mputstring(mgetstring());
  msynch();
  len = mgetsize(&off0, &off1);
  if (len) {
    delta += msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--)
      delta += export_entry();
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long section_table()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  mputstring(mgetstring());
  msynch();
  len = mgetsize(&off0, &off1);
  if (len) {
    delta += msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--) {
      mputuleb128(mgetuleb128());
      delta += msynch();
    }
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long section_function()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  mputstring(mgetstring());
  msynch();
  len = mgetsize(&off0, &off1);
  if (len) {
    delta += msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--) {
      mputuleb128(mgetuleb128());
      delta += msynch();
    }
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long section_start()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0;

  mputstring(mgetstring());
  msynch();
  len = mgetsize(&off0, &off1);
  if (len) {
    delta += msynch();
    mputuleb128(mgetuleb128());
    delta += msynch();
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long section_simple()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0;

  mputstring(mgetstring());
  msynch();
  len = mgetsize(&off0, &off1);
  if (len) {
    delta += msynch();
    mputbytes(mgetbytes(len), len);
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long section(void)
{
  char *name = mpeekstring();
  long delta = 0;

  if (strcmp(name, "type") == 0) {
    delta += section_type();
  } else if (strcmp(name, "import") == 0) {
    delta += section_import();
  } else if (strcmp(name, "function") == 0) {
    delta += section_function();
  } else if (strcmp(name, "memory") == 0) {
    delta += section_simple();
  } else if (strcmp(name, "export") == 0) {
    delta += section_export();
  } else if (strcmp(name, "table") == 0) {
    delta += section_table();
  } else if (strcmp(name, "code") == 0) {
    delta += section_code();
  } else if (strcmp(name, "start") == 0) {
    delta += section_start();
  } else if (strcmp(name, "data") == 0) {
    delta += section_data();
  } else if (strcmp(name, "name") == 0) {
    delta += section_simple();
  } else {
    abort();
  }

  free(name);

  return delta;
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
