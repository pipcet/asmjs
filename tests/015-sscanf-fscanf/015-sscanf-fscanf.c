#include <stdio.h>

extern int dr_sscanf(const char *, const char *, ...);

int main(void)
{
    int x = 7;
    char buf[80];

    //dr_sscanf("3", "%d", &x);
    sscanf("3", "%d", &x);
    fscanf(stdin, "%d", &x);
    fread(buf, 79, 1, stdin);
    scanf("%d", &x);

    printf("%d\n", x);

    printf("%p\n", sscanf);

    return 0;
}
