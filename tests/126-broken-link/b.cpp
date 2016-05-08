template <typename T>
int
s(T x)
{
  return sizeof(T) + x;
}

int g()
{
  return s<int>(7);
}

int f();

int main()
{
  f();
  g();
}
