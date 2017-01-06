rm -rf build/wasm64/gcc-preliminary/wasm64-virtual-wasm64/ &&
rm -rf build/wasm64/gcc-preliminary.make &&
make -kj6 build/wasm64/gcc-preliminary.make &&
bash -x ./wasm-experimentation/as-to-wasm.bash &&
./subrepos/binaryen/bin/wasm-dis ./b.out && 
gcc wasmrewrite2.c -o wasmrewrite2 &&
./wasmrewrite2 < b.out > c.out &&
cp c.out wasm-experimentation/wasm.wasm 
