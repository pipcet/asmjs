template <typename T>
int
s(T x)
{
  return sizeof(T) + x;
}

int f()
{
  return s<int>(7);
}
