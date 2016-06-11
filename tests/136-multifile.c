#include <stdio.h>

struct multifile_header {
  unsigned long long data_start;
  unsigned long long terminator;
  unsigned long long preinit_array_start;
  unsigned long long preinit_array_end;
  unsigned long long init_array_start;
  unsigned long long init_array_end;
  unsigned long long fini_array_start;
  unsigned long long fini_array_end;
};

void print_header(struct multifile_header *mfh)
{
  printf("header at %p:\n", mfh);
  printf(" data start at %016llx\n", mfh->data_start);
  printf(" terminator at %016llx\n", mfh->terminator);
  printf(" start of P at %016llx\n", mfh->preinit_array_start);
  printf(" end   of P at %016llx\n", mfh->preinit_array_end);
  printf(" start of I at %016llx\n", mfh->init_array_start);
  printf(" end   of I at %016llx\n", mfh->init_array_end);
  void **p = (void **)(long)mfh->init_array_start;
  while (p < (void **)(long)mfh->init_array_end) {
    printf("  initialization at %p\n", *p);
    p++;
  }
  printf(" start of F at %016llx\n", mfh->fini_array_start);
  printf(" end   of F at %016llx\n", mfh->fini_array_end);
}

void f(void)
{
  struct multifile_header *mfh = (struct multifile_header *)16384;

  while (mfh->data_start) {
    print_header(mfh);
    mfh = (struct multifile_header *)(long)(mfh->terminator);
  }
}

__attribute__((section(".init_array"))) void (*f_init)(void) = f;
