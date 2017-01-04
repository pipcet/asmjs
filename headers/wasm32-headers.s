        .include "wasm32-macros.s"
        .macro section_id name id
        .pushsection .wasm.header_id.\name
        rleb128_32 \id
        .popsection
        .pushsection .wasm.header.\name
        .popsection
        .pushsection .wasm.chars.\name
        __wasm_chars_\name\():
        .endm

        .macro section name
        .pushsection .wasm.header_id.\name
        .byte 0
        .popsection
        .pushsection .wasm.header.\name
        rleb128_32 __wasm_\name\()_id_end - __wasm_\name\()_id
__wasm_\name\()_id:
        .ascii "\name"
__wasm_\name\()_id_end:
        .popsection

        .pushsection .wasm.chars.\name
__wasm_chars_\name\():
        .endm

        section_id type 1
        section_id import 2
        section_id function 3
        section_id table 4
        section_id memory 5
        section_id global 6
        section_id export 7
        section_id start 8
        section_id element 9
        section_id code 10
        section_id data 11
        section name

        .pushsection .wasm.chars.table
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.table
        .byte 0x70                         ; anyfunc
        .byte 0x1                          ; maximum field present
        rleb128_32 1024
        rleb128_32 65536
        .popsection

        .pushsection .wasm.chars.import
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.import
        lstring "sys"
        lstring "got"
        .byte 3                 ; global
        .byte 0x7f              ; i32
        .byte 0                 ; immutable
        .popsection

        .pushsection .wasm.chars.import
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.import
        lstring "sys"
        lstring "plt"
        .byte 3                 ; global
        .byte 0x7f              ; i32
        .byte 0                 ; immutable
        .popsection

        .pushsection .wasm.chars.import
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.import
        lstring "sys"
        lstring "gpo"
        .byte 3                 ; global
        .byte 0x7f              ; i32
        .byte 0                 ; immutable
        .popsection

        .pushsection .wasm.chars.import
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.import
        lstring "sys"
        lstring "table"
        .byte 1                 ; table
        .byte 0x70
        .byte 1                 ; maximum present
        rleb128_32 65536        ; initial size
        rleb128_32 65536        ; maximum size
        .popsection

        .pushsection .wasm.chars.import
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.import
        lstring "sys"
        lstring "memory"
        .byte 2                 ; memory
        .byte 1                 ; maximum present
        rleb128_32 16384       ; initial size
        rleb128_32 16384       ; maximum size
        .popsection
