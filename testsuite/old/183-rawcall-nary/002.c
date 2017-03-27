/* This should produce the following output:

0 0
1 1
2 3
3 7
4 15
5 31
6 63
7 127
8 255
9 511
10 1023
11 2047
12 4095

*/


extern int f0(void) __attribute__((rawcall));
extern int f1(int) __attribute__((rawcall));
extern int f2(int,int) __attribute__((rawcall));
extern int f3(int,int,int) __attribute__((rawcall));
extern int f4(int,int,int,int) __attribute__((rawcall));
extern int f5(int,int,int,int,int) __attribute__((rawcall));
extern int f6(int,int,int,int,int,int) __attribute__((rawcall));
extern int f7(int,int,int,int,int,int,int) __attribute__((rawcall));
extern int f8(int,int,int,int,int,int,int,int) __attribute__((rawcall));
extern int f9(int,int,int,int,int,int,int,int,int) __attribute__((rawcall));
extern int f10(int,int,int,int,int,int,int,int,int,int) __attribute__((rawcall));
extern int f11(int,int,int,int,int,int,int,int,int,int,int) __attribute__((rawcall));
extern int f12(int,int,int,int,int,int,int,int,int,int,int,int) __attribute__((rawcall));

#include <stdio.h>

int main(void)
{
  printf("%d %d\n", 0, f0());
  printf("%d %d\n", 1, f1(1));
  printf("%d %d\n", 2, f2(1,2));
  printf("%d %d\n", 3, f3(1,2,4));
  printf("%d %d\n", 4, f4(1,2,4,8));
  printf("%d %d\n", 5, f5(1,2,4,8,16));
  printf("%d %d\n", 6, f6(1,2,4,8,16,32));
  printf("%d %d\n", 7, f7(1,2,4,8,16,32,64));
  printf("%d %d\n", 8, f8(1,2,4,8,16,32,64,128));
  printf("%d %d\n", 9, f9(1,2,4,8,16,32,64,128,256));
  printf("%d %d\n", 10, f10(1,2,4,8,16,32,64,128,256,512));
  printf("%d %d\n", 11, f11(1,2,4,8,16,32,64,128,256,512,1024));
  printf("%d %d\n", 12, f12(1,2,4,8,16,32,64,128,256,512,1024,2048));

  return 0;
}
