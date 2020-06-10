        .macro magic_number
        .byte 0
        .ascii "asm"
        .endm

        .macro file_header
        magic_number
        .long 1
        .endm

        .macro func_type signature
        .pushsection .space.type
        .byte 0
        .popsection
        .pushsection .wasm.type
        signature \signature
        .popsectino
        .endm

        .macro import_entry module field kind
        .pushsection .space.import
        .byte 0
        .popsection
        lstring \module
        lstring \field
        .ifeqs \kind,"function"
        .byte 0
        .endif
        .ifeqs \kind,"table"
        .byte 0
        .endif
        .ifeqs \kind,"memory"
        .byte 0
        .endif
        .ifeqs \kind,"global"
        .byte 0
        .endif
        .endm

        .macro import_function module field type
        .pushsection .wasm.import
        import_entry \module \field "function"
        rleb128_32 \type
        .popsection
        .endm

        .macro import_table module field table_type:vararg
        .pushsection .wasm.import
        import_entry \module \field "table"
        \table_type
        .popsection
        .endm

        .macro import_memory module field memory_type:vararg
        .pushsection .wasm.import
        import_entry \module \field "memory"
        \memory_type
        .popsection
        .endm

        .macro import_global module field global_type:vararg
        .pushsection .wasm.import
        import_entry \module \field "global"
        \global_type
        .popsection
        .endm

        .macro value_type value_type
        .ifeqs \value_type,"i"
        .byte 0x7f
        .endif
        .ifeqs \value_type,"l"
        .byte 0x7e
        .endif
        .ifeqs \value_type,"f"
        .byte 0x7d
        .endif
        .ifeqs \value_type,"d"
        .byte 0x7c
        .endif
        .endm

        .macro global_type value_type mutable
        value_type \value_type
        .if \mutable
        .byte 1
        .else
        .byte 0
        .endif
        .endm

        .macro elem_type elem_type
        .ifeqs \elem_type,"anyfunc"
        .byte 0x70
        .endif
        .endm

        .macro resizable_limits 
        
        .macro table_type elem_type limits:vararg
        elem_type \elem_type
        resizable_limits \limits
        .endm
        
        
