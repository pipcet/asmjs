#include <stdio.h>

int main(void)
{
  printf("%f %d %d %d  %d %f %d %d  %d %d %f %d  %d %d %d %f\n",
         0.0, 1, 2, 3,
         4, 5.0, 6, 7,
         8, 9,10.0,11,
         12,13,14,15.0);

  printf("%d %f %d %d %d  %d %f %d %d  %d %d %f %d  %d %d %d %f\n",
         -1, 0.0, 1, 2, 3,
         4, 5.0, 6, 7,
         8, 9,10.0,11,
         12,13,14,15.0);

  fprintf(stdout,
          "%f %d %d %d  %d %f %d %d  %d %d %f %d  %d %d %d %f\n",
          0.0, 1, 2, 3,
          4, 5.0, 6, 7,
          8, 9,10.0,11,
          12,13,14,15.0);
  
  printf("%f %d %d  %d %f %d  %d %d %f  %d %d %d\n",
         0.0, 1, 2,
         4, 5.0, 6,
         8, 9,10.0,
         12,13,14);

  fprintf(stdout,
          "%f %d %d %d  %d %f %d %d  %d %d %f %d  %d %d %d %f\n",
          0.0, 1, 2, 3,
          4, 5.0, 6, 7,
          8, 9,10.0,11,
          12,13,14,15.0);
  
  return 0;
}
