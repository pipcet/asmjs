struct s {
  int a;
  int b;
};

void g(struct s &x)
{
  x.a = 3;
  x.b = 4;
}

int main(void)
{
  struct s x;

  g(x);
}
