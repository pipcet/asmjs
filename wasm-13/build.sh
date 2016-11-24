export PATH=/home/pip/git/asmjs/wasm32-virtual-wasm32/bin:$PATH
make wasm-13/wasm.cpp-lds.lds
make js/wasm32.js
cd wasm-13
../wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-gcc -S -nostdlib 143-syscall.c ../wasm32-virtual-wasm32/lib/gcc/wasm32-virtual-wasm32/7.0.0/libgcc.a
../wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-gcc -c -nostdlib 143-syscall.s ../wasm32-virtual-wasm32/lib/gcc/wasm32-virtual-wasm32/7.0.0/libgcc.a
../wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-gcc -c ./wasm-headers.s
# ../wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-as -c ./wasm.S
../wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-ld -T wasm.cpp-lds.lds ./143-syscall.o ../wasm32-virtual-wasm32/lib/gcc/wasm32-virtual-wasm32/7.0.0/libgcc.a -o b.out
../wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-ld -T wasm2.lds ./b.out -o c.out
gcc -g ./wasmrewrite.c -o wasmrewrite
od -tx1 c.out
./wasmrewrite c.out > d.out
od -tx1 d.out
cp d.out wasm.wasm
../subrepos/binaryen/bin/wasm-dis d.out
#../common3/bin/js --execute='WebAssembly.instantiate(os.file.readFile("d.out", "binary"), { sys: { call: function (a,b,c,d,e,f) { console.log(`${a} ${b} ${c} ${d} ${e} ${f}`); return 42; }} }).catch(error => console.log(error)).then(success => { console.log("success: " + success); for (let o in success.instance.exports) console.log(o); console.log(success.instance.exports.main(0, 64*65536, 0, 0, 0, 0)) });'
../common3/bin/js ./wasm.js
sleep 10
