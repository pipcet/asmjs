all: bin/hexify lib/asmjs.o build/gcc-final.make tests/001-do-nothing.c.s.o.exe.js

MKDIR ?= mkdir
PWD ?= $(shell pwd)
OPT_NATIVE ?= "-O3 -g0"
OPT_ASMJS ?= "-O2"

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

build/ncurses.dir: build/.dir
	test -d build/ncurses || $(MKDIR) build/ncurses
	touch $@

build/emacs.dir: build/.dir
	test -d build/emacs || $(MKDIR) build/emacs
	touch $@

build/spidermonkey.dir: build/.dir
	test -d build/spidermonkey || $(MKDIR) build/spidermonkey
	touch $@

build/bash.dir: build/.dir
	test -d build/bash || $(MKDIR) build/bash
	touch $@

build/perl.dir: build/.dir
	test -d build/perl || mkdir build/perl
	(cd src/perl; tar c --exclude .git .) | (cd build/perl; tar x)
	touch $@

build/coreutils.dir: build/.dir
	test -d build/coreutils || $(MKDIR) build/coreutils
	touch $@

build/graphviz.dir: build/.dir
	test -d build/graphviz || $(MKDIR) build/graphviz
	touch $@

build/binutils-gdb.configure: src/binutils-gdb.dir build/binutils-gdb.dir
	(cd src/binutils-gdb/gas; aclocal-1.11; automake-1.11)
	(cd build/binutils-gdb; ../../src/binutils-gdb/configure --enable-optimize=$(OPT_NATIVE) --target=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs)
	touch $@

build/binutils-gdb.make: build/binutils-gdb.dir build/binutils-gdb.configure
	$(MAKE) -C build/binutils-gdb
	$(MAKE) -C build/binutils-gdb install
	touch $@

build/binutils-gdb.clean: FORCE
	rm -rf build/binutils-gdb src/binutils-gdb
	rm -f build/binutils-gdb.dir
	rm -f src/binutils-gdb.dir
	rm -f build/binutils-gdb.configure
	rm -f build/binutils-gdb.make

build/gcc-preliminary.configure: src/gcc-preliminary.dir build/gcc-preliminary.dir | build/binutils-gdb.make
	(cd build/gcc-preliminary; ../../src/gcc-preliminary/configure --enable-optimize=$(OPT_NATIVE) --target=asmjs-virtual-asmjs --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/asmjs-virtual-asmjs)
	touch $@

# test -L asmjs-virtual-asmjs/asmjs-virtual-asmjs || ln -sf . asmjs-virtual-asmjs/asmjs-virtual-asmjs

build/gcc-preliminary.make: build/gcc-preliminary.dir build/gcc-preliminary.configure
	$(MAKE) -C build/gcc-preliminary
	$(MAKE) -C build/gcc-preliminary install
	cp asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc.a asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc_eh.a
	cp asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc.a asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/libgcc_s.a
	touch $@

build/gcc-preliminary.clean: FORCE
	rm -rf build/gcc-preliminary src/gcc-preliminary
	rm -f build/gcc-preliminary.dir
	rm -f src/gcc-preliminary.dir
	rm -f build/gcc-preliminary.configure
	rm -f build/gcc-preliminary.make

build/glibc.configure: src/glibc.dir build/glibc.dir | build/gcc-preliminary.make
	(cd build/glibc; CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../src/glibc/configure --enable-optimize=$(OPT_NATIVE) --host=asmjs-virtual-asmjs --target=asmjs-virtual-asmjs --enable-hacker-mode --enable-static --enable-static-nss --disable-shared --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs)
	touch $@

build/glibc.make: build/glibc.dir build/glibc.configure
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/glibc
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/glibc install
	touch $@

build/glibc.clean: FORCE
	rm -rf build/glibc src/glibc
	rm -f build/glibc.dir
	rm -f src/glibc.dir
	rm -f build/glibc.configure
	rm -f build/glibc.make

build/gcc-final.configure: src/gcc-final.dir build/gcc-final.dir | build/glibc.make
	(cd build/gcc-final; ../../src/gcc-final/configure --enable-optimize=$(OPT_NATIVE) --target=asmjs-virtual-asmjs --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --disable-libssp --prefix=$(PWD)/asmjs-virtual-asmjs)
	touch $@

build/gcc-final.make: build/gcc-final.dir build/gcc-final.configure
	test -d build/gcc-final/gcc || $(MKDIR) build/gcc-final/gcc
	cp build/gcc-preliminary/gcc/libgcc.a build/gcc-final/gcc/libgcc_eh.a
	cp build/gcc-preliminary/gcc/libgcc.a build/gcc-final/gcc/libgcc_s.a
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/gcc-final
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/gcc-final install
	touch $@

build/ncurses.configure: src/ncurses.dir build/ncurses.dir | build/gcc-final.make
	(cd build/ncurses; CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../src/ncurses/configure --enable-optimize=$(OPT_ASMJS) --build=x86_64-pc-linux-gnu --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs)
	touch $@

build/ncurses.make: build/ncurses.configure
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/ncurses
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/ncurses install
	touch $@

build/emacs.configure: src/emacs.dir build/emacs.dir | build/ncurses.make
	(cd src/emacs; autoreconf -ivf)
	cp config/config.sub src/emacs/build-aux
	(cd build/emacs; CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../src/emacs/configure --enable-optimize=$(OPT_ASMJS) --with-x-toolkit=no --without-x --with-zlib --without-sound --without-all --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs)
	touch $@

build/emacs.make: build/emacs.configure build/ncurses.make | build/binfmt_misc.install
	$(MKDIR) -p $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/arpa $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/netinet
	touch $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/arpa/inet.h
	touch $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/netdb.h
	touch $(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs/include/netinet/in.h
	CC=asmjs-virtual-asmjs-gcc PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/emacs
	touch $@

build/bash.configure: src/bash.dir build/bash.dir
	(cd build/bash; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../src/bash/configure --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs --disable-net-redirections --without-bash-malloc)
	touch $@

build/bash.make: build/bash.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/bash
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/bash install
	touch $@

build/perl.configure: src/perl.dir build/perl.dir | build/gcc-final.make
	test -f build/perl/config.sh && mv build/perl/config.sh build/perl/config.sh.old || true
	touch build/perl/config.sh
	(cd build/perl; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH sh ./Configure -der -Uusemymalloc -Dcc=asmjs-virtual-asmjs-gcc -Dincpth='$(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/include $(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/include-fixed $(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/../../../../asmjs-virtual-asmjs/include' -Dlibpth='$(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/include-fixed $(PWD)/asmjs-virtual-asmjs/lib/gcc/asmjs-virtual-asmjs/7.0.0/../../../../asmjs-virtual-asmjs/lib' -Dloclibpth=' ' -Dglibpth=' ' -Dplibpth=' ' -Dldflags=' ')
	touch $@

build/spidermonkey.configure: src/spidermonkey.dir build/spidermonkey.dir
	(cd src/spidermonkey/js/src; autoconf2.13)
	(cd build/spidermonkey; ../../src/spidermonkey/js/src/configure --enable-optimize=$(OPT_NATIVE) --disable-debug --disable-tests --prefix=$(PWD)/asmjs-virtual-asmjs/spidermonkey --without-system-zlib)
	touch $@

build/perl.make: build/perl.dir build/perl.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/perl
	touch $@

build/spidermonkey.make: build/spidermonkey.configure
	$(MAKE) -C build/spidermonkey
	$(MAKE) -C build/spidermonkey install
	test -L $(PWD)/asmjs-virtual-asmjs/bin/js || ($(MKDIR) -p $(PWD)/asmjs-virtual-asmjs/bin; ln -sf ../spidermonkey/bin/js $(PWD)/asmjs-virtual-asmjs/bin/js)
	touch $@

build/spidermonkey.clean: build/spidermonkey.make
	rm -f build/spidermonkey.make
	rm -f build/spidermonkey.configure
	rm -f build/spidermonkey.dir
	rm -f src/spidermonkey.dir
	rm -rf build/spidermonkey
	rm -rf src/spidermonkey
	touch $@

build/coreutils.configure: src/coreutils.dir build/coreutils.dir
	(cd src/coreutils; ./bootstrap --gnulib-srcdir=gnulib --skip-po)
	(cd build/coreutils; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../src/coreutils/configure --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs --enable-static --disable-shared)
	touch $@

build/coreutils.make: build/coreutils.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/coreutils
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/coreutils install
	touch $@

build/graphviz.configure: src/graphviz.dir build/graphviz.dir
	(cd build/graphviz; PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH ../../src/graphviz/configure --host=asmjs-virtual-asmjs --prefix=$(PWD)/asmjs-virtual-asmjs/asmjs-virtual-asmjs --without-pangocairo --without-gdk --without-gdk-pixbuf --without-gtk --enable-static --disable-shared)
	touch $@

build/graphviz.make: build/graphviz.configure
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/graphviz
	PATH=$(PWD)/asmjs-virtual-asmjs/bin:$$PATH $(MAKE) -C build/graphviz install
	touch $@

build/binfmt_misc.install:
	sudo ./binfmt_misc/binfmt_misc $(PWD)/bin/interpreter) || true
	touch $@

build/binfmt_misc-caching.install:
	sudo ./binfmt_misc/binfmt_misc $(PWD)/bin/caching-interpreter) || true
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

lib/asmjs.o: lib/asmjs.S build/gcc-final.make
	asmjs-virtual-asmjs/bin/asmjs-virtual-asmjs-gcc -c $< -o $@

%.jsc.js: %.jsc
	test -d cache || mkdir cache
	perl ./bin/interpolate $< > $@

js/asmjs.js: js/asmjs-main.jsc.js js/asmjs-system.jsc.js js/asmjs-thinthin.jsc.js js/asmjs-vt100.jsc.js
	cat js/asmjs-main.jsc.js js/asmjs-system.jsc.js js/asmjs-thinthin.jsc.js js/asmjs-vt100.jsc.js > $@.new
	mv $@.new $@

clean:
	rm -rf asmjs-virtual-asmjs build cache src

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

.PHONY: FORCE clean fetch
