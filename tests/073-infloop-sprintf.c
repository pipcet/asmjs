#include <stdio.h>

int main(void)
{
  char buf[1024] = "hi there\n";
  for(;;)
    sprintf(buf, "%s", buf);
}
