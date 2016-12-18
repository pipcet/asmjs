	.include "wasm32-macros.s"
	.section .wasm.payload.code
	.subsection 2*__wasm_counter+1
	.global __wasm_lazyload_stub
	defun __wasm_lazyload_stub, FiiiiiiiE
	.labeldef_debug .LFB0
	get_local $sp
	i32.const -96
	i32.add
	tee_local $sp
	set_local $fp
	.labeldef_debug .LCFI0
	get_local $r0
	set_local $r3
        get_local $sp
        i32.const -84
        i32.add
        i32.const 12368
        i32.load a=2 0
        i32.store a=2 0
        get_local $sp
        i32.const -88
        i32.add
        i32.const 12376
        i32.load a=2 0
        i32.store a=2 0
        get_local $sp
        i32.const -92
        i32.add
        i32.const 12384
        i32.load a=2 0
        i32.store a=2 0
        get_local $sp
        i32.const -96
        i32.add
        i32.const 12392
        i32.load a=2 0
        i32.store a=2 0
	i32.const 12408
	i32.load a=2 0
	set_local $r2
	get_local $r2
	set_local $r0
	i32.const -1
	get_local $sp
	get_local $r0
	get_local $r1
	i32.const 0
	i32.const 0
	call __wasm_lazyload@plt
	tee_local $rp
	i32.const 3
	i32.and
	if[]
	.dpc .LI15
	set_local $dpc
	throw1
	end
	.wasmtextlabeldpcdef .LI15
        i32.const 12368
        get_local $sp
        i32.const -84
        i32.add
        i32.load a=2 0
        i32.store a=2 0
        i32.const 12376
        get_local $sp
        i32.const -88
        i32.add
        i32.load a=2 0
        i32.store a=2 0
        i32.const 12384
        get_local $sp
        i32.const -92
        i32.add
        i32.load a=2 0
        i32.store a=2 0
        i32.const 12392
        get_local $sp
        i32.const -96
        i32.add
        i32.load a=2 0
        i32.store a=2 0
	get_local $r3
	set_local $r0
	i32.const -1
	get_local $sp
        i32.const 96+16
        i32.add
	get_local $r0
	get_local $r1
	i32.const 0
	i32.const 0
	get_local $r2
	call_indirect __sigchar_FiiiiiiiE 0
        return
	.set __wasm32_fallthrough, 0
	.labeldef_debug .LFE0
	nextcase
	get_local $sp
	set_local $rp
	i32.const 16
	get_local $rp
	i32.add
	i32.load a=2 0
	set_local $dpc
	i32.const 32
	get_local $rp
	i32.add
	i32.load a=2 0
	set_local $sp
	i32.const 48
	get_local $rp
	i32.add
	i32.load a=2 0
	set_local $r0
	i32.const 56
	get_local $rp
	i32.add
	i32.load a=2 0
	set_local $r1
	i32.const 64
	get_local $rp
	i32.add
	i32.load a=2 0
	set_local $r2
	i32.const 72
	get_local $rp
	i32.add
	i32.load a=2 0
	set_local $r3
	get_local $rp
	set_local $fp
	jump2
	nextcase
	end
	i32.const 3
	get_local $rp
	i32.and
	i32.const 1
	i32.ne
	if[]
	get_local $rp
	return
	end
	get_local $sp
	i32.const -16
	i32.add
	get_local $fp
	i32.store a=2 0
	get_local $sp
	i32.const -8
	i32.add
	get_global $gpo
	get_local $dpc
	i32.const __wasm_pc_base___wasm_lazyload_stub
	i32.add
	i32.add
	i32.store a=2 0
	i32.const 0
	get_local $fp
	i32.add
	get_local $fp
	i32.const 80
	i32.add
	i32.store a=2 0
	i32.const 8
	get_local $fp
	i32.add
	get_global $plt
	i32.const __wasm_lazyload_stub
	i32.add
	i32.store a=2 0
	i32.const 16
	get_local $fp
	i32.add
	get_local $dpc
	i32.store a=2 0
	i32.const 24
	get_local $fp
	i32.add
	get_global $gpo
	get_local $dpc
	i32.const __wasm_pc_base___wasm_lazyload_stub
	i32.add
	i32.add
	i32.store a=2 0
	i32.const 32
	get_local $fp
	i32.add
	get_local $sp
	i32.store a=2 0
	i32.const 40
	get_local $fp
	i32.add
	i32.const 240
	i32.store a=2 0
	i32.const 48
	get_local $fp
	i32.add
	get_local $r0
	i32.store a=2 0
	i32.const 56
	get_local $fp
	i32.add
	get_local $r1
	i32.store a=2 0
	i32.const 64
	get_local $fp
	i32.add
	get_local $r2
	i32.store a=2 0
	i32.const 72
	get_local $fp
	i32.add
	get_local $r3
	i32.store a=2 0
	get_local $rp
	return
	end
	endefun __wasm_lazyload_stub
