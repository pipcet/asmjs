        .include "wasm32-macros.s"
        .macro section_id name id
        .pushsection .wasm.header_id.\name
__wasm_header_id_\name:
        rleb128_32 \id
        .popsection
        .pushsection .wasm.header.\name
	.reloc .,R_WASM32_CODE_POINTER,__wasm_header_id_\name
        .popsection
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

        .pushsection .space.table
        .byte 0x00
        .popsection
        .pushsection .wasm.table
        .byte 0x70                         ; anyfunc
        .byte 0x1                          ; maximum field present
        rleb128_32 1024
        rleb128_32 65536
        .popsection

	import_global $got, sys, got, 0
	import_global $plt, sys, plt, 0
	import_global $gpo, sys, gpo, 0

        .pushsection .space.import
        .reloc .,R_WASM32_CODE_POINTER,0f
        .byte 0x00
        .popsection
        .pushsection .wasm.import
0:      lstring "sys"
        lstring "table"
        .byte 1                 ; table
        .byte 0x70		; funcref
        .byte 1                 ; maximum present
        rleb128_32 65536        ; initial size
        rleb128_32 65536        ; maximum size
        .popsection

        .pushsection .space.import
        .reloc .,R_WASM32_CODE_POINTER,0f
        .byte 0x00
        .popsection
        .pushsection .wasm.import
0:      lstring "sys"
        lstring "memory"
        .byte 2                 ; memory
        .byte 1                 ; maximum present
        rleb128_32 1       ; initial size
        rleb128_32 64 * 1024 - 1
        .popsection
