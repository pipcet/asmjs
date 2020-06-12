#include <stdio.h>

extern int a(void);
extern int b;

int c(void);
int d;

void *ap = a;
void *bp = &b;
void *cp = c;
void *dp = &d;

int main(void)
{
  printf("%p %p\n", a, &b);
}
