#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>

extern int __gdb_open(const char *filename, int flags, int mode);
extern int __gdb_close(int fd);
extern int __gdb_read(int fd, void *buf, unsigned int count);
extern int __gdb_write(int fd, void *buf, unsigned int count);
extern int __gdb_lseek(int fd, long offset, int whence);
extern int __gdb_rename(const char *oldpath, const char *newpath);
extern int __gdb_unlink(const char *path);
extern int __gdb_stat(const char *path, struct stat *buf);
extern int __gdb_fstat(int fd, struct stat *buf);
extern int __gdb_gettimeofday(struct timeval *tv, void *tz);
extern int __gdb_isatty(int fd);
extern int __gdb_system(const char *command);
extern int __gdb_chdir(const char *command);

extern int breakpoint3(void);

int main(void)
{
  int fd;
  breakpoint3();
  fd = __gdb_open("a.tst", O_CREAT|O_RDWR, 0777);
  fprintf(stderr, "fd %d\n", fd);
  __gdb_write(fd, "test", 4);
  __gdb_close(fd);

  return 0;
}
