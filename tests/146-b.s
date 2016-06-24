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
        .pushsection .wasm.code
        .endm

        .macro endefun
        .popsection
        .endm

        .globl h
        defun h, i32
        nop
        endefun
