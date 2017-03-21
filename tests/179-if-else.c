extern void f(void);
extern void g(void);

int main(void)
{
  volatile int cond;

  if (cond) {
    f();
  } else {
    g();
  }
}
