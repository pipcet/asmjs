#include <stdio.h>

extern int thisisanundefinedfunctionsname(void);

int main(void)
{
  return thisisanundefinedfunctionsname();
}
