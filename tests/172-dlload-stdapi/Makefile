001-main: 001-main.c
	wasm32-virtual-wasm32-gcc -o $@ $^

003-f.so: 003-f.c 002-x.so
	wasm32-virtual-wasm32-gcc -fPIC -Wl,--shared --shared -o $@ $^
	../../bin/wasmify-wasm32 $@ > 003-f.wasm

002-x.so: 002-x.c
	wasm32-virtual-wasm32-gcc -fPIC -Wl,--shared --shared -o $@ $^
	../../bin/wasmify-wasm32 $@ > 002-x.wasm
