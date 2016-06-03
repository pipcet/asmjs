#include <stdio.h>

extern void (*ptr_init_0)();

int main(void)
{
  printf("in main\n");
  printf("ptr %p %p\n", ptr_init_0, &ptr_init_0);
  void (**pptr)();

  pptr = *(void (***)())(4 * 4096);

  for (int i = 0; i < 32; i++)
    {
      if (*pptr)
        (*pptr)();
      printf("pptr %p\n", *pptr++);
    }
}

int h(int, long long)
{
  return 0;
}

int k(int, long long)
{
  return 1;
}

int f(int, int)
{
  return 2;
}

void (*ptr_init_0)() __attribute__((section(".init.jsexport"))) = NULL;
