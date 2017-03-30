#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

#define offsetof(haystack, needle) ((unsigned)(&((haystack *)0)->needle))

#define P(str) printf(#str " %d %d %016llx\n", offsetof(struct stat, str), sizeof(((struct stat *)0)->str), (long long)buf.str);

int main(int argc, char **argv)
{
  struct stat buf;
  stat(argv[1], &buf);
  P(st_dev);
  P(st_ino);
  P(st_nlink);
  P(st_mode);
  P(st_uid);
  P(st_gid);
  P(st_rdev);
  P(st_size);
  P(st_blksize);
  P(st_blocks);

  return 0;
}
