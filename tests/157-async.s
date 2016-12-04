        .include "wasm32-macros.s"
        .include "wasm32-import-macros.s"

        .global main
        defun main, FiiiiiiiE
        T 0
        T 1
        T 2
        br 1
        i32.const 0
        return
        end
        endefun main
