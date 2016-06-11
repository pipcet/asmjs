asmjs-virtual-asmjs-gcc -c data.S
asmjs-virtual-asmjs-ld -T multifile-0.lds data.o -o multifile1a.o
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile1a.o multifile1.o
asmjs-virtual-asmjs-ld -T multifile.lds multifile1.o data.o -o multifile2a.o
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile2a.o multifile2.o
asmjs-virtual-asmjs-ld -T multifile.lds multifile2.o data.o -o multifile3a.o
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile3a.o multifile3.o
asmjs-virtual-asmjs-ld -T multifile.lds multifile3.o data.o -o multifile4a.o
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile4a.o multifile4.o
asmjs-virtual-asmjs-ld -T multifile.lds multifile4.o data.o -o multifile5a.o
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile5a.o multifile5.o
asmjs-virtual-asmjs-ld -T multifile.lds multifile5.o data.o -o multifile6a.o
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile6a.o multifile6.o
asmjs-virtual-asmjs-ld -T multifile.lds multifile6.o data.o -o multifile7a.o
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile7a.o multifile7.o
