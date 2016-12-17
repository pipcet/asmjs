libdl.so: libdl.c
	wasm32-virtual-wasm32-gcc -fPIC -Wl,--shared --shared -o $@ $<
	../bin/wasmify-wasm32 $@ > libdl.wasm

