// Testcase for proper handling of
// c++ type, constructors and destructors.

#include <stdio.h>

void
f()
{
  printf ("Throwing 1...\n");
  throw 3;
}


int
main ()
{
  printf ("hi!\n");
  try
    {
      f ();
    }
  catch (...)
    {
      printf ("Caught.\n");
    }
}
