# cpp < wasm-experimentation/wasm.cpp-lds | egrep -v '^#' > wasm-experimentation/wasm.lds
# ./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-gcc -c ./wasm-experimentation/wasm-headers.s
# ./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-gcc -c ./wasm-experimentation/wasm-test.s
# ./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm.lds wasm-headers.o wasm-test.o
# ./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm2.lds a.out -o b.out
# cat b.out

# ./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-gcc -O6 -c ./tests/138-countloop.c 
# cpp < wasm-experimentation/wasm.cpp-lds | egrep -v '^#' > wasm-experimentation/wasm.lds
# ./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-gcc -c ./wasm-experimentation/wasm-headers.s
# ./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm.lds wasm-headers.o 138-countloop.o
# ./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm2.lds a.out -o b.out
# cat b.out

./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-gcc -O6 -c ./tests/149-printloop.c
cpp < wasm-experimentation/wasm.cpp-lds | egrep -v '^#' > wasm-experimentation/wasm.lds
./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-gcc -c ./wasm-experimentation/wasm-headers.s
./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm.lds wasm-headers.o 149-printloop.o
./wasm64-virtual-wasm64/bin/wasm64-virtual-wasm64-ld -T wasm-experimentation/wasm2.lds a.out -o b.out
cat b.out
