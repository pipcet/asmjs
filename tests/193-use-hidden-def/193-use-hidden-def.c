extern int x __attribute__ ((visibility ("hidden")));

void _start(void)
{
  x++;
}
