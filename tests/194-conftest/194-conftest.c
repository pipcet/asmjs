#include <stdio.h>

extern FILE _IO_2_1_stdout_;

int main(void)
{
  while (1)
    {
      //stdout = (void *)(0x7560 + 36864);
      puts("boo");
      printf ("hello world\n");
      char str[128] = {0,};
      sprintf (str, "stdout is at %p\n", stdout);
      puts (str);
      for (int i = 0; i < 1024; i += 4)
	{
	  sprintf (str, "stdout[%d] = %08x\n", i, *(((int *)stdout)+i/4));
	  puts (str);
	}
      //fprintf (stdout, "stdout should be at %p\n", stdout);
      printf ("%p\n", stdout);
      printf ("bye world\n");
      read (0, 0, 0);
    }
}
