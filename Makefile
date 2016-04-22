all: bin/hexify lib/asmjs.o

MKDIR ?= mkdir
PWD ?= $(shell pwd)

build:
	$(MKDIR) $@

build/binutils-gdb: build
	$(MKDIR) $@

build/binutils-gdb.configure: src/binutils-gdb build/binutils-gdb
	(cd build/binutils-gdb; ../../src/binutils-gdb/configure --target=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs) && touch $@

build/binutils-gdb.make: build/binutils-gdb build/binutils-gdb.configure
	(cd src/binutils-gdb/gas; aclocal-1.11; AUTOCONF=autoconf2.64 automake-1.11) && $(MAKE) -C $< && $(MAKE) -C $< install && touch $@

src:
	$(MKDIR) $@

src/binutils-gdb: projects/binutils-gdb src
	cp -a $</ $@

bin/hexify: hexify/hexify.c
	$(CC) $< -o $@

lib/asmjs.o: lib/asmjs.S
	asmjs-virtual-asmjs-gcc -c $< -o $@

clean:
	$(RM) -rf build src asmjs-virtual-asmjs

.PHONY: FORCE clean
