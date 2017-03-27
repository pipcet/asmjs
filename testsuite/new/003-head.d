#c: int main(void) { while (1) printf("XXX\n"); }
#gcc:
#warning: .*
#run: 100
#pass