        .section .space.code
        .byte 0
        .byte 0
        .byte 0
.end.space.code:
        .section .wasm.code.0,"x"
        .string "hello"
.end.wasm.code.0:
        .section .wasm.code.1,"x"
        .string "there"
.end.wasm.code.1:
        .section .wasm.code.2,"x"
        .string "world"
.end.wasm.code.2:
        .section .wasm.code
        .rept .end.space.code - .space.code
        
