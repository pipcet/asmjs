libdl.so: libdl.c
	wasm32-unknown-none-gcc -fPIC -Wl,--shared --shared -o $@ $<
	../bin/wasmify-wasm32 $@ > libdl.wasm

