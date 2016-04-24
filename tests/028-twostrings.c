#include <stdio.h>

const char *string = "this is not the null string\n";
const char *string2 = "this is not the null string either\n";

int main(void)
{
  fprintf(stderr, "%s", string);
}
