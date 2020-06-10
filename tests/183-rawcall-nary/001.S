        .include "wasm32-macros.s"
        .globl f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12
        defun f0 FiE
        i32.const 0
        return
        end
        endefun f0
        defun f1 FiiE
        local.get 0
        return
        end
        endefun f1
        defun f2 FiiiE
        local.get 0
        local.get 1
        i32.add
        return
        end
        endefun f2
        defun f3 FiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        return
        end
        endefun f3
        defun f4 FiiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        local.get 3
        i32.add
        return
        end
        endefun f4
        defun f5 FiiiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        local.get 3
        i32.add
        local.get 4
        i32.add
        return
        end
        endefun f5
        defun f6 FiiiiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        local.get 3
        i32.add
        local.get 4
        i32.add
        local.get 5
        i32.add
        return
        end
        endefun f6
        defun f7 FiiiiiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        local.get 3
        i32.add
        local.get 4
        i32.add
        local.get 5
        i32.add
        local.get 6
        i32.add
        return
        end
        endefun f7
        defun f8 FiiiiiiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        local.get 3
        i32.add
        local.get 4
        i32.add
        local.get 5
        i32.add
        local.get 6
        i32.add
        local.get 7
        i32.add
        return
        end
        endefun f8
        defun f9 FiiiiiiiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        local.get 3
        i32.add
        local.get 4
        i32.add
        local.get 5
        i32.add
        local.get 6
        i32.add
        local.get 7
        i32.add
        local.get 8
        i32.add
        return
        end
        endefun f9
        defun f10 FiiiiiiiiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        local.get 3
        i32.add
        local.get 4
        i32.add
        local.get 5
        i32.add
        local.get 6
        i32.add
        local.get 7
        i32.add
        local.get 8
        i32.add
        local.get 9
        i32.add
        return
        end
        endefun f10
        defun f11 FiiiiiiiiiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        local.get 3
        i32.add
        local.get 4
        i32.add
        local.get 5
        i32.add
        local.get 6
        i32.add
        local.get 7
        i32.add
        local.get 8
        i32.add
        local.get 9
        i32.add
        local.get 10
        i32.add
        return
        end
        endefun f11
        defun f12 FiiiiiiiiiiiiiE
        local.get 0
        local.get 1
        i32.add
        local.get 2
        i32.add
        local.get 3
        i32.add
        local.get 4
        i32.add
        local.get 5
        i32.add
        local.get 6
        i32.add
        local.get 7
        i32.add
        local.get 8
        i32.add
        local.get 9
        i32.add
        local.get 10
        i32.add
        local.get 11
        i32.add
        return
        end
        endefun f12
