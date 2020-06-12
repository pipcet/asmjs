void loop(void)
{
  volatile int i = 1;
  while (i++);
}

int main(void)
{
  loop();
  return 0;
}
