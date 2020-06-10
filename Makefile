all: build/wasm32/glibc-static.make build/wasm32/glibc.make bin/hexify js/asmjs.js lib/asmjs.o build/asmjs/gcc-final.make build/asmjs/perl.make build/asmjs/emacs.make

MKDIR ?= mkdir
PWD ?= $(shell pwd)
OPT_NATIVE ?= "-O0 -g3"
OPT_ASMJS ?= "-O2"

env:
	@echo "export ASMJSDIR=$(PWD)"
	@echo "export PATH=$(PWD)/common3/bin:$(PWD)/asmjs-unknown-none/bin:$(PWD)/wasm32-unknown-none/bin:$(PWD)/bin:$$PATH"
	@echo "export LANG=C"
	@echo "export JSFLAGS=\"--no-threads\""

# asmjs-unknown-none/lib/gcc/asmjs-unknown-none/7.0.1/libgcc_eh.a: asmjs-unknown-none/lib/gcc/asmjs-unknown-none/7.0.1/libgcc.a
#	cp $< $@

# architecture-independent package-independent
build/.dir:
	test -d build || $(MKDIR) build
	touch $@

src/.dir:
	test -d src || $(MKDIR) src
	touch $@

# wasm32 package-independent
build/wasm32/.dir: build/.dir
	test -d build/wasm32 || $(MKDIR) build/wasm32
	touch $@

src/wasm32/.dir: src/.dir
	test -d src/wasm32 || $(MKDIR) src/wasm32
	touch $@

# wasm32 binutils-gdb
build/wasm32/binutils-gdb.dir: build/wasm32/.dir
	test -d build/wasm32/binutils-gdb || $(MKDIR) build/wasm32/binutils-gdb
	touch $@

src/wasm32/binutils-gdb.dir: src/wasm32/.dir
	test -d src/wasm32/binutils-gdb || mkdir src/wasm32/binutils-gdb
	(cd subrepos/binutils-gdb; tar c --exclude .git .) | (cd src/wasm32/binutils-gdb; tar x)
	touch $@

build/wasm32/binutils-gdb.configure: src/wasm32/binutils-gdb.dir build/wasm32/binutils-gdb.dir
	(cd src/wasm32/binutils-gdb/gas; aclocal; automake; autoreconf)
	(cd build/wasm32/binutils-gdb; ../../../src/wasm32/binutils-gdb/configure --target=wasm32-unknown-none --enable-debug --prefix=$(PWD)/wasm32-unknown-none CFLAGS=$(OPT_NATIVE))
	touch $@

build/wasm32/binutils-gdb.make: build/wasm32/binutils-gdb.dir build/wasm32/binutils-gdb.configure
	$(MAKE) -C build/wasm32/binutils-gdb
	$(MAKE) -C build/wasm32/binutils-gdb install
	(cd bin; ln -sf ../wasm32-unknown-none/bin/wasm32-unknown-none-* .)
	touch $@

# wasm32 gcc-preliminary
build/wasm32/gcc-preliminary.dir: build/wasm32/.dir
	test -d build/wasm32/gcc-preliminary || $(MKDIR) build/wasm32/gcc-preliminary
	touch $@

build/wasm32/gcc-preliminary.configure: src/gcc-preliminary.dir build/wasm32/gcc-preliminary.dir | build/wasm32/binutils-gdb.make
	(cd build/wasm32/gcc-preliminary; ../../../src/gcc-preliminary/configure --enable-optimize=$(OPT_NATIVE) --target=wasm32-unknown-none --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/wasm32-unknown-none)
	touch $@

build/wasm32/gcc-preliminary.make: build/wasm32/gcc-preliminary.dir build/wasm32/gcc-preliminary.configure
	$(MAKE) -C build/wasm32/gcc-preliminary
	$(MAKE) -C build/wasm32/gcc-preliminary install
	cp wasm32-unknown-none/lib/gcc/wasm32-unknown-none/11.0.0/libgcc.a wasm32-unknown-none/lib/gcc/wasm32-unknown-none/11.0.0/libgcc_eh.a
	cp wasm32-unknown-none/lib/gcc/wasm32-unknown-none/11.0.0/libgcc.a wasm32-unknown-none/lib/gcc/wasm32-unknown-none/11.0.0/libgcc_s.a
	(cd bin; ln -sf ../wasm32-unknown-none/bin/wasm32-unknown-none-* .)
	touch $@

build/common/.dir: build/.dir
	test -d build/common || $(MKDIR) build/common
	touch $@

build/common3/.dir: build/.dir
	test -d build/common3 || $(MKDIR) build/common3
	touch $@

build/common3x/.dir: build/.dir
	test -d build/common3x || $(MKDIR) build/common3x
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

build/asmjs-cross/.dir: build/.dir
	test -d build/asmjs-cross || $(MKDIR) build/asmjs-cross
	touch $@

build/native/.dir: build/.dir
	test -d build/native || $(MKDIR) build/native
	touch $@

build/asmjs/binutils-gdb.dir: build/asmjs/.dir
	test -d build/asmjs/binutils-gdb || $(MKDIR) build/asmjs/binutils-gdb
	touch $@

build/native/binutils-gdb.dir: build/native/.dir
	test -d build/native/binutils-gdb || $(MKDIR) build/native/binutils-gdb
	touch $@

build/asmjs/gcc-preliminary.dir: build/asmjs/.dir
	test -d build/asmjs/gcc-preliminary || $(MKDIR) build/asmjs/gcc-preliminary
	touch $@

build/native/gcc.dir: build/native/.dir
	test -d build/native/gcc || $(MKDIR) build/native/gcc
	touch $@

build/asmjs/glibc.dir: build/asmjs/.dir
	test -d build/asmjs/glibc || $(MKDIR) build/asmjs/glibc
	touch $@

build/asmjs-cross/glibc.dir: build/asmjs-cross/.dir
	test -d build/asmjs-cross/glibc || $(MKDIR) build/asmjs-cross/glibc
	touch $@

build/wasm32/glibc.dir: build/wasm32/.dir
	test -d build/wasm32/glibc || $(MKDIR) build/wasm32/glibc
	touch $@

build/wasm32/glibc-static.dir: build/wasm32/.dir
	test -d build/wasm32/glibc-static || $(MKDIR) build/wasm32/glibc-static
	touch $@

build/asmjs/gcc-final.dir: build/asmjs/.dir
	test -d build/asmjs/gcc-final || $(MKDIR) build/asmjs/gcc-final
	touch $@

build/wasm32/gcc-final.dir: build/wasm32/.dir
	test -d build/wasm32/gcc-final || $(MKDIR) build/wasm32/gcc-final
	touch $@

build/wasm32/musl.dir: build/wasm32/.dir
	test -d build/wasm32/musl || $(MKDIR) build/wasm32/musl
	touch $@

build/wasm32/musl.configure: build/wasm32/musl.dir src/musl.dir
	(cd build/wasm32/musl; PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH ../../../src/musl/configure LDFLAGS="-Wl,-soname=libc.wasm" --prefix=$(PWD)/wasm32-unknown-none/wasm32-unknown-none --target=wasm32-unknown-none --build=x86_64-pc-linux-gnu --enable-shared --enable-static)
	touch $@

build/asmjs/ncurses.dir: build/asmjs/.dir
	test -d build/asmjs/ncurses || $(MKDIR) build/asmjs/ncurses
	touch $@

build/wasm32/ncurses.dir: build/wasm32/.dir
	test -d build/wasm32/ncurses || $(MKDIR) build/wasm32/ncurses
	touch $@

build/asmjs/emacs.dir: build/asmjs/.dir
	test -d build/asmjs/emacs || $(MKDIR) build/asmjs/emacs
	touch $@

build/wasm32/emacs.dir: build/wasm32/.dir
	test -d build/wasm32/emacs || $(MKDIR) build/wasm32/emacs
	touch $@

build/asmjs-cross/ncurses.dir: build/asmjs-cross/.dir
	test -d build/asmjs-cross/ncurses || $(MKDIR) build/asmjs-cross/ncurses
	touch $@

build/asmjs-cross/emacs.dir: build/asmjs-cross/.dir
	test -d build/asmjs-cross/emacs || $(MKDIR) build/asmjs-cross/emacs
	touch $@

build/common/wabt.dir: build/common/.dir
	test -d build/common/wabt || $(MKDIR) build/common/wabt
	touch $@

build/common/spidermonkey.dir: build/common/.dir
	test -d build/common/spidermonkey || $(MKDIR) build/common/spidermonkey
	touch $@

build/common3/spidermonkey.dir: build/common3/.dir
	test -d build/common3/spidermonkey || $(MKDIR) build/common3/spidermonkey
	touch $@

build/common3x/spidermonkey.dir: build/common3x/.dir
	test -d build/common3x/spidermonkey || $(MKDIR) build/common3x/spidermonkey
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

build/wasm32/bash.dir: build/wasm32/.dir
	test -d build/wasm32/bash || $(MKDIR) build/wasm32/bash
	touch $@

build/asmjs/perl.dir: build/asmjs/.dir src/perl.dir
	test -d build/asmjs/perl || mkdir build/asmjs/perl
	(cd src/perl; tar c --exclude .git .) | (cd build/asmjs/perl; tar x)
	touch $@

build/asmjs-cross/perl.dir: build/asmjs-cross/.dir src/perl.dir
	test -d build/asmjs-cross/perl || mkdir build/asmjs-cross/perl
	(cd src/perl; tar c --exclude .git .) | (cd build/asmjs-cross/perl; tar x)
	touch $@

build/wasm32/perl.dir: build/wasm32/.dir src/perl.dir
	test -d build/wasm32/perl || mkdir build/wasm32/perl
	(cd src/perl; tar c --exclude .git .) | (cd build/wasm32/perl; tar x)
	touch $@

build/wasm32-cross/perl.dir: build/wasm32-cross/.dir src/perl.dir
	test -d build/wasm32-cross/perl || mkdir build/wasm32-cross/perl
	(cd src/perl; tar c --exclude .git .) | (cd build/wasm32-cross/perl; tar x)
	touch $@

build/asmjs/coreutils.dir: build/asmjs/.dir
	test -d build/asmjs/coreutils || $(MKDIR) build/asmjs/coreutils
	touch $@

build/asmjs/graphviz.dir: build/asmjs/.dir
	test -d build/asmjs/graphviz || $(MKDIR) build/asmjs/graphviz
	touch $@

build/wasm32/graphviz.dir: build/wasm32/.dir
	test -d build/wasm32/graphviz || $(MKDIR) build/wasm32/graphviz
	touch $@

build/wasm32/coreutils.dir: build/wasm32/.dir
	test -d build/wasm32/coreutils || $(MKDIR) build/wasm32/coreutils
	touch $@

build/asmjs/binutils-gdb.configure: src/binutils-gdb.dir build/asmjs/binutils-gdb.dir
	(cd src/binutils-gdb/gas; aclocal-1.15; automake-1.15)
	(cd build/asmjs/binutils-gdb; ../../../src/binutils-gdb/configure --target=asmjs-unknown-none --prefix=$(PWD)/asmjs-unknown-none CFLAGS=$(OPT_NATIVE))
	touch $@

build/native/binutils-gdb.configure: src/binutils-gdb.dir build/native/binutils-gdb.dir
	(cd src/binutils-gdb/gas; aclocal-1.15; automake-1.15)
	(cd build/native/binutils-gdb; ../../../src/binutils-gdb/configure --enable-debug --prefix=$(PWD)/native CFLAGS=$(OPT_NATIVE))
	touch $@

build/asmjs/binutils-gdb.make: build/asmjs/binutils-gdb.dir build/asmjs/binutils-gdb.configure
	$(MAKE) -C build/asmjs/binutils-gdb
	$(MAKE) -C build/asmjs/binutils-gdb install
	touch $@

build/native/binutils-gdb.make: build/native/binutils-gdb.dir build/native/binutils-gdb.configure
	$(MAKE) -C build/native/binutils-gdb
	$(MAKE) -C build/native/binutils-gdb install
	touch $@

build/binutils-gdb.clean: FORCE
	rm -rf build/binutils-gdb src/binutils-gdb src/wasm32/binutils-gdb
	rm -f build/binutils-gdb.dir
	rm -f src/binutils-gdb.dir
	rm -f build/binutils-gdb.configure
	rm -f build/binutils-gdb.make

build/%/binutils-gdb.clean: FORCE
	rm -rf build/$*/binutils-gdb src/$*/binutils-gdb
	rm -f build/$*/binutils-gdb.dir
	rm -f src/$*/binutils-gdb.dir
	rm -f build/$*/binutils-gdb.configure
	rm -f build/$*/binutils-gdb.make

build/asmjs/gcc-preliminary.configure: src/gcc-preliminary.dir build/asmjs/gcc-preliminary.dir | build/asmjs/binutils-gdb.make
	(cd build/asmjs/gcc-preliminary; ../../../src/gcc-preliminary/configure --enable-optimize=$(OPT_NATIVE) --target=asmjs-unknown-none --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/asmjs-unknown-none)
	touch $@

build/native/gcc.configure: src/gcc-preliminary.dir build/native/gcc.dir
	(cd build/native/gcc; ../../../src/gcc-preliminary/configure --enable-optimize=$(OPT_NATIVE) --target=x86_64-pc-linux-gnu --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/x86_64-linux-gnu/ --disable-bootstrap)
	touch $@

build/asmjs/gcc-preliminary.make: build/asmjs/gcc-preliminary.dir build/asmjs/gcc-preliminary.configure
	$(MAKE) -C build/asmjs/gcc-preliminary
	$(MAKE) -C build/asmjs/gcc-preliminary install
	cp asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/libgcc.a asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/libgcc_eh.a
	cp asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/libgcc.a asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/libgcc_s.a
	touch $@

build/%/gcc-preliminary.clean: FORCE
	rm -rf build/$*/gcc-preliminary
	rm -f build/$*/gcc-preliminary.dir
	rm -f build/$*/gcc-preliminary.configure
	rm -f build/$*/gcc-preliminary.make

build/asmjs/glibc.configure: src/glibc.dir build/asmjs/glibc.dir | build/asmjs/gcc-preliminary.make
	(cd build/asmjs/glibc; CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH ../../../src/glibc/configure --enable-optimize=$(OPT_NATIVE) --host=asmjs-unknown-none --target=asmjs-unknown-none --enable-hacker-mode --enable-static --enable-static-nss --disable-shared --prefix=$(PWD)/asmjs-unknown-none/asmjs-unknown-none)
	touch $@

build/asmjs-cross/glibc.configure: src/glibc.dir build/asmjs-cross/glibc.dir | build/asmjs/gcc-preliminary.make
	(cd build/asmjs-cross/glibc; CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH ../../../src/glibc/configure --enable-optimize=$(OPT_NATIVE) --host=asmjs-unknown-none --enable-hacker-mode --enable-static --enable-static-nss --disable-shared --prefix=$(PWD)/asmjs-unknown-none/asmjs-unknown-none)
	touch $@

build/wasm32/glibc.configure: src/glibc.dir build/wasm32/glibc.dir | build/wasm32/gcc-preliminary.make
	(cd build/wasm32/glibc; CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH ../../../src/glibc/configure CFLAGS="-fPIC -O3 -Wno-error=missing-attributes" --enable-optimize=$(OPT_NATIVE) --host=wasm32-unknown-none --target=wasm32-unknown-none --enable-hacker-mode --prefix=$(PWD)/wasm32-unknown-none/wasm32-unknown-none)
	touch $@

build/wasm32/glibc-static.configure: src/glibc.dir build/wasm32/glibc-static.dir | build/wasm32/gcc-preliminary.make
	(cd build/wasm32/glibc-static; CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH ../../../src/glibc/configure CFLAGS="-O3" --enable-optimize=$(OPT_NATIVE) --host=wasm32-unknown-none --target=wasm32-unknown-none --enable-hacker-mode --enable-static --prefix=$(PWD)/wasm32-unknown-none/wasm32-unknown-none)
	touch $@

build/asmjs/glibc.make: build/asmjs/glibc.dir build/asmjs/glibc.configure
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/glibc
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/glibc install
	touch $@

build/asmjs-cross/glibc.make: build/asmjs-cross/glibc.dir build/asmjs-cross/glibc.configure
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs-cross/glibc
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs-cross/glibc install
	touch $@

build/wasm32/glibc.make: build/wasm32/glibc.dir build/wasm32/glibc.configure
	CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/glibc
	CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/glibc install
	touch $@

build/wasm32/glibc-static.make: build/wasm32/glibc-static.dir build/wasm32/glibc-static.configure
	CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/glibc-static
	touch $@

build/wasm32/glibc-semishared.make: build/wasm32/glibc.make
	$(PWD)/wasm32-unknown-none/bin/wasm32-unknown-none-ld -shared --whole-archive lib/wasm32-globals.o $(PWD)/wasm32-unknown-none/wasm32-unknown-none/lib/libc.a --no-whole-archive $(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/libgcc.a -o $(PWD)/wasm32-unknown-none/wasm32-unknown-none/lib/libc.so
	$(PWD)/bin/wasmify-wasm32 $(PWD)/wasm32-unknown-none/wasm32-unknown-none/lib/libc.so > $(PWD)/libc.wasm
	touch $@

build/wasm32/libdl.make: build/wasm32/glibc-semishared.make build/wasm32/gcc-final.make
	$(MAKE) -C libdl
	cp libdl/libdl.so wasm32-unknown-none/wasm32-unknown-none/lib/libdl.so
	wasmify-wasm32 libdl/libdl.so > libdl.wasm
	touch $@

build/wasm32/libs.make: build/wasm32/glibc-semishared.make build/wasm32/gcc-final.make build/wasm32/libdl.make
	touch $@

build/glibc.clean: FORCE
	rm -rf build/glibc src/glibc
	rm -f build/glibc.dir
	rm -f src/glibc.dir
	rm -f build/glibc.configure
	rm -f build/glibc.make

build/wasm32/musl.make: build/wasm32/musl.dir build/wasm32/musl.configure
	CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/musl
	CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/musl install
	touch $@

build/asmjs/gcc-final.configure: src/gcc-final.dir build/asmjs/gcc-final.dir | build/asmjs/glibc.make
	(cd build/asmjs/gcc-final; ../../../src/gcc-final/configure --enable-optimize=$(OPT_NATIVE) --target=asmjs-unknown-none --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --disable-libssp --prefix=$(PWD)/asmjs-unknown-none)
	touch $@

build/wasm32/gcc-final.configure: src/gcc-final.dir build/wasm32/gcc-final.dir | build/wasm32/glibc.make
	(cd build/wasm32/gcc-final; ../../../src/gcc-final/configure --enable-optimize=$(OPT_NATIVE) --target=wasm32-unknown-none --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --disable-libssp --prefix=$(PWD)/wasm32-unknown-none)
	touch $@

build/asmjs/gcc-final.make: build/asmjs/gcc-final.dir build/asmjs/gcc-final.configure
	test -d build/asmjs/gcc-final/gcc || $(MKDIR) build/asmjs/gcc-final/gcc
	cp build/asmjs/gcc-preliminary/gcc/libgcc.a build/asmjs/gcc-final/gcc/libgcc_eh.a
	cp build/asmjs/gcc-preliminary/gcc/libgcc.a build/asmjs/gcc-final/gcc/libgcc_s.a
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/gcc-final
	cp build/asmjs/gcc-final/gcc/libgcc.a build/asmjs/gcc-final/gcc/libgcc_eh.a
	cp build/asmjs/gcc-final/gcc/libgcc.a build/asmjs/gcc-final/gcc/libgcc_s.a
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/gcc-final install
	touch $@

build/wasm32/gcc-final.make: build/wasm32/gcc-final.dir build/wasm32/gcc-final.configure
	test -d build/wasm32/gcc-final/gcc || $(MKDIR) build/wasm32/gcc-final/gcc
	cp build/wasm32/gcc-preliminary/gcc/libgcc.a build/wasm32/gcc-final/gcc/libgcc_eh.a
	cp build/wasm32/gcc-preliminary/gcc/libgcc.a build/wasm32/gcc-final/gcc/libgcc_s.a
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/gcc-final
	cp build/wasm32/gcc-final/gcc/libgcc.a build/wasm32/gcc-final/gcc/libgcc_eh.a
	cp build/wasm32/gcc-final/gcc/libgcc.a build/wasm32/gcc-final/gcc/libgcc_s.a
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/gcc-final install
	touch $@

build/asmjs/ncurses.configure: src/ncurses.dir build/asmjs/ncurses.dir | build/asmjs/gcc-final.make
	(cd build/asmjs/ncurses; CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH ../../../src/ncurses/configure --enable-optimize=$(OPT_ASMJS) --build=x86_64-pc-linux-gnu --host=asmjs-unknown-none --prefix=$(PWD)/asmjs-unknown-none/asmjs-unknown-none)
	touch $@

build/wasm32/ncurses.configure: src/ncurses.dir build/wasm32/ncurses.dir | build/wasm32/gcc-final.make
	(cd build/wasm32/ncurses; CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH ../../../src/ncurses/configure --enable-optimize=$(OPT_ASMJS) --build=x86_64-pc-linux-gnu --host=wasm32-unknown-none --prefix=$(PWD)/wasm32-unknown-none/wasm32-unknown-none)
	touch $@

build/asmjs/ncurses.make: build/asmjs/ncurses.configure
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/ncurses
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/ncurses install
	touch $@

build/wasm32/ncurses.make: build/wasm32/ncurses.configure
	CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/ncurses
	CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/ncurses install
	touch $@

build/asmjs-cross/ncurses.configure: src/ncurses.dir build/asmjs-cross/ncurses.dir | build/asmjs/gcc-final.make
	(cd build/asmjs-cross/ncurses; CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH ../../../src/ncurses/configure --enable-optimize=$(OPT_ASMJS) --build=x86_64-pc-linux-gnu --host=asmjs-unknown-none --prefix=$(PWD)/asmjs-unknown-none/asmjs-unknown-none)
	touch $@

build/asmjs-cross/ncurses.make: build/asmjs-cross/ncurses.configure
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs-cross/ncurses
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs-cross/ncurses install
	touch $@

build/asmjs/emacs.configure: src/emacs.dir build/asmjs/emacs.dir | build/asmjs/ncurses.make
	(cd src/emacs; autoreconf -ivf)
	cp config/config.sub src/emacs/build-aux
	(cd build/asmjs/emacs; CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH ../../../src/emacs/configure --enable-optimize=$(OPT_ASMJS) --with-x-toolkit=no --without-x --with-zlib --without-sound --without-all --host=asmjs-unknown-none --prefix=$(PWD)/asmjs-unknown-none/asmjs-unknown-none)
	touch $@

build/asmjs-cross/emacs.configure: src/emacs.dir build/asmjs-cross/emacs.dir | build/asmjs-cross/ncurses.make
	(cd src/emacs; autoreconf -ivf)
	cp config/config.sub src/emacs/build-aux
	(cd build/asmjs-cross/emacs; CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH ../../../src/emacs/configure --enable-optimize=$(OPT_ASMJS) --with-x-toolkit=no --without-x --with-zlib --without-sound --without-all --build=x86_64-pc-linux-gnu --host=asmjs-unknown-none --prefix=$(PWD)/asmjs-unknown-none/asmjs-unknown-none)
	touch $@

build/wasm32/emacs.configure: src/emacs.dir build/wasm32/emacs.dir | build/wasm32/ncurses.make
	(cd src/emacs; autoreconf -ivf)
	cp config/config.sub src/emacs/build-aux
	(cd build/wasm32/emacs; CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH ../../../src/emacs/configure --enable-optimize=$(OPT_ASMJS) --with-x-toolkit=no --without-x --with-zlib --without-sound --without-all --host=wasm32-unknown-none --prefix=$(PWD)/wasm32-unknown-none/wasm32-unknown-none)
	touch $@

build/asmjs/emacs.make: build/asmjs/emacs.configure build/asmjs/ncurses.make | build/binfmt_misc.install
	$(MKDIR) -p $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/arpa $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/netinet
	touch $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/arpa/inet.h
	touch $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/netdb.h
	touch $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/netinet/in.h
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/emacs
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/emacs install
	touch $@

build/asmjs-cross/emacs.make: build/asmjs-cross/emacs.configure build/asmjs-cross/ncurses.make | build/binfmt_misc.install
	$(MKDIR) -p $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/arpa $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/netinet
	touch $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/arpa/inet.h
	touch $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/netdb.h
	touch $(PWD)/asmjs-unknown-none/asmjs-unknown-none/include/netinet/in.h
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/emacs
	CC=asmjs-unknown-none-gcc PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/emacs install
	touch $@

build/wasm32/emacs.make: build/wasm32/emacs.configure build/wasm32/ncurses.make | build/binfmt_misc.install
	$(MKDIR) -p $(PWD)/wasm32-unknown-none/wasm32-unknown-none/include/arpa $(PWD)/wasm32-unknown-none/wasm32-unknown-none/include/netinet
	touch $(PWD)/wasm32-unknown-none/wasm32-unknown-none/include/arpa/inet.h
	touch $(PWD)/wasm32-unknown-none/wasm32-unknown-none/include/netdb.h
	touch $(PWD)/wasm32-unknown-none/wasm32-unknown-none/include/netinet/in.h
	CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/emacs
	CC=wasm32-unknown-none-gcc PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/emacs install
	touch $@

build/asmjs/bash.configure: src/bash.dir build/asmjs/bash.dir | build/asmjs/gcc-final.make
	(cd build/asmjs/bash; PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH ../../../src/bash/configure --host=asmjs-unknown-none --prefix=$(PWD)/asmjs-unknown-none/asmjs-unknown-none --disable-net-redirections --without-bash-malloc)
	touch $@

build/asmjs/bash.make: build/asmjs/bash.configure
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/bash
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/bash install
	touch $@

build/wasm32/bash.configure: src/bash.dir build/wasm32/bash.dir | build/wasm32/gcc-final.make
	(cd build/wasm32/bash; PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH ../../../src/bash/configure --host=wasm32-unknown-none --prefix=$(PWD)/wasm32-unknown-none/wasm32-unknown-none --disable-net-redirections --without-bash-malloc)
	touch $@

build/wasm32/bash.make: build/wasm32/bash.configure
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/bash
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/bash install
	touch $@

build/asmjs/perl.configure: src/perl.dir build/asmjs/perl.dir | build/asmjs/gcc-final.make
	test -f build/asmjs/perl/config.sh && mv build/asmjs/perl/config.sh build/asmjs/perl/config.sh.old || true
	touch build/asmjs/perl/config.sh
	(cd build/asmjs/perl; PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH sh ./Configure -der -Uusemymalloc -Dcc=asmjs-unknown-none-gcc -Doptimize="-O3 -fno-strict-aliasing" -Dincpth='$(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/include $(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/include-fixed $(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/../../../../asmjs-unknown-none/include' -Dlibpth='$(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/include-fixed $(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/../../../../asmjs-unknown-none/lib' -Dloclibpth=' ' -Dglibpth=' ' -Dplibpth=' ' -Dldflags=' ' -Uusedl -Dlibs='-lnsl -ldl -lm -lcrypt -lutil' -Dd_u32align=define -Dusedevel -Darchname='asmjs' -Dprefix='$(PWD)/asmjs-unknown-none/asmjs-unknown-none')
	touch $@

build/asmjs/perl.make: build/asmjs/perl.dir build/asmjs/perl.configure
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/perl
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/perl install
	touch $@

build/asmjs-cross/perl.configure: src/perl.dir build/asmjs-cross/perl.dir | build/asmjs/gcc-final.make
	test -f build/asmjs-cross/perl/config.sh && mv build/asmjs-cross/perl/config.sh build/asmjs-cross/perl/config.sh.old || true
	touch build/asmjs-cross/perl/config.sh
	(cd build/asmjs-cross/perl; PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH sh ./Configure -der -Dusecrosscompile -Dtargethost=127.0.1.1 -Dtargetrun='$(PWD)/bin/interpreter' -Dtargetuser=none -Dtargetport=none -Dtargetdir='$(PWD)/build/asmjs-cross/perl/targetdir' -Dtargetfrom=cp -Dtargetto=cp -Uusemymalloc -Dcc=asmjs-unknown-none-gcc -Doptimize="-O3 -fno-strict-aliasing" -Dincpth='$(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/include $(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/include-fixed $(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/../../../../asmjs-unknown-none/include' -Dlibpth='$(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/include-fixed $(PWD)/asmjs-unknown-none/lib/gcc/asmjs-unknown-none/8.0.0/../../../../asmjs-unknown-none/lib' -Dloclibpth=' ' -Dglibpth=' ' -Dplibpth=' ' -Dldflags=' ' -Uusedl -Dlibs='-lnsl -ldl -lm -lcrypt -lutil' -Dd_u32align=define -Dusedevel -Darchname='asmjs' -Dprefix='$(PWD)/asmjs-unknown-none/asmjs-unknown-none')
	touch $@

build/asmjs-cross/perl.make: build/asmjs-cross/perl.dir build/asmjs-cross/perl.configure
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs-cross/perl
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs-cross/perl install
	touch $@

build/wasm32/perl.configure: src/perl.dir build/wasm32/perl.dir | build/wasm32/gcc-final.make build/wasm32/libs.make
	test -f build/wasm32/perl/config.sh && mv build/wasm32/perl/config.sh build/wasm32/perl/config.sh.old || true
	touch build/wasm32/perl/config.sh
	(cd build/wasm32/perl; PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH sh ./Configure -der -Uversiononly -Uusemymalloc -Dcc=wasm32-unknown-none-gcc -Doptimize="-O3 -fno-strict-aliasing" -Dincpth='$(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/include $(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/include-fixed $(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/../../../../wasm32-unknown-none/include' -Dlibpth='$(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/include-fixed $(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/../../../../wasm32-unknown-none/lib' -Dcccdlflags='-fPIC -Wl,--shared -shared' -Dlddlflags='-Wl,--shared -shared' -Dccdlflags='-Wl,-E'  -Dloclibpth=' ' -Dglibpth=' ' -Dplibpth=' ' -Dusedl -Dlibs='-lnsl -ldl -lm -lcrypt -lutil' -Dd_u32align=define -Dusedevel -Darchname='wasm32' -Dprefix='$(PWD)/wasm32-unknown-none/wasm32-unknown-none')
	touch $@

build/wasm32/perl.make: build/wasm32/perl.dir build/wasm32/perl.configure
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/perl
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/perl install
	touch $@

build/wasm32-cross/perl.configure: src/perl.dir build/wasm32-cross/perl.dir | build/wasm32/gcc-final.make
	test -f build/wasm32-cross/perl/config.sh && mv build/wasm32-cross/perl/config.sh build/wasm32-cross/perl/config.sh.old || true
	touch build/wasm32-cross/perl/config.sh
	(cd build/wasm32-cross/perl; PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH sh ./Configure -der -Dusecrosscompile -Dtargethost=127.0.1.1 -Dtargetrun='$(PWD)/bin/interpreter' -Dtargetuser=none -Dtargetport=none -Dtargetdir='$(PWD)/build/wasm32-cross/perl/targetdir' -Dtargetfrom=cp -Dtargetto=cp -Uusemymalloc -Dcc=wasm32-unknown-none-gcc -Doptimize="-O3 -fno-strict-aliasing" -Dincpth='$(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/include $(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/include-fixed $(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/../../../../wasm32-unknown-none/include' -Dlibpth='$(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/include-fixed $(PWD)/wasm32-unknown-none/lib/gcc/wasm32-unknown-none/8.0.0/../../../../wasm32-unknown-none/lib' -Dloclibpth=' ' -Dglibpth=' ' -Dplibpth=' ' -Dldflags=' ' -Uusedl -Dlibs='-lnsl -ldl -lm -lcrypt -lutil' -Dd_u32align=define -Dusedevel -Darchname='wasm32' -Dprefix='$(PWD)/wasm32-unknown-none/wasm32-unknown-none')
	touch $@

build/wasm32-cross/perl.make: build/wasm32-cross/perl.dir build/wasm32-cross/perl.configure
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32-cross/perl
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32-cross/perl install
	touch $@

build/common/wabt.cmake: src/wabt.dir build/common/wabt.dir
	(cd build/common/wabt; cmake ../../../src/wabt -DBUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=$(PWD)/common)
	touch $@

build/common/wabt.make: build/common/wabt.cmake
	$(MAKE) -C build/common/wabt
	$(MAKE) -C build/common/wabt install
	touch $@

build/common/spidermonkey.configure: src/spidermonkey.dir build/common/spidermonkey.dir
	(cd src/spidermonkey/js/src; autoconf2.13)
	(cd build/common/spidermonkey; ../../../src/spidermonkey/js/src/configure --enable-optimize=$(OPT_NATIVE) --disable-debug --disable-tests --prefix=$(PWD)/common/spidermonkey --without-system-zlib)
	touch $@

build/common/spidermonkey.make: build/common/spidermonkey.configure
	$(MAKE) -C build/common/spidermonkey
	$(MAKE) -C build/common/spidermonkey install
	test -L $(PWD)/common/bin/js || ($(MKDIR) -p $(PWD)/common/bin; ln -sf ../spidermonkey/bin/js57 $(PWD)/common/bin/js)
	touch $@

build/common3/spidermonkey.configure: src/spidermonkey.dir build/common3/spidermonkey.dir
	(cd src/spidermonkey/js/src; autoconf2.13)
	(cd build/common3/spidermonkey; ../../../src/spidermonkey/js/src/configure --enable-optimize="-O3" --disable-debug --disable-tests --prefix=$(PWD)/common3/spidermonkey --without-system-zlib)
	touch $@

build/common3x/spidermonkey.configure: src/spidermonkey.dir build/common3x/spidermonkey.dir
	(cd src/spidermonkey/js/src; autoconf2.13)
	(cd build/common3x/spidermonkey; ../../../src/spidermonkey/js/src/configure --enable-optimize="-O3" --disable-debug --disable-tests --prefix=$(PWD)/common3x/spidermonkey --without-system-zlib)
	touch $@

build/common3/spidermonkey.make: build/common3/spidermonkey.configure
	$(MAKE) -C build/common3/spidermonkey
	$(MAKE) -C build/common3/spidermonkey install
	test -L $(PWD)/common3/bin/js || ($(MKDIR) -p $(PWD)/common3/bin; ln -sf ../spidermonkey/bin/js57 $(PWD)/common3/bin/js)
	touch $@

build/common3x/spidermonkey.make: build/common3x/spidermonkey.configure
	$(MAKE) -C build/common3x/spidermonkey
	$(MAKE) -C build/common3x/spidermonkey install
	test -L $(PWD)/common3x/bin/js || ($(MKDIR) -p $(PWD)/common3x/bin; ln -sf ../spidermonkey/bin/js57 $(PWD)/common3x/bin/js)
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
	(cd build/asmjs/coreutils; PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH ../../../src/coreutils/configure --host=asmjs-unknown-none --prefix=$(PWD)/asmjs-unknown-none/asmjs-unknown-none --enable-static --disable-shared)
	touch $@

build/asmjs/coreutils.make: build/asmjs/coreutils.configure
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/coreutils
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/coreutils install
	touch $@

build/wasm32/coreutils.configure: src/coreutils.dir build/wasm32/coreutils.dir | build/wasm32/gcc-final.make
	(cd src/coreutils; ./bootstrap --gnulib-srcdir=gnulib --skip-po)
	(cd build/wasm32/coreutils; PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH ../../../src/coreutils/configure --host=wasm32-unknown-none --prefix=$(PWD)/wasm32-unknown-none/wasm32-unknown-none)
	touch $@

build/wasm32/coreutils.make: build/wasm32/coreutils.configure
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/coreutils
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/coreutils install
	touch $@

build/asmjs/graphviz.configure: src/graphviz.dir build/asmjs/graphviz.dir | build/asmjs/gcc-final.make
	(cd src/graphviz; sh autogen.sh NOCONFIG)
	cp config/config.sub src/graphviz/config/config.sub
	(cd build/asmjs/graphviz; PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH ../../../src/graphviz/configure --host=asmjs-unknown-none --prefix=$(PWD)/asmjs-unknown-none/asmjs-unknown-none --without-pangocairo --without-gdk --without-gdk-pixbuf --without-gtk --without-qt --enable-static --disable-shared --disable-ltdl)
	touch $@

build/asmjs/graphviz.make: build/asmjs/graphviz.configure
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/graphviz
	PATH=$(PWD)/asmjs-unknown-none/bin:$$PATH $(MAKE) -C build/asmjs/graphviz install
	touch $@

build/wasm32/graphviz.configure: src/graphviz.dir build/wasm32/graphviz.dir | build/wasm32/gcc-final.make
	(cd src/graphviz; sh autogen.sh NOCONFIG)
	cp config/config.sub src/graphviz/config/config.sub
	(cd build/wasm32/graphviz; PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH ../../../src/graphviz/configure --host=wasm32-unknown-none --prefix=$(PWD)/wasm32-unknown-none/wasm32-unknown-none --without-pangocairo --without-gdk --without-gdk-pixbuf --without-gtk --without-qt --enable-static --disable-shared --disable-ltdl)
	touch $@

build/wasm32/graphviz.make: build/wasm32/graphviz.configure
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/graphviz
	PATH=$(PWD)/wasm32-unknown-none/bin:$$PATH $(MAKE) -C build/wasm32/graphviz install
	touch $@

build/binfmt_misc.install: /proc/sys/fs/binfmt_misc
	sudo ./binfmt_misc/binfmt_misc $(PWD)/bin/interpreter || true
	sudo ./binfmt_misc/binfmt_misc-wasm $(PWD)/bin/interpreter-wasm || true
	sudo ./binfmt_misc/binfmt_misc-wasm32 $(PWD)/bin/interpreter-wasm32 || true
	sudo ./binfmt_misc/binfmt_misc-wasm64 $(PWD)/bin/interpreter-wasm64 || true
	touch $@

build/binfmt_misc-caching.install: /proc/sys/fs/binfmt_misc
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

src/musl.dir: src/.dir
	test -L src/musl || ln -sf ../subrepos/musl src/musl
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

src/wabt.dir: src/.dir
	test -d src/wabt || mkdir src/wabt
	(cd subrepos/wabt; tar c --exclude .git .) | (cd src/wabt; tar x)
	touch $@

src/perl.dir: src/.dir
	test -d src/perl || mkdir src/perl
	(cd subrepos/perl; tar c --exclude .git .) | (cd src/perl; tar x)
	touch $@

bin/hexify: hexify/hexify.c
	$(CC) $< -o $@

lib/asmjs.o: lib/asmjs.S build/asmjs/gcc-final.make
	asmjs-unknown-none/bin/asmjs-unknown-none-gcc -c $< -o $@

js/.dir:
	test -d js || mkdir js
	touch $@

js/asmjs-%.jsc.js: jsc/asmjs-%.jsc js/.dir build/asmjs/gcc-final.make
	test -d cache || mkdir cache
	perl ./bin/interpolate asmjs-unknown-none < $< > $@

js/asmjs-%.jsc.js: jsc/asm-%.jsc js/.dir build/asmjs/gcc-final.make
	test -d cache || mkdir cache
	perl ./bin/interpolate asmjs-unknown-none < $< > $@

js/wasm32-%.jsc.js: jsc/wasm32-%.jsc js/.dir
	test -d cache || mkdir cache
	perl ./bin/interpolate asmjs-unknown-none < $< > $@

js/wasm32-%.jsc.js: jsc/asm-%.jsc js/.dir
	test -d cache || mkdir cache
	perl ./bin/interpolate asmjs-unknown-none < $< > $@

js/asmjs.js: js/asmjs-main.jsc.js js/asmjs-system.jsc.js js/asmjs-thinthin.jsc.js js/asmjs-thinthin-jsexport.jsc.js js/asmjs-vt100.jsc.js build/asmjs/gcc-final.make
	echo "// autogenerated, do not edit" > $@.new
	cat js/asmjs-system.jsc.js js/asmjs-thinthin.jsc.js js/asmjs-thinthin-jsexport.jsc.js js/asmjs-vt100.jsc.js js/asmjs-main.jsc.js >> $@.new
	mv $@.new $@

js/wasm32.js: js/wasm32-main.jsc.js js/wasm32-range.jsc.js js/wasm32-system.jsc.js js/wasm32-thinthin.jsc.js js/wasm32-vt100.jsc.js js/wasm32-boot.jsc.js build/wasm32/gcc-final.make
	echo "// autogenerated, do not edit" > $@.new
	cat js/wasm32-range.jsc.js js/wasm32-system.jsc.js js/wasm32-thinthin.jsc.js js/wasm32-vt100.jsc.js js/wasm32-main.jsc.js js/wasm32-boot.jsc.js >> $@.new
	mv $@.new $@

js/wasm32-worker.js: js/wasm32-main.jsc.js js/wasm32-range.jsc.js js/wasm32-system.jsc.js js/wasm32-thinthin.jsc.js js/wasm32-vt100.jsc.js js/wasm32-worker.jsc.js build/wasm32/gcc-final.make
	echo "// autogenerated, do not edit" > $@.new
	cat js/wasm32-range.jsc.js js/wasm32-system.jsc.js js/wasm32-thinthin.jsc.js js/wasm32-vt100.jsc.js js/wasm32-main.jsc.js js/wasm32-worker.jsc.js >> $@.new
	mv $@.new $@

js/wasm32-forkedworker.js: js/wasm32-main.jsc.js js/wasm32-range.jsc.js js/wasm32-system.jsc.js js/wasm32-thinthin.jsc.js js/wasm32-vt100.jsc.js js/wasm32-forkedworker.jsc.js build/wasm32/gcc-final.make
	echo "// autogenerated, do not edit" > $@.new
	cat js/wasm32-range.jsc.js js/wasm32-system.jsc.js js/wasm32-thinthin.jsc.js js/wasm32-vt100.jsc.js js/wasm32-main.jsc.js js/wasm32-forkedworker.jsc.js >> $@.new
	mv $@.new $@

cache/interpolate-cache.pl: bootstrap/interpolate-cache.pl
	test -d cache || mkdir cache
	cp $< $@

clean:
	rm -rf asmjs-unknown-none build src js bin/hexify # cache

tests/%.c.s: tests/%.c build/gcc-final.make
	./asmjs-unknown-none/bin/asmjs-unknown-none-gcc -S $< -o $@

tests/%.cpp.s: tests/%.cpp build/gcc-final.make
	./asmjs-unknown-none/bin/asmjs-unknown-none-g++ -S $< -o $@

tests/%.s.o: tests/%.s build/gcc-final.make
	./asmjs-unknown-none/bin/asmjs-unknown-none-gcc -c $< -o $@

tests/%.o.exe: tests/%.o build/gcc-final.make
	./asmjs-unknown-none/bin/asmjs-unknown-none-gcc $< -o $@

tests/%.exe.js: tests/%.exe build/gcc-final.make
	./bin/prepare $< > $@

intermediate/dot: asmjs-unknown-none/asmjs-unknown-none/bin/dot_static lib/mfinfo.o lib/loop.o | build/graphviz.make
	./bin/jsexport $< intermediate/dot-export
	./bin/multifile-add1 intermediate/dot-export lib/mfinfo.o intermediate/dot-export-mfinfo
	./bin/multifile-add1 intermediate/dot-export-mfinfo lib/loop.o $@

lib/%.o: lib/%.c
	asmjs-unknown-none-gcc -c -o $@ $<

lib/%.o: lib/%.cc
	asmjs-unknown-none-g++ -c -o $@ $<

examples/002-perl/perl.js: asmjs-unknown-none/asmjs-unknown-none/bin/perl5.25.7 bin/prepare js/asmjs.js
	./bin/prepare $< > $@

%.cpp-lds.lds: %.cpp-lds
	cpp < $< | egrep -v '^#' > $@

lib/wasm32-headers.o: headers/wasm32-headers.s build/wasm32/gcc-final.make
	./wasm32-unknown-none/bin/wasm32-unknown-none-gcc -c $< -o $@

lib/wasm32-globals.o: headers/wasm32-globals.s build/wasm32/gcc-preliminary.make
	./wasm32-unknown-none/bin/wasm32-unknown-none-gcc -c $< -o $@

bin/wasmrewrite: wasmrewrite/wasmrewrite.c
	gcc -g3 $< -o $@

bin/wasmsect: wasmrewrite/wasmsect.c
	gcc -g3 $< -o $@

.PHONY: FORCE clean fetch

update-mozilla:
	diff -ur src/spidermonkey subrepos/mozilla -x '*.in' -x '*.m4' | (cd src/spidermonkey; patch -p 2)
	false

update-binutils-gdb:
	diff -ur src/binutils-gdb subrepos/binutils-gdb -x '*.in' -x '*.m4' | (cd src/binutils-gdb; patch -p 2)
	false

update-gcc:
	diff -ur src/gcc-preliminary subrepos/gcc -x '*.in' -x '*.m4' | (cd src/gcc-preliminary; patch -p 2)
	diff -ur src/gcc-final subrepos/gcc -x '*.in' -x '*.m4' | (cd src/gcc-final; patch -p 2)
	false

update-wabt:
	diff -ur src/wabt subrepos/wabt -x 'Makefile' | (cd src/wabt; patch -p 2)
	false

# build/wasm64/.dir: build/.dir
# 	test -d build/wasm64 || $(MKDIR) build/wasm64
# 	touch $@

# build/wasm64/binutils-gdb.dir: build/wasm64/.dir
# 	test -d build/wasm64/binutils-gdb || $(MKDIR) build/wasm64/binutils-gdb
# 	touch $@

# build/wasm64/gcc-preliminary.dir: build/wasm64/.dir
# 	test -d build/wasm64/gcc-preliminary || $(MKDIR) build/wasm64/gcc-preliminary
# 	touch $@

# build/wasm64/glibc.dir: build/wasm64/.dir
# 	test -d build/wasm64/glibc || $(MKDIR) build/wasm64/glibc
# 	touch $@

# build/wasm64/gcc-final.dir: build/wasm64/.dir
# 	test -d build/wasm64/gcc-final || $(MKDIR) build/wasm64/gcc-final
# 	touch $@

# build/wasm64/binutils-gdb.configure: src/binutils-gdb.dir build/wasm64/binutils-gdb.dir
# 	(cd src/binutils-gdb/gas; aclocal-1.11; automake-1.11)
# 	(cd build/wasm64/binutils-gdb; ../../../src/binutils-gdb/configure --target=wasm64-virtual-wasm64 --prefix=$(PWD)/wasm64-virtual-wasm64 CFLAGS="-g -O0")
# 	touch $@

# build/wasm64/binutils-gdb.make: build/wasm64/binutils-gdb.dir build/wasm64/binutils-gdb.configure
# 	$(MAKE) -C build/wasm64/binutils-gdb
# 	$(MAKE) -C build/wasm64/binutils-gdb install
# 	touch $@

# build/wasm64/gcc-preliminary.configure: src/gcc-preliminary.dir build/wasm64/gcc-preliminary.dir | build/wasm64/binutils-gdb.make
# 	(cd build/wasm64/gcc-preliminary; ../../../src/gcc-preliminary/configure --enable-optimize=$(OPT_NATIVE) --target=wasm64-virtual-wasm64 --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --enable-languages=c --disable-libssp --prefix=$(PWD)/wasm64-virtual-wasm64)
# 	touch $@

# test -L asmjs-unknown-none/asmjs-unknown-none || ln -sf . asmjs-unknown-none/asmjs-unknown-none

# build/wasm64/gcc-preliminary.make: build/wasm64/gcc-preliminary.dir build/wasm64/gcc-preliminary.configure
# 	$(MAKE) -C build/wasm64/gcc-preliminary
# 	$(MAKE) -C build/wasm64/gcc-preliminary install
# 	cp wasm64-virtual-wasm64/lib/gcc/wasm64-virtual-wasm64/8.0.0/libgcc.a wasm64-virtual-wasm64/lib/gcc/wasm64-virtual-wasm64/8.0.0/libgcc_eh.a
# 	cp wasm64-virtual-wasm64/lib/gcc/wasm64-virtual-wasm64/8.0.0/libgcc.a wasm64-virtual-wasm64/lib/gcc/wasm64-virtual-wasm64/8.0.0/libgcc_s.a
# 	touch $@

# build/wasm64/glibc.configure: src/glibc.dir build/wasm64/glibc.dir | build/wasm64/gcc-preliminary.make
# 	(cd build/wasm64/glibc; CC=wasm64-virtual-wasm64-gcc PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH ../../../src/glibc/configure --enable-optimize=$(OPT_NATIVE) --host=wasm64-virtual-wasm64 --target=wasm64-virtual-wasm64 --enable-hacker-mode --enable-static --enable-static-nss --disable-shared --prefix=$(PWD)/wasm64-virtual-wasm64/wasm64-virtual-wasm64)
# 	touch $@

# build/wasm64/glibc.make: build/wasm64/glibc.dir build/wasm64/glibc.configure
# 	CC=wasm64-virtual-wasm64-gcc PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH $(MAKE) -C build/wasm64/glibc
# 	CC=wasm64-virtual-wasm64-gcc PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH $(MAKE) -C build/wasm64/glibc install
# 	touch $@

# build/wasm64/gcc-final.configure: src/gcc-final.dir build/wasm64/gcc-final.dir | build/wasm64/glibc.make
# 	(cd build/wasm64/gcc-final; ../../../src/gcc-final/configure --enable-optimize=$(OPT_NATIVE) --target=wasm64-virtual-wasm64 --disable-libatomic --disable-libgomp --disable-libquadmath --enable-explicit-exception-frame-registration --disable-libssp --prefix=$(PWD)/wasm64-virtual-wasm64)
# 	touch $@

# build/wasm64/gcc-final.make: build/wasm64/gcc-final.dir build/wasm64/gcc-final.configure
# 	test -d build/wasm64/gcc-final/gcc || $(MKDIR) build/wasm64/gcc-final/gcc
# 	cp build/wasm64/gcc-preliminary/gcc/libgcc.a build/wasm64/gcc-final/gcc/libgcc_eh.a
# 	cp build/wasm64/gcc-preliminary/gcc/libgcc.a build/wasm64/gcc-final/gcc/libgcc_s.a
# 	PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH $(MAKE) -C build/wasm64/gcc-final
# 	cp build/wasm64/gcc-final/gcc/libgcc.a build/wasm64/gcc-final/gcc/libgcc_eh.a
# 	cp build/wasm64/gcc-final/gcc/libgcc.a build/wasm64/gcc-final/gcc/libgcc_s.a
# 	PATH=$(PWD)/wasm64-virtual-wasm64/bin:$$PATH $(MAKE) -C build/wasm64/gcc-final install
# 	touch $@

# js/wasm64-%.jsc.js: jsc/wasm64-%.jsc js/.dir
# 	test -d cache || mkdir cache
# 	perl ./bin/interpolate wasm64-virtual-wasm64 < $< > $@

# js/wasm64-%.jsc.js: jsc/asm-%.jsc js/.dir
# 	test -d cache || mkdir cache
# 	perl ./bin/interpolate wasm64-virtual-wasm64 < $< > $@

# js/wasm64.js: js/wasm64-main.jsc.js js/wasm64-system.jsc.js js/wasm64-thinthin.jsc.js js/wasm64-vt100.jsc.js build/wasm64/gcc-final.make
# 	echo "// autogenerated, do not edit" > $@.new
# 	cat js/wasm64-system.jsc.js js/wasm64-thinthin.jsc.js js/wasm64-vt100.jsc.js js/wasm64-main.jsc.js >> $@.new
# 	mv $@.new $@
