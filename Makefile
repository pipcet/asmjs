all: bin/hexify lib/asmjs.o build/gcc-final.make build/perl.make

MKDIR ?= mkdir
PWD ?= $(shell pwd)

# asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc_eh.a: asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc.a
#	cp $< $@

build/.dir:
	test -d build || $(MKDIR) build
	touch $@

build/binutils-gdb.dir: build/.dir
	test -d build/binutils-gdb || $(MKDIR) build/binutils-gdb
	touch $@

build/gcc-preliminary.dir: build/.dir
	test -d build/gcc-preliminary || $(MKDIR) build/gcc-preliminary
	touch $@

build/glibc.dir: build/.dir
	test -d build/glibc || $(MKDIR) build/glibc
	touch $@

build/gcc-final.dir: build/.dir
	test -d build/gcc-final || $(MKDIR) build/gcc-final
	touch $@

build/perl.dir: build/.dir
	test -d build/perl || $(MKDIR) build/perl && (cd src/perl; tar c .)|(cd build/perl; tar x)
	touch $@

build/binutils-gdb.configure: src/binutils-gdb.dir build/binutils-gdb.dir
	(cd src/binutils-gdb/gas; aclocal-1.11; automake-1.11)
	(cd build/binutils-gdb; ../../src/binutils-gdb/configure --target=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs)
	touch $@

build/binutils-gdb.make: build/binutils-gdb.dir build/binutils-gdb.configure
	$(MAKE) -C build/binutils-gdb
	$(MAKE) -C build/binutils-gdb install
	touch $@

build/gcc-preliminary.configure: src/gcc-preliminary.dir build/gcc-preliminary.dir | build/binutils-gdb.make
	(cd build/gcc-preliminary; ../../src/gcc-preliminary/configure --target=asmjs-virtual-asmjs --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/asmjs-virtual-asmjs)
	touch $@

# test -L asmjs-virtual-asmjs/asmjs-virtual-asmjs || ln -sf . asmjs-virtual-asmjs/asmjs-virtual-asmjs

build/gcc-preliminary.make: build/gcc-preliminary.dir build/gcc-preliminary.configure
	$(MAKE) -C build/gcc-preliminary
	$(MAKE) -C build/gcc-preliminary install
	cp asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc.a asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc_eh.a
	touch $@

build/glibc.configure: src/glibc.dir build/glibc.dir | build/gcc-preliminary.make
	(cd build/glibc; CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../src/glibc/configure --host=asmjs-virtual-asmjs --target=asmjs-virtual-asmjs --enable-hacker-mode --enable-static --enable-static-nss --disable-shared --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs)
	touch $@

build/glibc.make: build/glibc.dir build/glibc.configure
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/glibc
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/glibc install
	touch $@

build/gcc-final.configure: src/gcc-final.dir build/gcc-final.dir | build/glibc.make
	(cd build/gcc-final; ../../src/gcc-final/configure --target=asmjs-virtual-asmjs --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --disable-libssp --prefix=$(PWD)/asmjs-virtual-asmjs)
	touch $@

build/gcc-final.make: build/gcc-final.dir build/gcc-final.configure
	test -d build/gcc-final/gcc || $(MKDIR) build/gcc-final/gcc
	cp build/gcc-preliminary/gcc/libgcc.a build/gcc-final/gcc/libgcc_eh.a
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/gcc-final
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/gcc-final install
	touch $@

build/perl.configure: build/perl.dir | build/gcc-final.make
	test -f build/perl/config.sh && mv build/perl/config.sh build/perl/config.sh.old
	touch build/perl/config.sh
	(cd build/perl; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH sh ./Configure -der -Uusemymalloc -Dcc=asmjs-virtual-asmjs-gcc -Dincpth='$(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/include $(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/include-fixed $(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/../../../../asmjs-virtual-asmjs/include' -Dlibpth='$(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/include-fixed $(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/../../../../asmjs-virtual-asmjs/lib' -Dloclibpth=' ' -Dglibpth=' ' -Dplibpth=' ' -Dldflags=' ')
	touch $@

build/perl.make: build/perl.dir build/perl.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/perl
	touch $@

src/.dir:
	test -d src || $(MKDIR) src
	touch $@

src/binutils-gdb.dir: src/.dir
	test -d src/binutils-gdb || mkdir src/binutils-gdb
	(cd subrepos/binutils-gdb; tar c --exclude .git .) | (cd src/binutils-gdb; tar x)
	touch $@

src/gcc-preliminary.dir: src/.dir
	test -L src/gcc-preliminary || ln -sf ../subrepos/gcc src/gcc-preliminary
	touch $@

src/gcc-final.dir: src/.dir
	test -L src/gcc-final || ln -sf ../subrepos/gcc src/gcc-final
	touch $@

src/glibc.dir: src/.dir
	test -L src/glibc || ln -sf ../subrepos/glibc src/glibc
	touch $@

src/perl.dir: src/.dir
	test -L src/perl || ln -sf ../subrepos/perl src/perl
	touch $@

bin/hexify: hexify/hexify.c
	$(CC) $< -o $@

lib/asmjs.o: lib/asmjs.S build/gcc-final.make
	asmjs-virtual-asmjs/bin/asmjs-virtual-asmjs-gcc -c $< -o $@

clean:
	rm -rf build src asmjs-virtual-asmjs

fetch: projects/gcc.fetch projects/glibc.fetch projects/binutils-gdb.fetch

projects/gcc.fetch:
	rm -f projects/gcc
	(cd projects; git clone https://github.com/pipcet/gcc -b asmjs)
	touch $@

projects/glibc.fetch:
	rm -f projects/glibc
	(cd projects; git clone https://github.com/pipcet/glibc -b asmjs)
	touch $@

projects/binutils-gdb.fetch:
	rm -f projects/binutils-gdb
	(cd projects; git clone https://github.com/pipcet/binutils-gdb -b asmjs)
	touch $@

.PHONY: FORCE clean fetch
