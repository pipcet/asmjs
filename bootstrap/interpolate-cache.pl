$VAR1 = {
          '
int main(void) {
    printf("%d", POLLIN);

    return 0;
}
' => '1',
          '
int main(void) {
    printf("%s", set(tvptr,struct timeval,tv_sec,"s|0"));

    return 0;
}
' => 'this.HEAP32[tvptr+0>>2] = s|0; this.HEAP32[tvptr+4>>2] = 0;',
          '
int main(void) {
    printf("%d", SEEK_SET);

    return 0;
}
' => '0',
          '
int main(void) {
    printf("%d", FIONREAD);

    return 0;
}
' => '21531',
          '
int main(void) {
    printf("%d", S_IFREG + 0666);

    return 0;
}
' => '33206',
          '
int main(void) {
    printf("%d", offsetof(zeropage_t, top_of_memory));

    return 0;
}
' => '0',
          '
int main(void) {
    printf("%d", S_IFDIR + 0777);

    return 0;
}
' => '16895',
          '
int main(void) {
    printf("%d", EINVAL);

    return 0;
}
' => '22',
          '
int main(void) {
    printf("%d", offsetof(struct stat,st_mode));

    return 0;
}
' => '24',
          '
int main(void) {
    printf("%d", offsetof(struct stat,st_size));

    return 0;
}
' => '48',
          '
int main(void) {
    printf("%d", SEEK_CUR);

    return 0;
}
' => '1',
          '
int main(void) {
    printf("%d", offsetof(struct stat,st_blksize));

    return 0;
}
' => '56',
          '
int main(void) {
    printf("%d", SEEK_END);

    return 0;
}
' => '2',
          '
int main(void) {
    printf("%d", EBADF);

    return 0;
}
' => '9',
          '
int main(void) {
    printf("%d", offsetof(struct dirent,d_name));

    return 0;
}
' => '19',
          '
int main(void) {
    printf("%s", set(direntp,struct dirent,d_reclen,9));

    return 0;
}
' => 'this.HEAP16[direntp+16>>1] = 9;',
          '
int main(void) {
    printf("%d", AT_EMPTY_PATH);

    return 0;
}
' => '4096',
          '
int main(void) {
    printf("%d", AT_FDROOTD);

    return 0;
}
' => '-101',
          '
int main(void) {
    printf("%d", offsetof(struct stat,st_blocks));

    return 0;
}
' => '64',
          '
int main(void) {
    printf("%s", set(tvptr,struct timeval,tv_usec,"us|0"));

    return 0;
}
' => 'this.HEAP32[tvptr+8>>2] = us|0; this.HEAP32[tvptr+12>>2] = 0;',
          '
int main(void) {
    printf("%d", sizeof(struct stat));

    return 0;
}
' => '176',
          '
int main(void) {
    printf("%s", clear(direntp,struct dirent,d_off));

    return 0;
}
' => 'this.HEAP32[direntp+8>>2] = 0; this.HEAP32[direntp+12>>2] = 0;',
          '
int main(void) {
    printf("%d", offsetof(zeropage_t, top_of_sbrk));

    return 0;
}
' => '8',
          '
int main(void) {
    printf("%d", offsetof(threadpage_t, pc));

    return 0;
}
' => '48',
          '
int main(void) {
    printf("%d", offsetof(struct stat,st_nlink));

    return 0;
}
' => '16',
          '
int main(void) {
    printf("%d", offsetof(threadpage_t, stop_reason));

    return 0;
}
' => '40',
          '
int main(void) {
    printf("%d", offsetof(threadpage_t, sp));

    return 0;
}
' => '56',
          '
int main(void) {
    printf("%s", clear(direntp,struct dirent,d_ino));

    return 0;
}
' => 'this.HEAP32[direntp+0>>2] = 0; this.HEAP32[direntp+4>>2] = 0;',
          '
int main(void) {
    printf("%d", offsetof(threadpage_t, initsp));

    return 0;
}
' => '64'
        };
