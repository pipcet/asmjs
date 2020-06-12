#include <stdio.h> 

int main(int argc, char **argv)
{
  fprintf(fdopen(1, "w"), "%d %s %s %s %s\n", argc, argv[0], argv[1], argv[2], argv[3]);

  return 0;
}
