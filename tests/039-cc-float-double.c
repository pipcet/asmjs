extern void v_f(float);
extern void v_d(double);
extern void v_ff(float, float);
extern void v_fd(float, double);
extern void v_df(double, float);
extern void v_dd(double, double);

extern int i_f(float);
extern int i_d(double);
extern int i_ff(float, float);
extern int i_fd(float, double);
extern int i_df(double, float);
extern int i_dd(double, double);


int main(void)
{
  volatile float x = 1.3;
  volatile double y = 2.5;
  volatile float z = 3.5;
  volatile double a = 4.5;

  v_f(x);
  v_f(z);
  v_d(y);
  v_d(a);
  v_ff(x, z);
  v_fd(x, y);
  v_df(a, x);
  v_dd(y, a);

  i_f(x);
  i_f(z);
  i_d(y);
  i_d(a);
  i_ff(x, z);
  i_fd(x, y);
  i_df(a, x);
  i_dd(y, a);
}
