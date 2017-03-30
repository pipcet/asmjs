// Testcase for proper handling of
// c++ type, constructors and destructors.

#include <stdio.h>

int c, d;

struct A
{
  int i;
  A () { i = ++c; printf("."); }
  ~A () { ++d; printf(","); }
};

void
f()
{
  printf ("Throwing 1...\n");
  throw A();
}

int
main ()
{
  A x;
  printf("hi!\n");
  try
    {
      f();
    }
  catch (A x)
    {
      printf ("Caught %d.\n", x.i);
      {
        A z;
      }
      printf ("Destroyed.\n");
    }
  printf ("c == %d, d == %d\n", c, d);
  return c != d;
}
