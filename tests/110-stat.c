#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

#define P(str) printf(#str " %d %d", offsetof(struct stat, str), sizeof((struct stat *)0->str));

int main(void)
{
  P(st_dev);
}
