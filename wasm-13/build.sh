export PATH=/home/pip/git/asmjs/wasm64-virtual-wasm64/bin:$PATH
make wasm-13/wasm.cpp-lds.lds
cd wasm-13
../wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-as -c ./wasm-headers.s
mv a.out wasm-headers.o
../wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-as -c ./wasm.S
../wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm.cpp-lds.lds ./a.out -o b.out
../wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm2.lds ./b.out -o c.out
gcc -g ./wasmrewrite.c -o wasmrewrite
od -tx1 c.out
./wasmrewrite c.out > d.out
od -tx1 d.out
../common3/bin/js --execute='WebAssembly.instantiate(os.file.readFile("d.out", "binary"), { sys: { call: function (a,b,c,d,e,f) { console.log(`${a} ${b} ${c} ${d} ${e} ${f}`); return 42; }} }).catch(error => console.log(error)).then(success => { console.log("success: " + success); for (let o in success.instance.exports) console.log(o); console.log(success.instance.exports._start()) });'
sleep 10
