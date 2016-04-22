all: bin/hexify lib/asmjs.o

bin/hexify: hexify/hexify.c
	$(CC) $< -o $@

lib/asmjs.o: lib/asmjs.S
	asmjs-virtual-asmjs-gcc -c $< -o $@
