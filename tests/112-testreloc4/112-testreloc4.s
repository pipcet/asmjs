        .reloc .+2,R_ASMJS_HEX16R4,b-a
        .ascii "0x0000000000000000"
        .ascii "HERE HERE HERE"
a:
        .long   0xdeadbeef
        .long   0xdeadbeef
        .long   0xdeadbeef
        .long   0xdeadbeef
b:
        .globl main
main:   
        
