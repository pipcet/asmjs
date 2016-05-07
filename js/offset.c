#include <sys/stat.h>
#include <stdio.h>

#define offsetof(type,field) ((unsigned long)&(((struct type *)0)->field))
#define O(type,field) do {                                      \
    fprintf(stdout, "OffsetOf.%s.%s = %d;\n", #type, #field,    \
            offsetof(type, field));                             \
  } while(0)

int main(void) {
  O(stat, st_dev);
  O(stat, st_ino);
  O(stat, st_nlink);
  O(stat, st_mode);
  O(stat, st_uid);
  O(stat, st_gid);
  O(stat, st_rdev);
  O(stat, st_size);
  O(stat, st_blksize);
  O(stat, st_blocks);
  O(stat, st_atime);
  O(stat, st_mtime);
  O(stat, st_ctime);

  return 0;
}
