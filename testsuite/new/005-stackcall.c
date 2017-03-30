int f(int, long long, int) __attribute__((stackcall));

int f(int a, long long b, int c)
{
  return a / 'a' + b / 'b' + c / 'c';
}
