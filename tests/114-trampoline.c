extern int f(int (*)(void));

int main(void)
{
  volatile int x = 7;
  volatile int y = 13;
  int sum(void) {
    return x + y;
  }

  f(sum);
}
