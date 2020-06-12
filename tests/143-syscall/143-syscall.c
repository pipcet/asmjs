asm(".include \"143-import-macros.s\"");
asm(".import3 thinthin,write,__thinthin_write");

extern __attribute__((stackcall)) int __thinthin_write(int, const char *, int);

int main(void)
{
  return __thinthin_write(1, "hi there\n", __builtin_strlen("hi there\n"));
}
