        .include "wasm64-macros.s"
        
        .macro section name
        .pushsection .wasm.header.\name
        rleb128 __wasm_\name\()_id_end - __wasm_\name\()_id
__wasm_\name\()_id:
        .ascii "\name"
__wasm_\name\()_id_end:
        .popsection

        .pushsection .wasm.chars.\name
__wasm_chars_\name\():
        .endm

        section type
        section import
        section function
        section memory
        section export
        section start
        section code
        section data
        section name

        .globl $i64_store8
        .globl $i64_store16
        .globl $i64_store32
        .globl $i64_store

        .globl $i64_load8_s
        .globl $i64_load16_s
        .globl $i64_load32_s
        .globl $i64_load8_u
        .globl $i64_load16_u
        .globl $i64_load32_u
        .globl $i64_load

        .globl $shl
        .globl $shr_s
        .globl $shr_u

        defun $i64_store8 i32 i64
        get_local 0
        get_local 1
        i32.wrap_i64
        i32.store8 a=0 0
        endefun $i64_store8

        defun $i64_store16 i32 i64
        get_local 0
        get_local 1
        i32.wrap_i64
        i32.store16 a=0 0
        endefun $i64_store16

        defun $i64_store32 i32 i64
        get_local 0
        get_local 1
        i32.wrap_i64
        i32.store a=0 0
        endefun $i64_store32

        defun $i64_store i32 i64
        get_local 0
        get_local 1
        f64.reinterpret_i64
        f64.store a=0 0
        endefun $i64_store

        defun $i64_load8_s i32 result i64
        get_local 0
        i32.load8_s a=0 0
        i64.extend_s_i32
        return[1]
        endefun $i64_load8_s

        defun $i64_load16_s i32 result i64
        get_local 0
        i32.load16_s a=0 0
        i64.extend_s_i32
        return[1]
        endefun $i64_load16_s

        defun $i64_load32_s i32 result i64
        get_local 0
        i32.load a=0 0
        i64.extend_s_i32
        return[1]
        endefun $i64_load32_s

        defun $i64_load8_u i32 result i64
        get_local 0
        i32.load8_u a=0 0
        i64.extend_u_i32
        return[1]
        endefun $i64_load8_u

        defun $i64_load16_u i32 result i64
        get_local 0
        i32.load16_u a=0 0
        i64.extend_u_i32
        return[1]
        endefun $i64_load16_u

        defun $i64_load32_u i32 result i64
        get_local 0
        i32.load a=0 0
        i64.extend_u_i32
        return[1]
        endefun $i64_load32_u

        defun $i64_load i32 result i64
        get_local 0
        f64.load a=0 0
        i64.reinterpret_f64
        return[1]
        endefun $i64_load

        defun $shl i64 i64 result i64
        get_local 0
        get_local 1
        i64.shl
        return[1]
        endefun $shl

        defun $shr_s i64 i64 result i64
        get_local 0
        get_local 1
        i64.shr_s
        return[1]
        endefun $shr_s

        defun $shr_u i64 i64 result i64
        get_local 0
        get_local 1
        i64.shr_u
        return[1]
        endefun $shr_u

        defun x0 i64 i64 result i64
        i64.const 0
        endefun x0
        defun x1 i64 i64 result i64
        i64.const 0
        endefun x1
        defun x2 i64 i64 result i64
        i64.const 0
        endefun x2
        defun x3 i64 i64 result i64
        i64.const 0
        endefun x3
        defun x4 i64 i64 result i64
        i64.const 0
        endefun x4
        defun x5 i64 i64 result i64
        i64.const 0
        endefun x5
        defun x6 i64 i64 result i64
        i64.const 0
        endefun x6
        defun x7 i64 i64 result i64
        i64.const 0
        endefun x7
        defun x8 i64 i64 result i64
        i64.const 0
        endefun x8
        defun x9 i64 i64 result i64
        i64.const 0
        endefun x9
        defun x10 i64 i64 result i64
        i64.const 0
        endefun x10
        defun x11 i64 i64 result i64
        i64.const 0
        endefun x11
        defun x12 i64 i64 result i64
        i64.const 0
        endefun x12
        defun x13 i64 i64 result i64
        i64.const 0
        endefun x13
        defun x14 i64 i64 result i64
        i64.const 0
        endefun x14
        defun x15 i64 i64 result i64
        i64.const 0
        endefun x15
        defun x16 i64 i64 result i64
        i64.const 0
        endefun x16

        .pushsection .wasm.chars.export
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.export
        rleb128 _start
        .byte 20
        .ascii "f_0x4000000000025000"
        .popsection

        .pushsection .wasm.chars.type
__wasm_type_extcall:
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.type
        .byte 0x40
        .byte 0x4
        .byte 0x2
        .byte 0x2
        .byte 0x2
        .byte 0x2
        .byte 0x1
        .byte 0x2
        .popsection

        .globl __wasm_import_extcall
        .pushsection .wasm.chars.import
__wasm_import_extcall:
        .byte 0x00
        .popsection
        .pushsection .wasm.payload.import
        rleb128 __wasm_type_extcall
        lstring thinthin
        lstring extcall
        .popsection
