./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-gcc -nostdlib  ./tests/149-printloop.c -lgcc
./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm.lds a.out -o d.out
./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm2.lds d.out -o b.out
./wasmrewrite2 b.out > c.out
cp c.out wasm-experimentation/wasm.wasm
(cd wasm-experimentation/; JIT_OPTION_wasmTestMode=true ../common/bin/js ./wasm64lib.js)
