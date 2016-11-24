asm(".include \"wasm32-import-macros.s\"");
asm(".import3 thinthin,write,__thinthin_write");

extern __attribute__((stackcall)) int __thinthin_write(int, const char *, int);

char _start;

void main(void)
{
  __thinthin_write(1, "hi there\n", __builtin_strlen("hi there\n"));
}
