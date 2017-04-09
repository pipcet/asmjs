#include <stdio.h>
#include <stdlib.h>

asm(".include \"wasm32-import-macros.s\"");

asm(".import3_pic thinthin,init_trampoline,__thinthin_init_trampoline");

extern long __thinthin_init_trampoline(void *m_tramp)
  __attribute__((stackcall));

struct gcc_trampoline {
  unsigned magic;
  unsigned magic1;
  unsigned fnaddr;
  unsigned fnaddr1;
  unsigned static_chain;
  unsigned static_chain1;
  unsigned trampoline_index;
  unsigned trampoline_index1;
};

void init_trampoline (struct gcc_trampoline *m_tramp)
{
  fprintf(stderr,"init_trampoline\n");
  fprintf(stderr,"init_trampoline %p\n", m_tramp);

  fprintf(stderr,"init_trampoline %p %p\n", m_tramp->magic, m_tramp->magic);
  m_tramp->magic = "FiiiiiiiE";
  fprintf(stderr,"init_trampoline %s %p\n", m_tramp->magic, m_tramp->magic);

  if (__thinthin_init_trampoline (m_tramp) == 0) {
    fprintf(stderr,"got trampoline at %d\n", m_tramp->trampoline_index);
    ((void (*)(void))(m_tramp->trampoline_index))();
    fprintf(stderr,"called trampoline at %d\n", m_tramp->trampoline_index);
  }
}

#ifndef NO_TRAMPOLINES
int f0(int (*fn)(int *), int *p)
{
  printf("in f0 %d\n", *p);
  return (*fn) (p);
}

int f1(void)
{
  int i = 0;
  printf("in f1 %d\n", i);

  int f2(int *p)
  {
    printf("in f2 %d\n", i);
    i = 1;
    printf("in f2 %d\n", i);
    return *p + 1;
  }

  printf("in f1 %d\n", i);
  return f0(f2, &i);
}
#endif

int main()
{
#ifndef NO_TRAMPOLINES
  if (f1() != 2)
    abort ();
  if (f1() != 2)
    abort ();
  if (f1() != 2)
    abort ();
  if (f1() != 2)
    abort ();
#endif
  return 0;
}
