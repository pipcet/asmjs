        .pushsection .wasm.type
        .popsection

        .pushsection .wasm.funchars
        .popsection

        .set __wasm_counter,0

        .macro rleb128 expr:vararg
        .reloc .,R_ASMJS_LEB128,\expr
        .rept 15
        .byte 0x80
        .endr
        .byte 0x00
        .endm

        .macro defun name, sig:vararg
        .set __wasm_depth, __wasm_blocks_\name\()_end - __wasm_blocks_\name
        .pushsection .wasm.chars.type
__sigchar_\name\():
        .byte 0
        .popsection
        .pushsection .wasm.payload.type
__signature_\name\():
        signature \sig
        .popsection
        .pushsection .wasm.chars.function
\name\():
        .byte 0
        .popsection
        .pushsection .wasm.chars.code
        .byte 0
        .popsection
        .pushsection .wasm.payload.function
        .sleb128 __sigchar_\name\()
        .popsection

        .set __wasm_counter, __wasm_counter + 1
        .set __wasm_blocks, 0
        .pushsection .wasm.payload.code,2*__wasm_counter
        rleb128 __body_end_\name - __body_start_\name
__body_start_\name\():
        .byte 0x00
        block
        .popsection

        .pushsection .wasm.payload.code,2*__wasm_counter+1
        .endm

        .macro endefun name
__body_end_\name\():
        .popsection
        .pushsection .wasm.payload.code,2*__wasm_counter
__wasm_blocks_\name:
        .rept __wasm_blocks+2
        block
        .endr
__wasm_blocks_\name\()_end:
        get_local 0
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

