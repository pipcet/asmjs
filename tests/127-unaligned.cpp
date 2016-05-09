struct A {
  char c;
  int i;
} __attribute__((packed));

int main()
{
  volatile A a;
  while(1)
    a.i++;
}
