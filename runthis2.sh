./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-gcc ./tests/004-hello-world-infloop-count.c
./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm.lds --no-check-sections a.out -o d.out
./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm2.lds --no-check-sections d.out -o b.out
# ./wasmrewrite2 b.out > c.out
./wasmrewrite3 b.out > c.out
cp c.out wasm-experimentation/wasm.wasm
wasm64-virtual-wasm64-objcopy --dump-section .data=wasm-experimentation/wasm.data a.out
(cd wasm-experimentation/; JIT_OPTION_wasmTestMode=true ../common/bin/js ./wasm64lib.js)
