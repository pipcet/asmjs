asmjs-virtual-asmjs-gcc -c data.S
asmjs-virtual-asmjs-ld -T multifile-0.lds data.o -o multifile1a.o
asmjs-virtual-asmjs-objcopy --prefix-sections prev_ -N __data_start -N __data_end multifile1a.o multifile1.o
asmjs-virtual-asmjs-ld -T multifile.lds multifile1.o data.o -o multifile2a.o
asmjs-virtual-asmjs-objcopy --prefix-sections prev_ -N __data_start -N __data_end multifile2a.o multifile2.o
asmjs-virtual-asmjs-ld -T multifile.lds multifile2.o data.o -o multifile3a.o
asmjs-virtual-asmjs-objcopy --prefix-sections prev_ -N __data_start -N __data_end multifile3a.o multifile3.o
