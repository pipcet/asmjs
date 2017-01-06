        .include "wasm-macros.s"

        .global _start
        defun _start, i32
        i32.const 0
        call[1] _start
        endefun _start

        defun g, i32 i64 i32 i32 f64
        i64.const __wasm_depth
        call[1] _start
        nextcase
        call[1] _start
        call[1] _start
        nextcase
        call[1] _start
        endefun g
