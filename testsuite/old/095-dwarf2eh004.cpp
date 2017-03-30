// Testcase for proper handling of
// c++ type, constructors and destructors.

#include <stdio.h>

int c, d;

struct A
{
  int i;
  A () { i = ++c; fprintf (stdout, "A() %d\n", i); }
  A (const A&) { i = ++c; fprintf (stdout, "A(const A&) %d\n", i); }
  ~A() { fprintf (stdout, "~A() %d\n", i); ++d; }
};

void
f()
{
  fprintf (stdout, "Throwing 1...\n");
  throw A();
}


int
main ()
{
  fprintf(stdout, "hi!\n");
  try
    {
      f();
    }
  catch (A)
    {
      fprintf (stdout, "Caught.\n");
    }
  fprintf (stdout, "c == %d, d == %d\n", c, d);
  return c != d;
}
