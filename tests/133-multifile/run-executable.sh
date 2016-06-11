asmjs-virtual-asmjs-gcc -c data.S
asmjs-virtual-asmjs-ld -T multifile-0.lds data.o -o multifile1a
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile1a multifile1
asmjs-virtual-asmjs-ld -T multifile.lds multifile1 data.o -o multifile2a
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile2a multifile2
asmjs-virtual-asmjs-ld -T multifile.lds multifile2 data.o -o multifile3a
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile3a multifile3
asmjs-virtual-asmjs-ld -T multifile.lds multifile3 data.o -o multifile4a
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile4a multifile4
asmjs-virtual-asmjs-ld -T multifile.lds multifile4 data.o -o multifile5a
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile5a multifile5
asmjs-virtual-asmjs-ld -T multifile.lds multifile5 data.o -o multifile6a
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile6a multifile6
asmjs-virtual-asmjs-ld -T multifile.lds multifile6 data.o -o multifile7a
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end multifile7a multifile7
