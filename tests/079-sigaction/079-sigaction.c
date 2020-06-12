#include <signal.h>

extern void f(struct sigaction *);

int main(void)
{
  struct sigaction sa;

  f(&sa);
}
