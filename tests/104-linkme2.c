extern int f(void);

int g(void)
{
    return f();
}

int main(void)
{
    while(1)
	f();
}
