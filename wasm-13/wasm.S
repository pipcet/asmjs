        .include "wasm-macros.s"
        .globl _start
        defun _start FvE
        return[0]
        end
        endefun _start

        .globl _ret42
        defun _ret42 FiE
        i32.const 0xa
        i32.const 0xb
        i32.const 0xc
        i32.const 0xd
        i32.const 0xe
        i32.const 0xf
        call 0
        return[1]
        end
        endefun _ret42
