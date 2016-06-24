        .pushsection .wasm.type
        .popsection

        .pushsection .wasm.funchars
        .popsection

        .set __wasm_counter,0

        .macro rleb128 expr
        .reloc .,R_ASMJS_LEB128,\expr
        .rept 15
        .byte 0x80
        .endr
        .byte 0x00
        .endm

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

        .set __wasm_counter, __wasm_counter + 1
        .set __wasm_blocks, 0
        .pushsection .wasm.code,2*__wasm_counter
        .reloc .,R_ASMJS_LEB128,__body_end_\name - __body_start_\name
        .rept 15
        .byte 0x80
        .endr
        .byte 0x00
__body_start_\name\():
        .byte 0x00
        block
        .popsection

        .pushsection .wasm.code,2*__wasm_counter+1
        .endm

        .macro endefun name
__body_end_\name\():
        .popsection
        .pushsection .wasm.code,2*__wasm_counter
        .rept __wasm_blocks
        block
        .endr
        .byte 0x08
        .byte 0x00
        .uleb128 __wasm_blocks
        .set __wasm_block, __wasm_blocks
        .rept __wasm_blocks
        .4byte __wasm_block
        .set __wasm_block, __wasm_block - 1
        .endr
        .4byte 0
        .popsection
        .endm

        .macro nextcase
        end
        .set __wasm_blocks, __wasm_blocks + 1
        .endm

        defun f, i32 i64 i32 i32 f64
        call[1] f
        nextcase
        call[1] f
        call[1] f
        nextcase
        call[1] f
        endefun f

        defun g, i32 i64 i32 i32 f64
        call[1] f
        nextcase
        call[1] f
        call[1] f
        nextcase
        call[1] f
        endefun g
