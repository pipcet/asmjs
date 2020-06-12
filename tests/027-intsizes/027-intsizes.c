// from the perl configure script
#include <stdio.h>
#define I_STDLIB
#ifdef I_STDLIB
#include <stdlib.h>
#endif
int main()
{
        printf("intsize=%d;\n", (int)sizeof(int));
        printf("longsize=%d;\n", (int)sizeof(long));
        printf("shortsize=%d;\n", (int)sizeof(short));
        exit(0);
}
