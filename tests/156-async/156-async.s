        .include "wasm32-macros.s"
        .include "wasm32-import-macros.s"

        .global main
        defun main, FiiiiiiiE
        nextcase
        T 0
        T 1
        .labeldef_internal .L1
        .dpc .L1
        local.set $dpc
        T 2
        jump
        end
        end
        i32.const 0
        return
        end
        endefun main
