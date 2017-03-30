extern int __wrap_write(int fd, const char *data, int count);

int main(void)
{
  while(1)
    __wrap_write(1, "test\n", 5);
}
