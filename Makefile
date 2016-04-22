all: hexify/hexify asmjs.o

hexify/hexify: hexify/hexify.c
	$(CC) $< -o $@

asmjs.o: asmjs.S
	asmjs-virtual-asmjs-gcc -c $< -o $@
