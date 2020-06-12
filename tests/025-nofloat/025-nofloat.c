#include <stdio.h>

int main(void)
{
  int ret = 0;

  while (1) {
    ret += fprintf(stdout, "hello world: %d %%f %s %c\n", ret,
                   /* 4.5, */
                   "string", (int)'x');
  }

}
