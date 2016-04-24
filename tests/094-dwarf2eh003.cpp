// Testcase for proper handling of
// c++ type, constructors and destructors.

#include <stdio.h>

int c, d;

struct A
{
  int i;
  A () { i = ++c; fprintf (stderr, "A() %d\n", i); }
  A (const A&) { i = ++c; fprintf (stderr, "A(const A&) %d\n", i); }
  ~A() { fprintf (stderr, "~A() %d\n", i); ++d; }
};

void
f()
{
  fprintf (stderr, "Throwing 1...\n");
  throw A();
}


int
main ()
{
  A x;
  fprintf(stderr, "hi!\n");
  try
    {
      f();
    }
  catch (A)
    {
      fprintf (stderr, "Caught.\n");
    }
  fprintf (stderr, "c == %d, d == %d\n", c, d);
  return c != d;
}
