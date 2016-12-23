#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
  int fd;
  fd = open(argv[1], O_RDONLY);

  if (fd < 0)
    exit(1);

  unlink(argv[1]);

  if (execveat(fd, "", argv+1, envp, AT_EMPTY_PATH) < 0)
    exit(1);

  /* not reached */

  exit(0);
}
