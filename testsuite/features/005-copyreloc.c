#include <stdio.h>

extern FILE *stderr;

int main(void)
{
  fprintf (stderr, "hi\n");
  stderr = NULL;
  fprintf (stderr, "segfault!\n");
  return 0;
}
