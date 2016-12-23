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

void mputsleb128(long value, int bits)
{
  u8 c;
  int more;
  if (bits < 64)
    value |= (value & (1L<<(bits-1))) ? ((-1L) << bits) : 0;
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
        return value | (-1L << shift);
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
  //assert(len == roff - off1 - delta);
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

long ast(unsigned long len, unsigned long index)
{
  unsigned long off0 = roff;
  unsigned long target_count;
  long delta = 0;
  long block = 0;

  while (roff < off0 + len) {
    u8 c = mgetchar();
    switch (c) {
    case 0x01:
      delta += msynch();
      break;
    case 0x0b:
      block--;
    case 0x0f:
    case 0x00:
    case 0x05:
    case 0x1a:
    case 0x1b:
    case 0x45 ... 0xbf:
      mputchar(c);
      break;

    case 0x02 ... 0x04:
      block++;
    case 0x0c:
    case 0x0d:
    case 0x10:
    case 0x20 ... 0x24:
    case 0x3f:
    case 0x40 ... 0x41:
      mputchar(c);
      mputsleb128(mgetsleb128(), 32);
      delta += msynch();
      break;
    case 0x42:
      mputchar(c);
      mputsleb128(mgetsleb128(), 64);
      delta += msynch();
      break;
    case 0x43:
      mputchar(c);
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      delta += msynch();
      break;
    case 0x44:
      mputchar(c);
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      delta += msynch();
      break;

    case 0x11:
    case 0x28 ... 0x3e:
      mputchar(c);
      mputuleb128(mgetuleb128());
      mputuleb128(mgetuleb128());
      delta += msynch();
      break;

    case 0x0e:
      mputchar(c);
      mputuleb128(target_count = mgetuleb128());
      while (target_count--)
        mputuleb128(mgetuleb128());
      mputuleb128(mgetuleb128());
      delta += msynch();
      break;

    case 0x06:
      switch (mgetchar()) {
      case 1: /* jump */
        //mputchar(0x41);
        //mputchar(0x01);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+1, 32);
        break;
      case 2: /* throw */
        //mputchar(0x41);
        //mputchar(0x02);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+2, 32);
        break;
      case 3: /* jump1 */
        //mputchar(0x41);
        //mputchar(0x03);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+2, 32);
        break;
      case 4: /* throw1 */
        //mputchar(0x41);
        //mputchar(0x04);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+3, 32);
        break;
      case 5: /* jump2 */
        //mputchar(0x41);
        //mputchar(0x05);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+1, 32);
        break;
      }
      delta += msynch();
      break;

    default:
      fprintf(stderr, "ast %02x %lx\n", (int)c, roff);
      for(;;);
      abort();
    }
  }

  if (block != -1) {
    fprintf(stderr, "unbalanced %ld %lx %lx\n", block, roff, index);
    for(;;);
  }

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

long function_body(unsigned long index)
{
  unsigned long off0, off1;
  unsigned long len = mgetsize(&off0, &off1);
  unsigned long nlocals;
  unsigned long end;
  long delta = 0;
  long delta1;

  end = roff + len;

  /* delta += */ delta1 = msynch();
  mputuleb128(nlocals = mgetuleb128());
  delta += msynch();

  while (nlocals--)
    delta += local_entry();

  delta += ast(end - roff, index);
  delta += msynch();

  delta += msetsize(off0, off1, delta);
  delta += msynch();

  return delta + delta1;
}

long section_code()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0;
  unsigned long index = 0;

  len = mgetsize(&off0, &off1);
  if (len) {
    unsigned long count;
    /* delta += */ msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--)
      delta += function_body(index++);
    delta += msetsize(off0, off1, delta);
  } else {
    /* delta += */ msynch();
  }

  return delta;
}

long data_segment()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta0 = 0, delta = 0;
  long delta1;
  char c;

  mputuleb128(mgetuleb128());
  mputchar(mgetchar());
  mputuleb128(mgetuleb128());
  mputchar(mgetchar());
  delta0 += msynch();
  len = mgetsize(&off0, &off1);
  delta1 = msynch();

  mputbytes(mgetbytes(len), len);
  delta += msetsize(off0, off1, delta);
  delta += msynch();

  return delta0 + delta + delta1;
}

long section_data()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0;
  len = mgetsize(&off0, &off1);
  if (len) {
    unsigned long count;
    /* delta += */ msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--)
      delta += data_segment();
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msetsize(off0, off1, delta);
    delta += msynch();
  }

  return delta;
}

long func_type(void)
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  mputuleb128(mgetuleb128());
  delta += msynch();
  mputuleb128(count = mgetuleb128());
  delta += msynch();
  while (count--) {
    mputuleb128(mgetuleb128());
    delta += msynch();
  }
  mputuleb128(count = mgetuleb128());
  delta += msynch();
  while (count--) {
    mputuleb128(mgetuleb128());
    delta += msynch();
  }

  return delta;
}

long section_type()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  len = mgetsize(&off0, &off1);
  if (len) {
    /* delta += */ msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--)
      delta += func_type();
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long import_entry(void)
{
  long delta = 0;
  long kind = 0;

  delta += msynch();
  mputstring(mgetstring());
  delta += msynch();
  mputstring(mgetstring());
  mputuleb128(kind = mgetuleb128());
  switch (kind) {
  case 0:
    mputuleb128(mgetuleb128());
    break;
  case 1:
    mputuleb128(mgetuleb128());
    mputuleb128(mgetuleb128());
    mputuleb128(mgetuleb128());
    mputuleb128(mgetuleb128());
    break;
  case 2:
    mputuleb128(mgetuleb128());
    mputuleb128(mgetuleb128());
    mputuleb128(mgetuleb128());
    break;
  case 3:
    mputuleb128(mgetuleb128());
    mputuleb128(mgetuleb128());
    break;
  }
  delta += msynch();

  return delta;
}

long section_import()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  len = mgetsize(&off0, &off1);
  if (len) {
    /* delta += */ msynch();
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

  mputstring(mgetstring());
  delta += msynch();
  mputuleb128(mgetuleb128());
  mputuleb128(mgetuleb128());
  delta += msynch();

  return delta;
}

long section_export()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  len = mgetsize(&off0, &off1);
  if (len) {
    /* delta += */ msynch();
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

  len = mgetsize(&off0, &off1);
  if (len) {
    /* delta += */ msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--) {
      mputuleb128(mgetuleb128());
      mputuleb128(mgetuleb128());
      mputuleb128(mgetuleb128());
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

  len = mgetsize(&off0, &off1);
  if (len) {
    /* delta += */ msynch();
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

  len = mgetsize(&off0, &off1);
  if (len) {
    /* delta += */ msynch();
    mputuleb128(mgetuleb128());
    delta += msynch();
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long function_names(void)
{
  long delta = 0;
  unsigned long count;

  mputstring(mgetstring());
  delta += msynch();
  mputuleb128(count = mgetuleb128());
  delta += msynch();
  while (count--) {
    mputstring(mgetstring());
    delta += msynch();
  }

  return delta;
}

long section_simple()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0;

  len = mgetsize(&off0, &off1);
  if (len) {
    /* delta += */ msynch();
    mputbytes(mgetbytes(len), len);
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long section_memory()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  len = mgetsize(&off0, &off1);
  if (len) {
    /* delta += */ msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--) {
      mputuleb128(mgetuleb128());
      mputuleb128(mgetuleb128());
      mputuleb128(mgetuleb128());
      delta += msynch();
    }
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long init_expr()
{
  unsigned long off0 = roff;
  unsigned long target_count;
  long delta = 0;
  long block = 0;

  while (1) {
    u8 c = mgetchar();
    switch (c) {
    case 0x0b:
      mputchar(c);
      block--;
      goto out;
    case 0x0f:
    case 0x00 ... 0x01:
    case 0x05:
    case 0x1a:
    case 0x1b:
    case 0x45 ... 0xbf:
      mputchar(c);
      break;

    case 0x02 ... 0x04:
      block++;
    case 0x0c:
    case 0x0d:
    case 0x10:
    case 0x20 ... 0x24:
    case 0x3f:
    case 0x40 ... 0x41:
      mputchar(c);
      mputsleb128(mgetsleb128(), 32);
      delta += msynch();
      break;
    case 0x42:
      mputchar(c);
      mputsleb128(mgetsleb128(), 64);
      delta += msynch();
      break;
    case 0x43:
      mputchar(c);
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      delta += msynch();
      break;
    case 0x44:
      mputchar(c);
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      mputchar(mgetchar());
      delta += msynch();
      break;

    case 0x11:
    case 0x28 ... 0x3e:
      mputchar(c);
      mputuleb128(mgetuleb128());
      mputuleb128(mgetuleb128());
      delta += msynch();
      break;

    case 0x0e:
      mputchar(c);
      mputuleb128(target_count = mgetuleb128());
      while (target_count--)
        mputuleb128(mgetuleb128());
      mputuleb128(mgetuleb128());
      delta += msynch();
      break;

    case 0x06:
      switch (mgetchar()) {
      case 1: /* jump */
        //mputchar(0x41);
        //mputchar(0x01);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+1, 32);
        break;
      case 2: /* throw */
        //mputchar(0x41);
        //mputchar(0x02);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+2, 32);
        break;
      case 3: /* jump1 */
        //mputchar(0x41);
        //mputchar(0x03);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+2, 32);
        break;
      case 4: /* throw1 */
        //mputchar(0x41);
        //mputchar(0x04);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+3, 32);
        break;
      case 5: /* jump2 */
        //mputchar(0x41);
        //mputchar(0x05);
        //mputchar(0x1a);
        mputchar(0x0c);
        mputsleb128(mgetsleb128()+1, 32);
        break;
      }
      delta += msynch();
      break;

    default:
      fprintf(stderr, "ast %02x %lx\n", (int)c, roff);
      for(;;);
      abort();
    }
  }
 out:
  if (block != -1) {
    fprintf(stderr, "unbalanced %ld %lx %lx\n", block, roff, index);
    for(;;);
  }

  return delta;
}

long section_global()
{
  unsigned long off0, off1;
  unsigned long len;
  unsigned long count;
  long delta = 0;

  len = mgetsize(&off0, &off1);
  if (len) {
    /* delta += */ msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--) {
      mputuleb128(mgetuleb128());
      delta += msynch();
      delta += init_expr();
    }
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msynch();
  }

  return delta;
}

long elem_segment()
{
  unsigned long count;
  long delta = 0;

  mputuleb128(mgetuleb128());
  delta += msynch();
  delta += init_expr();
  mputuleb128(count = mgetuleb128());
  delta += msynch();
  while (count--) {
    mputuleb128(mgetuleb128());
    delta += msynch();
  }

  return delta;
}

long section_element()
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0;
  len = mgetsize(&off0, &off1);
  if (len) {
    unsigned long count;
    /* delta += */ msynch();
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--)
      delta += elem_segment();
    delta += msetsize(off0, off1, delta);
  } else {
    delta += msetsize(off0, off1, delta);
    delta += msynch();
  }

  return delta;
}

long section_name(long len)
{
  unsigned long off0, off1;
  unsigned long count;
  long delta = 0;
  long lcount = 0;

  if (len) {
    mputuleb128(count = mgetuleb128());
    delta += msynch();
    while (count--) {
      mputstring(mgetstring());
      mputuleb128(lcount = mgetuleb128());
      while (lcount--)
        mputstring(mgetstring());
      delta += msynch();
    }
  } else {
    delta += msynch();
  }

  return delta;
}

long section_named(const char *name)
{
  unsigned long off0, off1;
  unsigned long len;
  long delta = 0;

  msynch();
  len = mgetsize(&off0, &off1);
  msynch();
  char *str = mgetstring();

  if (strcmp(str, name) == 0) {
    fwrite(gbuf+roff, 1, len, stdout);
  }

  return delta;
}

long section(const char *name)
{
  long id = mgetuleb128();
  long delta = 0;

  switch (id) {
  case  1: delta += section_type(); break;
  case  2: delta += section_import(); break;
  case  3: delta += section_function(); break;
  case  4: delta += section_table(); break;
  case  5: delta += section_memory(); break;
  case  6: delta += section_global(); break;
  case  7: delta += section_export(); break;
  case  8: delta += section_start(); break;
  case  9: delta += section_element(); break;
  case 10: delta += section_code(); break;
  case 11: delta += section_data(); break;
  case  0: delta += section_named(name); break;
  }

  return delta;
}
int main(int argc, char **argv)
{
  size_t size = 4096;
  gbuf = xmalloc(size);
  size_t off = 0;
  size_t res = 0;
  FILE *f = fopen(argv[1], "r");
  const char *secname = argv[2];

  while (res = fread(gbuf+off, 1, size-off, f)) {
    off += res;
    size *= 2;
    gbuf = xrealloc(gbuf, size);
  }

  while (roff < off) {
    section(secname);
  }

  return 0;
}
