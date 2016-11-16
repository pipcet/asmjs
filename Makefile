all: build/spidermonkey.make cache/interpolate-cache.pl bin/hexify js/asmjs.js lib/asmjs.o build/gcc-final.make build/graphviz.make # tests/001-do-nothing.c.s.o.exe.js build/perl.make build/coreutils.make build/bash.make # build/emacs.make

MKDIR ?= mkdir
PWD ?= $(shell pwd)
OPT_NATIVE ?= "-O0 -g0"
OPT_ASMJS ?= "-O2"

# asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc_eh.a: asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc.a
#	cp $< $@

build/.dir:
	test -d build || $(MKDIR) build
	touch $@

build/common/.dir: build/.dir
	test -d build/common || $(MKDIR) build/common
	touch $@

build/debug/.dir: build/.dir
	test -d build/debug || $(MKDIR) build/debug
	touch $@

build/debug0/.dir: build/.dir
	test -d build/debug0 || $(MKDIR) build/debug0
	touch $@

build/asmjs/.dir: build/.dir
	test -d build/asmjs || $(MKDIR) build/asmjs
	touch $@

build/wasm/.dir: build/.dir
	test -d build/wasm || $(MKDIR) build/wasm
	touch $@

build/wasm64/.dir: build/.dir
	test -d build/wasm64 || $(MKDIR) build/wasm64
	touch $@

build/asmjs/binutils-gdb.dir: build/asmjs/.dir
	test -d build/asmjs/binutils-gdb || $(MKDIR) build/asmjs/binutils-gdb
	touch $@

build/wasm/binutils-gdb.dir: build/wasm/.dir
	test -d build/wasm/binutils-gdb || $(MKDIR) build/wasm/binutils-gdb
	touch $@

build/wasm64/binutils-gdb.dir: build/wasm64/.dir
	test -d build/wasm64/binutils-gdb || $(MKDIR) build/wasm64/binutils-gdb
	touch $@

build/asmjs/gcc-preliminary.dir: build/asmjs/.dir
	test -d build/asmjs/gcc-preliminary || $(MKDIR) build/asmjs/gcc-preliminary
	touch $@

build/wasm/gcc-preliminary.dir: build/wasm/.dir
	test -d build/wasm/gcc-preliminary || $(MKDIR) build/wasm/gcc-preliminary
	touch $@

build/wasm64/gcc-preliminary.dir: build/wasm64/.dir
	test -d build/wasm64/gcc-preliminary || $(MKDIR) build/wasm64/gcc-preliminary
	touch $@

build/asmjs/glibc.dir: build/asmjs/.dir
	test -d build/asmjs/glibc || $(MKDIR) build/asmjs/glibc
	touch $@

build/wasm/glibc.dir: build/wasm/.dir
	test -d build/wasm/glibc || $(MKDIR) build/wasm/glibc
	touch $@

build/wasm64/glibc.dir: build/wasm64/.dir
	test -d build/wasm64/glibc || $(MKDIR) build/wasm64/glibc
	touch $@

build/asmjs/gcc-final.dir: build/asmjs/.dir
	test -d build/asmjs/gcc-final || $(MKDIR) build/asmjs/gcc-final
	touch $@

build/wasm64/gcc-final.dir: build/wasm64/.dir
	test -d build/wasm64/gcc-final || $(MKDIR) build/wasm64/gcc-final
	touch $@

build/asmjs/ncurses.dir: build/asmjs/.dir
	test -d build/asmjs/ncurses || $(MKDIR) build/asmjs/ncurses
	touch $@

build/asmjs/emacs.dir: build/asmjs/.dir
	test -d build/asmjs/emacs || $(MKDIR) build/asmjs/emacs
	touch $@

build/common/spidermonkey.dir: build/common/.dir
	test -d build/common/spidermonkey || $(MKDIR) build/common/spidermonkey
	touch $@

build/debug/spidermonkey.dir: build/debug/.dir
	test -d build/debug/spidermonkey || $(MKDIR) build/debug/spidermonkey
	touch $@

build/debug0/spidermonkey.dir: build/debug0/.dir
	test -d build/debug0/spidermonkey || $(MKDIR) build/debug0/spidermonkey
	touch $@

build/asmjs/bash.dir: build/asmjs/.dir
	test -d build/asmjs/bash || $(MKDIR) build/asmjs/bash
	touch $@

build/asmjs/perl.dir: build/asmjs/.dir src/perl.dir
	test -d build/asmjs/perl || mkdir build/asmjs/perl
	(cd src/perl; tar c --exclude .git .) | (cd build/asmjs/perl; tar x)
	touch $@

build/asmjs/coreutils.dir: build/asmjs/.dir
	test -d build/asmjs/coreutils || $(MKDIR) build/asmjs/coreutils
	touch $@

build/asmjs/graphviz.dir: build/asmjs/.dir
	test -d build/asmjs/graphviz || $(MKDIR) build/asmjs/graphviz
	touch $@

build/asmjs/binutils-gdb.configure: src/binutils-gdb.dir build/asmjs/binutils-gdb.dir
	(cd src/binutils-gdb/gas; aclocal-1.11; automake-1.11)
	(cd build/asmjs/binutils-gdb; ../../../src/binutils-gdb/configure --target=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs CFLAGS=$(OPT_NATIVE))
	touch $@

build/wasm/binutils-gdb.configure: src/binutils-gdb.dir build/wasm/binutils-gdb.dir
	(cd src/binutils-gdb/gas; aclocal-1.11; automake-1.11)
	(cd build/wasm/binutils-gdb; ../../../src/binutils-gdb/configure --target=wasm-virtual-wasm --prefix=$(PWD)/wasm-virtual-wasm CFLAGS=$(OPT_NATIVE))
	touch $@

build/wasm64/binutils-gdb.configure: src/binutils-gdb.dir build/wasm64/binutils-gdb.dir
	(cd src/binutils-gdb/gas; aclocal-1.11; automake-1.11)
	(cd build/wasm64/binutils-gdb; ../../../src/binutils-gdb/configure --target=wasm64-virtual-wasm64 --prefix=$(PWD)/wasm64-virtual-wasm64 CFLAGS="-g -O0")
	touch $@

build/asmjs/binutils-gdb.make: build/asmjs/binutils-gdb.dir build/asmjs/binutils-gdb.configure
	$(MAKE) -C build/asmjs/binutils-gdb
	$(MAKE) -C build/asmjs/binutils-gdb install
	touch $@

build/wasm/binutils-gdb.make: build/wasm/binutils-gdb.dir build/wasm/binutils-gdb.configure
	$(MAKE) -C build/wasm/binutils-gdb
	$(MAKE) -C build/wasm/binutils-gdb install
	touch $@

build/wasm64/binutils-gdb.make: build/wasm64/binutils-gdb.dir build/wasm64/binutils-gdb.configure
	$(MAKE) -C build/wasm64/binutils-gdb
	$(MAKE) -C build/wasm64/binutils-gdb install
	touch $@

build/binutils-gdb.clean: FORCE
	rm -rf build/binutils-gdb src/binutils-gdb
	rm -f build/binutils-gdb.dir
	rm -f src/binutils-gdb.dir
	rm -f build/binutils-gdb.configure
	rm -f build/binutils-gdb.make

build/asmjs/gcc-preliminary.configure: src/gcc-preliminary.dir build/asmjs/gcc-preliminary.dir | build/asmjs/binutils-gdb.make
	(cd build/asmjs/gcc-preliminary; ../../../src/gcc-preliminary/configure --enable-optimize=$(OPT_NATIVE) --target=asmjs-virtual-asmjs --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/asmjs-virtual-asmjs)
	touch $@

build/wasm/gcc-preliminary.configure: src/gcc-preliminary.dir build/wasm/gcc-preliminary.dir | build/wasm/binutils-gdb.make
	(cd build/wasm/gcc-preliminary; ../../../src/gcc-preliminary/configure --enable-optimize=$(OPT_NATIVE) --target=wasm-virtual-wasm --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/wasm-virtual-wasm)
	touch $@

build/wasm64/gcc-preliminary.configure: src/gcc-preliminary.dir build/wasm64/gcc-preliminary.dir | build/wasm64/binutils-gdb.make
	(cd build/wasm64/gcc-preliminary; ../../../src/gcc-preliminary/configure --enable-optimize=$(OPT_NATIVE) --target=wasm64-virtual-wasm64 --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/wasm64-virtual-wasm64)
	touch $@

# test -L asmjs-virtual-asmjs/asmjs-virtual-asmjs || ln -sf . asmjs-virtual-asmjs/asmjs-virtual-asmjs

build/asmjs/gcc-preliminary.make: build/asmjs/gcc-preliminary.dir build/asmjs/gcc-preliminary.configure
	$(MAKE) -C build/asmjs/gcc-preliminary
	$(MAKE) -C build/asmjs/gcc-preliminary install
	cp asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc.a asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc_eh.a
	cp asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc.a asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc_s.a
	touch $@

build/wasm/gcc-preliminary.make: build/wasm/gcc-preliminary.dir build/wasm/gcc-preliminary.configure
	$(MAKE) -C build/wasm/gcc-preliminary
	$(MAKE) -C build/wasm/gcc-preliminary install
	cp wasm-virtual-wasm/lib/gcc/wasm-virtual-wasm/7.0.0/libgcc.a wasm-virtual-wasm/lib/gcc/wasm-virtual-wasm/7.0.0/libgcc_eh.a
	cp wasm-virtual-wasm/lib/gcc/wasm-virtual-wasm/7.0.0/libgcc.a wasm-virtual-wasm/lib/gcc/wasm-virtual-wasm/7.0.0/libgcc_s.a
	touch $@

build/wasm64/gcc-preliminary.make: build/wasm64/gcc-preliminary.dir build/wasm64/gcc-preliminary.configure
	$(MAKE) -C build/wasm64/gcc-preliminary
	$(MAKE) -C build/wasm64/gcc-preliminary install
	cp wasm64-virtual-wasm64/lib/gcc/wasm64-virtual-wasm64/7.0.0/libgcc.a wasm64-virtual-wasm64/lib/gcc/wasm64-virtual-wasm64/7.0.0/libgcc_eh.a
	cp wasm64-virtual-wasm64/lib/gcc/wasm64-virtual-wasm64/7.0.0/libgcc.a wasm64-virtual-wasm64/lib/gcc/wasm64-virtual-wasm64/7.0.0/libgcc_s.a
	touch $@

build/gcc-preliminary.clean: FORCE
	rm -rf build/gcc-preliminary src/gcc-preliminary
	rm -f build/gcc-preliminary.dir
	rm -f src/gcc-preliminary.dir
	rm -f build/gcc-preliminary.configure
	rm -f build/gcc-preliminary.make

build/asmjs/glibc.configure: src/glibc.dir build/asmjs/glibc.dir | build/asmjs/gcc-preliminary.make
	(cd build/asmjs/glibc; CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../../src/glibc/configure --enable-optimize=$(OPT_NATIVE) --host=asmjs-virtual-asmjs --target=asmjs-virtual-asmjs --enable-hacker-mode --enable-static --enable-static-nss --disable-shared --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs)
	touch $@

build/wasm/glibc.configure: src/glibc.dir build/wasm/glibc.dir | build/wasm/gcc-preliminary.make
	(cd build/wasm/glibc; CC=wasm-virtual-wasm-gcc PATH=$(PWD)/wasm-virtual-wasm/bin:$$PATH ../../../src/glibc/configure --enable-optimize=$(OPT_NATIVE) --host=wasm-virtual-wasm --target=wasm-virtual-wasm --enable-hacker-mode --enable-static --enable-static-nss --disable-shared --prefix=$(PWD)/wasm-virtual-wasm/wasm-virtual-wasm)
	touch $@

build/wasm64/glibc.configure: src/glibc.dir build/wasm64/glibc.dir | build/wasm64/gcc-preliminary.make
	(cd build/wasm64/glibc; CC=wasm64-virtual-wasm64-gcc PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH ../../../src/glibc/configure --enable-optimize=$(OPT_NATIVE) --host=wasm64-virtual-wasm64 --target=wasm64-virtual-wasm64 --enable-hacker-mode --enable-static --enable-static-nss --disable-shared --prefix=$(PWD)/wasm64-virtual-wasm64/wasm64-virtual-wasm64)
	touch $@

build/asmjs/glibc.make: build/asmjs/glibc.dir build/asmjs/glibc.configure
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/glibc
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/glibc install
	touch $@

build/wasm/glibc.make: build/wasm/glibc.dir build/wasm/glibc.configure
	CC=wasm-virtual-wasm-gcc PATH=$(PWD)/wasm-virtual-wasm/bin:$$PATH $(MAKE) -C build/wasm/glibc
	CC=wasm-virtual-wasm-gcc PATH=$(PWD)/wasm-virtual-wasm/bin:$$PATH $(MAKE) -C build/wasm/glibc install
	touch $@

build/wasm64/glibc.make: build/wasm64/glibc.dir build/wasm64/glibc.configure
	CC=wasm64-virtual-wasm64-gcc PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH $(MAKE) -C build/wasm64/glibc
	CC=wasm64-virtual-wasm64-gcc PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH $(MAKE) -C build/wasm64/glibc install
	touch $@

build/glibc.clean: FORCE
	rm -rf build/glibc src/glibc
	rm -f build/glibc.dir
	rm -f src/glibc.dir
	rm -f build/glibc.configure
	rm -f build/glibc.make

build/asmjs/gcc-final.configure: src/gcc-final.dir build/asmjs/gcc-final.dir | build/asmjs/glibc.make
	(cd build/asmjs/gcc-final; ../../../src/gcc-final/configure --enable-optimize=$(OPT_NATIVE) --target=asmjs-virtual-asmjs --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --disable-libssp --prefix=$(PWD)/asmjs-virtual-asmjs)
	touch $@

build/wasm64/gcc-final.configure: src/gcc-final.dir build/wasm64/gcc-final.dir | build/wasm64/glibc.make
	(cd build/wasm64/gcc-final; ../../../src/gcc-final/configure --enable-optimize=$(OPT_NATIVE) --target=wasm64-virtual-wasm64 --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --disable-libssp --prefix=$(PWD)/wasm64-virtual-wasm64)
	touch $@

build/asmjs/gcc-final.make: build/asmjs/gcc-final.dir build/asmjs/gcc-final.configure
	test -d build/asmjs/gcc-final/gcc || $(MKDIR) build/asmjs/gcc-final/gcc
	cp build/asmjs/gcc-preliminary/gcc/libgcc.a build/asmjs/gcc-final/gcc/libgcc_eh.a
	cp build/asmjs/gcc-preliminary/gcc/libgcc.a build/asmjs/gcc-final/gcc/libgcc_s.a
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/gcc-final
	cp build/asmjs/gcc-final/gcc/libgcc.a build/asmjs/gcc-final/gcc/libgcc_eh.a
	cp build/asmjs/gcc-final/gcc/libgcc.a build/asmjs/gcc-final/gcc/libgcc_s.a
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/gcc-final install
	touch $@

build/wasm64/gcc-final.make: build/wasm64/gcc-final.dir build/wasm64/gcc-final.configure
	test -d build/wasm64/gcc-final/gcc || $(MKDIR) build/wasm64/gcc-final/gcc
	cp build/wasm64/gcc-preliminary/gcc/libgcc.a build/wasm64/gcc-final/gcc/libgcc_eh.a
	cp build/wasm64/gcc-preliminary/gcc/libgcc.a build/wasm64/gcc-final/gcc/libgcc_s.a
	PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH $(MAKE) -C build/wasm64/gcc-final
	cp build/wasm64/gcc-final/gcc/libgcc.a build/wasm64/gcc-final/gcc/libgcc_eh.a
	cp build/wasm64/gcc-final/gcc/libgcc.a build/wasm64/gcc-final/gcc/libgcc_s.a
	PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH $(MAKE) -C build/wasm64/gcc-final install
	touch $@

build/asmjs/ncurses.configure: src/ncurses.dir build/asmjs/ncurses.dir | build/asmjs/gcc-final.make
	(cd build/asmjs/ncurses; CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../../src/ncurses/configure --enable-optimize=$(OPT_ASMJS) --build=x86_64-pc-linux-gnu --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs)
	touch $@

build/asmjs/ncurses.make: build/asmjs/ncurses.configure
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/ncurses
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/ncurses install
	touch $@

build/asmjs/emacs.configure: src/emacs.dir build/asmjs/emacs.dir | build/asmjs/ncurses.make
	(cd src/emacs; autoreconf -ivf)
	cp config/config.sub src/emacs/build-aux
	(cd build/asmjs/emacs; CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../../src/emacs/configure --enable-optimize=$(OPT_ASMJS) --with-x-toolkit=no --without-x --with-zlib --without-sound --without-all --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs)
	touch $@

build/asmjs/emacs.make: build/asmjs/emacs.configure build/asmjs/ncurses.make | build/asmjs/binfmt_misc.install
	$(MKDIR) -p $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/arpa $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/netinet
	touch $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/arpa/inet.h
	touch $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/netdb.h
	touch $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/netinet/in.h
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/emacs
	touch $@

build/asmjs/bash.configure: src/bash.dir build/asmjs/bash.dir | build/asmjs/gcc-final.make
	(cd build/asmjs/bash; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../../src/bash/configure --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs --disable-net-redirections --without-bash-malloc)
	touch $@

build/asmjs/bash.make: build/asmjs/bash.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/bash
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/bash install
	touch $@

build/asmjs/perl.configure: src/perl.dir build/asmjs/perl.dir | build/asmjs/gcc-final.make
	test -f build/asmjs/perl/config.sh && mv build/asmjs/perl/config.sh build/asmjs/perl/config.sh.old || true
	touch build/asmjs/perl/config.sh
	(cd build/asmjs/perl; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH sh ./Configure -der -Uusemymalloc -Dcc=asmjs-virtual-asmjs-gcc -Dincpth='$(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/include $(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/include-fixed $(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/../../../../asmjs-virtual-asmjs/include' -Dlibpth='$(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/include-fixed $(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/../../../../asmjs-virtual-asmjs/lib' -Dloclibpth=' ' -Dglibpth=' ' -Dplibpth=' ' -Dldflags=' ' -Uusedl -Dlibs='-lnsl -ldl -lm -lcrypt -lutil' -Dd_u32align=define -Dusedevel)
	touch $@

build/asmjs/perl.make: build/asmjs/perl.dir build/asmjs/perl.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/perl
	touch $@

build/common/spidermonkey.configure: src/spidermonkey.dir build/common/spidermonkey.dir
	(cd src/spidermonkey/js/src; autoconf2.13)
	(cd build/common/spidermonkey; ../../../src/spidermonkey/js/src/configure --enable-optimize=$(OPT_NATIVE) --disable-debug --disable-tests --prefix=$(PWD)/common/spidermonkey --without-system-zlib)
	touch $@

build/common/spidermonkey.make: build/common/spidermonkey.configure
	$(MAKE) -C build/common/spidermonkey
	$(MAKE) -C build/common/spidermonkey install
	test -L $(PWD)/common/bin/js || ($(MKDIR) -p $(PWD)/common/bin; ln -sf ../spidermonkey/bin/js $(PWD)/common/bin/js)
	touch $@

build/debug/spidermonkey.configure: src/spidermonkey.dir build/debug/spidermonkey.dir
	(cd src/spidermonkey/js/src; autoconf2.13)
	(cd build/debug/spidermonkey; ../../../src/spidermonkey/js/src/configure --disable-optimize --enable-debug --disable-tests --prefix=$(PWD)/debug/spidermonkey --without-system-zlib)
	touch $@

build/debug/spidermonkey.make: build/debug/spidermonkey.configure
	$(MAKE) -C build/debug/spidermonkey
	$(MAKE) -C build/debug/spidermonkey install
	touch $@

build/debug0/spidermonkey.configure: src/spidermonkey.dir build/debug0/spidermonkey.dir
	(cd src/spidermonkey/js/src; autoconf2.13)
	(cd build/debug0/spidermonkey; ../../../src/spidermonkey/js/src/configure --enable-optimize="-O0 -g" --disable-debug --disable-tests --prefix=$(PWD)/debug0/spidermonkey --without-system-zlib)
	touch $@

build/debug0/spidermonkey.make: build/debug0/spidermonkey.configure
	$(MAKE) -C build/debug0/spidermonkey
	$(MAKE) -C build/debug0/spidermonkey install
	touch $@

build/common/spidermonkey.clean: FORCE
	rm -f build/common/spidermonkey.make
	rm -f build/common/spidermonkey.configure
	rm -f build/common/spidermonkey.dir
	rm -f src/spidermonkey.dir
	rm -rf build/common/spidermonkey
	rm -rf src/spidermonkey
	touch $@

build/asmjs/coreutils.configure: src/coreutils.dir build/asmjs/coreutils.dir | build/asmjs/gcc-final.make
	(cd src/coreutils; ./bootstrap --gnulib-srcdir=gnulib --skip-po)
	(cd build/asmjs/coreutils; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../../src/coreutils/configure --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs --enable-static --disable-shared)
	touch $@

build/asmjs/coreutils.make: build/asmjs/coreutils.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/coreutils
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/coreutils install
	touch $@

build/asmjs/graphviz.configure: src/graphviz.dir build/asmjs/graphviz.dir | build/asmjs/gcc-final.make
	(cd build/asmjs/graphviz; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../../src/graphviz/configure --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs --without-pangocairo --without-gdk --without-gdk-pixbuf --without-gtk --enable-static --disable-shared)
	touch $@

build/asmjs/graphviz.make: build/asmjs/graphviz.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/graphviz
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/asmjs/graphviz install
	touch $@

build/binfmt_misc.install:
	sudo ./binfmt_misc/binfmt_misc $(PWD)/bin/interpreter || true
	sudo ./binfmt_misc/binfmt_misc-wasm $(PWD)/bin/interpreter-wasm || true
	sudo ./binfmt_misc/binfmt_misc-wasm64 $(PWD)/bin/interpreter-wasm64 || true
	touch $@

build/binfmt_misc-caching.install:
	sudo ./binfmt_misc/binfmt_misc $(PWD)/bin/caching-interpreter || true
	touch $@

build/gcc-final.clean: FORCE
	rm -rf build/gcc-final src/gcc-final
	rm -f build/gcc-final.dir
	rm -f src/gcc-final.dir
	rm -f build/gcc-final.configure
	rm -f build/gcc-final.make

build/bash.clean: FORCE
	rm -rf build/bash src/bash
	rm -f build/bash.dir
	rm -f src/bash.dir
	rm -f build/bash.configure
	rm -f build/bash.make

build/coreutils.clean: FORCE
	rm -rf build/coreutils src/coreutils
	rm -f build/coreutils.dir
	rm -f src/coreutils.dir
	rm -f build/coreutils.configure
	rm -f build/coreutils.make

build/graphviz.clean: FORCE
	rm -rf build/graphviz src/graphviz
	rm -f build/graphviz.dir
	rm -f src/graphviz.dir
	rm -f build/graphviz.configure
	rm -f build/graphviz.make

src/.dir:
	test -d src || $(MKDIR) src
	touch $@

src/bash.dir:
	test -L src/bash || ln -sf ../subrepos/bash src/bash
	touch $@

src/binutils-gdb.dir: src/.dir
	test -d src/binutils-gdb || mkdir src/binutils-gdb
	(cd subrepos/binutils-gdb; tar c --exclude .git .) | (cd src/binutils-gdb; tar x)
	touch $@

src/coreutils.dir: src/.dir
	test -d src/coreutils || mkdir src/coreutils
	(cd subrepos/coreutils; tar c --exclude .git .) | (cd src/coreutils; tar x)
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

src/graphviz.dir: src/.dir
	test -d src/graphviz || mkdir src/graphviz
	(cd subrepos/graphviz; tar c --exclude .git .) | (cd src/graphviz; tar x)
	touch $@

src/ncurses.dir: src/.dir
	test -L src/ncurses || ln -sf ../subrepos/ncurses src/ncurses
	touch $@

src/emacs.dir: src/.dir
	test -d src/emacs || mkdir src/emacs
	(cd subrepos/emacs; tar c --exclude .git .) | (cd src/emacs; tar x)
	touch $@

src/spidermonkey.dir: src/.dir
	test -d src/spidermonkey || mkdir src/spidermonkey
	(cd subrepos/mozilla; tar c --exclude .git .) | (cd src/spidermonkey; tar x)
	touch $@

src/perl.dir: src/.dir
	test -d src/perl || mkdir src/perl
	(cd subrepos/perl; tar c --exclude .git .) | (cd src/perl; tar x)
	touch $@

bin/hexify: hexify/hexify.c
	$(CC) $< -o $@

lib/asmjs.o: lib/asmjs.S build/asmjs/gcc-final.make
	asmjs-virtual-asmjs/bin/asmjs-virtual-asmjs-gcc -c $< -o $@

js/.dir:
	test -d js || mkdir js
	touch $@

js/asmjs-%.jsc.js: jsc/asmjs-%.jsc js/.dir
	test -d cache || mkdir cache
	perl ./bin/interpolate asmjs-virtual-asmjs < $< > $@

js/asmjs-%.jsc.js: jsc/asm-%.jsc js/.dir
	test -d cache || mkdir cache
	perl ./bin/interpolate asmjs-virtual-asmjs < $< > $@

js/wasm-%.jsc.js: jsc/wasm-%.jsc js/.dir
	test -d cache || mkdir cache
	perl ./bin/interpolate wasm-virtual-wasm < $< > $@

js/wasm-%.jsc.js: jsc/asm-%.jsc js/.dir
	test -d cache || mkdir cache
	perl ./bin/interpolate wasm-virtual-wasm < $< > $@

js/wasm64-%.jsc.js: jsc/wasm64-%.jsc js/.dir
	test -d cache || mkdir cache
	perl ./bin/interpolate wasm64-virtual-wasm64 < $< > $@

js/wasm64-%.jsc.js: jsc/asm-%.jsc js/.dir
	test -d cache || mkdir cache
	perl ./bin/interpolate wasm64-virtual-wasm64 < $< > $@

js/asmjs.js: js/asmjs-main.jsc.js js/asmjs-system.jsc.js js/asmjs-thinthin.jsc.js js/asmjs-vt100.jsc.js build/asmjs/gcc-final.make
	echo "// autogenerated, do not edit" > $@.new
	cat js/asmjs-system.jsc.js js/asmjs-thinthin.jsc.js js/asmjs-vt100.jsc.js js/asmjs-main.jsc.js >> $@.new
	mv $@.new $@

js/wasm64.js: js/wasm64-main.jsc.js js/wasm64-system.jsc.js js/wasm64-thinthin.jsc.js js/wasm64-vt100.jsc.js build/wasm64/gcc-final.make
	echo "// autogenerated, do not edit" > $@.new
	cat js/wasm64-system.jsc.js js/wasm64-thinthin.jsc.js js/wasm64-vt100.jsc.js js/wasm64-main.jsc.js >> $@.new
	mv $@.new $@

cache/interpolate-cache.pl: bootstrap/interpolate-cache.pl
	test -d cache || mkdir cache
	cp $< $@

clean:
	rm -rf asmjs-virtual-asmjs build src js bin/hexify # cache

tests/%.c.s: tests/%.c build/gcc-final.make
	./asmjs-virtual-asmjs/bin/asmjs-virtual-asmjs-gcc -S $< -o $@

tests/%.cpp.s: tests/%.cpp build/gcc-final.make
	./asmjs-virtual-asmjs/bin/asmjs-virtual-asmjs-g++ -S $< -o $@

tests/%.s.o: tests/%.s build/gcc-final.make
	./asmjs-virtual-asmjs/bin/asmjs-virtual-asmjs-gcc -c $< -o $@

tests/%.o.exe: tests/%.o build/gcc-final.make
	./asmjs-virtual-asmjs/bin/asmjs-virtual-asmjs-gcc $< -o $@

tests/%.exe.js: tests/%.exe build/gcc-final.make
	./bin/prepare $< > $@

intermediate/dot: asmjs-virtual-asmjs/asmjs-virtual-asmjs/bin/dot_static lib/mfinfo.o lib/loop.o | build/graphviz.make
	./bin/jsexport $< intermediate/dot-export
	./bin/multifile-add1 intermediate/dot-export lib/mfinfo.o intermediate/dot-export-mfinfo
	./bin/multifile-add1 intermediate/dot-export-mfinfo lib/loop.o $@

lib/%.o: lib/%.c
	asmjs-virtual-asmjs-gcc -c -o $@ $<

lib/%.o: lib/%.cc
	asmjs-virtual-asmjs-g++ -c -o $@ $<

.PHONY: FORCE clean fetch
