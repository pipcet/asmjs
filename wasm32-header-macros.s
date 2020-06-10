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
