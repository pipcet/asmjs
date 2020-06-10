        .include "wasm32-macros.s"
        .globl f
        defun f FiiE
        get_local 0
        i32.const 37
        i32.add
        return
        end
        endefun f
