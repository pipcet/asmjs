asm(".include \"wasm32-import-macros.s\"");
asm(".import3_pic thinthin,write,__thinthin_write");

extern __attribute__((stackcall)) int __thinthin_write(int, const char *, int);

void _start(void)
{
  return __thinthin_write(1, "hi there\n", __builtin_strlen("hi there\n"));
}

int main(void) {}
