#include <stdio.h>

int main(void)
{
  double d = 1.2;

  printf("%f\n", 1.2);
  printf("%f\n", 1.2);
  printf("%f %f\n", 1.2, 3.4);
  printf("%f %d %f\n", 1.2, 3, 4.5);
  printf("%f %d %d %f\n", 1.2, 3, 4, 5.6);
  printf("%f %d %f %d %f %d %f\n", 1.2, 3, 4.5, 6, 7.8, 9, 10.11);

  return 0;
}
