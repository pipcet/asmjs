#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
  int fd;
  fd = open(argv[argc-1], O_RDONLY);
  if (dup2(fd, 3) < 0)
    exit(1);

  if (fd < 0)
    exit(1);

  unlink(argv[argc-1]);

  argv[argc-1] = NULL;

  if (execve(argv[1], argv+1, envp) < 0)
    exit(1);

  /* not reached */

  exit(0);
}
