        .pushsection .wasm.type
        .popsection

        .pushsection .wasm.funchars
        .popsection

        .macro defun name, sig:vararg
        .pushsection .wasm.sigchars
__sigchar_\name\():
        .byte 0
        .pushsection .wasm.type
__signature_\name\():
        signature \sig
        .popsection
        .pushsection .wasm.funchars
\name\():
        .byte 0
        .pushsection .wasm.function
        .sleb128 __sigchar_\name\()
        .popsection

        .set __wasm_blocks, 0
        .pushsection .wasm.code.\name\().a,0
        block
        .popsection
        
        .pushsection .wasm.code.\name\().a,1
        .endm

        .macro endefun name
        .popsection
        .pushsection .wasm.code.\name\().a,0
        .rept __wasm_blocks
        block
        .endr
        .popsection
        .endm

        defun f, i32 i64 i32 i32 f64
        .set __wasm_blocks, 5
        call[1] f
        endefun f

        .globl main
        defun main, i32
        .set __wasm_blocks, 5
        endefun main
