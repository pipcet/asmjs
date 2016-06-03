template<typename F, F f>
void
deduceme(F f)
{
}

int ff() { return 7; }

int main()
{
  deduceme(ff);
}
