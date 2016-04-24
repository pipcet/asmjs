extern void v_i(int x);
extern int i_i(int x);
extern double d_i(int x);

extern void v_d(double x);
extern int i_d(double x);
extern double d_d(double x);

int main(void)
{
  v_i(3);
  i_i(4);
  d_i(5);

  v_d(6.0);
  i_d(7.0);
  d_d(8.0);

  return 0;
}
