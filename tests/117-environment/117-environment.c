#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
  while (*envp)
    fprintf(stderr, "%s\n", *envp++);

  return 0;
}
