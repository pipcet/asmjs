all: bin/hexify lib/asmjs.o build/gcc-final.make

MKDIR ?= mkdir
PWD ?= $(shell pwd)

# asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc_eh.a: asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc.a
#	cp $< $@

build:
	test -d $@ || $(MKDIR) $@

build/binutils-gdb: build
	test -d $@ || $(MKDIR) $@

build/gcc-preliminary: build
	test -d $@ || $(MKDIR) $@

build/glibc: build
	test -d $@ || $(MKDIR) $@

build/gcc-final: build
	test -d $@ || $(MKDIR) $@

build/binutils-gdb.configure: src/binutils-gdb build/binutils-gdb
	(cd build/binutils-gdb; ../../src/binutils-gdb/configure --target=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs) && touch $@

build/binutils-gdb.make: build/binutils-gdb build/binutils-gdb.configure
	(cd src/binutils-gdb/gas; aclocal-1.11; AUTOCONF=autoconf2.64 automake-1.11) && $(MAKE) -C $< && $(MAKE) -C $< install && touch $@

build/gcc-preliminary.configure: src/gcc-preliminary build/gcc-preliminary build/binutils-gdb.make
	(cd build/gcc-preliminary; ../../src/gcc-preliminary/configure --target=asmjs-virtual-asmjs --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/asmjs-virtual-asmjs) && touch $@

build/gcc-preliminary.make: build/gcc-preliminary build/gcc-preliminary.configure
	$(MAKE) -C $< && $(MAKE) -C $< install && cp asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc.a asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc_eh.a && touch $@

build/glibc.configure: src/glibc build/glibc build/gcc-preliminary.make
	(cd build/glibc; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../src/glibc/configure --host=asmjs-virtual-asmjs --target=asmjs-virtual-asmjs --enable-hacker-mode --enable-static --disable-shared --prefix=$(PWD)/asmjs-virtual-asmjs) && touch $@

build/glibc.make: build/glibc build/glibc.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C $< && PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C $< install && touch $@

build/gcc-final.configure: src/gcc-final build/gcc-final build/glibc.make
	(cd build/gcc-final; ../../src/gcc-final/configure --target=asmjs-virtual-asmjs --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --prefix=$HOME/asmjs-virtual-asmjs --disable-libssp --prefix=$(PWD)/asmjs-virtual-asmjs) && touch $@

build/gcc-final.make: build/gcc-final build/gcc-final.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C $< && PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C $< install && touch $@

src:
	$(MKDIR) $@

src/binutils-gdb: projects/binutils-gdb src
	test -d $@ || mkdir $@
	(cd $<; tar c --exclude .git .) | (cd $@; tar x)

src/gcc-preliminary: projects/gcc src
	test -L $@ || ln -sf ../$< $@

src/gcc-final: projects/gcc src
	test -L $@ || ln -sf ../$< $@

src/glibc: projects/glibc src
	test -L $@ || ln -sf ../$< $@

bin/hexify: hexify/hexify.c
	$(CC) $< -o $@

lib/asmjs.o: lib/asmjs.S
	asmjs-virtual-asmjs-gcc -c $< -o $@

# clean:
# make clean by hand until I've fixed this.
# $(RM) -rf build src asmjs-virtual-asmjs

.PHONY: FORCE clean
