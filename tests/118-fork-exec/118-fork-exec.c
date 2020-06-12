#include <unistd.h>
#include <stdio.h>

int main(void)
{
  int res;

  res = fork();
  if (res > 0)
    {
      char *argv[] = {
        "/bin/echo",
        "hello",
        "world",
        NULL,
      };
      char *envp[] = {
        NULL,
      };
      fprintf(stderr, "child!\n");
      execve("/bin/echo", argv, envp);
    }
  else
    {
      fprintf(stderr, "parent: %d\n", res);
    }
  return 0;
}
