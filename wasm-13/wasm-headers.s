        .include "wasm-macros.s"
        .macro section_id name id
        .pushsection .wasm.header_id.\name
        rleb128 \id
        .popsection
        .pushsection .wasm.header.\name
        .popsection
        .pushsection .wasm.chars.\name
        __wasm_chars_\name\():
        .endm

        .macro section name
        .pushsection .wasm.header_id.\name
        rleb128 0
        .popsection
        .pushsection .wasm.header.\name
        rleb128 __wasm_\name\()_id_end - __wasm_\name\()_id
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
        rleb128 1                          ; __wasm_chars_function_size
        rleb128 1024
        .popsection

        .pushsection .wasm.chars.memory
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.memory
        .byte 0x1               ; maximum field present
        rleb128 1024            ; 64 MiB
        rleb128 1024            ; 64 MiB
        .popsection

        .if 0
        .pushsection .wasm.chars.export
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.export
        lstring "_start"
        .byte 0x00              ; external kind function
                                ;rleb128 _start
        .byte 0x02
        .popsection
        .endif
        
        .pushsection .wasm.chars.export
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.export
        lstring "_memory"
        .byte 0x02              ; external kind memory
                                ;rleb128 _start
        .byte 0x00
        .popsection
