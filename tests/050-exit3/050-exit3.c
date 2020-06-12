extern void _Noreturn exit(int x);
extern void exit2(int x);
extern int exit3(int x);

int main(void)
{
  volatile int i = 3;

  switch (i) {
  case 1:
    exit(11);
  case 2:
    exit2(12);
  case 3:
    exit3(13);
  }
  return 0;
}
