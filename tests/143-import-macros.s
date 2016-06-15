#NO_APP
        .macro .import3 module, extname, name
        .section .str.lib,"ams",1
        .data
.ifndef __str_\name
__str_\name:
        .asciz "\extname"
.endif
.ifndef __str_\module
__str_\module:
        .asciz "\module"
.endif
        .text
        .p2align 4+8
        .global \name
        .pushsection .javascript%S,"a"
 (                              
	.wasmtextlabeldeffirst \name
	.ascii "\""
        f_$
	.textlabel \name
	.ascii "\""
	(block
		(if (i32.ne (i32.and (get_local $rp) (i32.const 3)) (i32.const 1)) (return (get_local $rp)))
		(i32.store (i32.add (get_local $fp) (i32.const 0)) (i32.add (get_local $fp) (i32.const 48)))
		(i32.store (i32.add (get_local $fp) (i32.const 4)) (i32.shl (get_local $pc0) (i32.const 4)))
		(i32.store (i32.add (get_local $fp) (i32.const 8)) (i32.shl (i32.add (get_local $pc0) (get_local $dpc)) (i32.const 4)))
		(i32.store (i32.add (get_local $fp) (i32.const 12)) (get_local $rpc))
		(i32.store (i32.add (get_local $fp) (i32.const 16)) (get_local $sp))
		(i32.store (i32.add (get_local $fp) (i32.const 20)) (i32.const 1008))
		(return (get_local $rp))
	)
	(set $sp (i32.add (get_local $sp1) (i32.const -16)))
	.labeldef_debug .LFB0
	(set $sp (i32.add (get_local $sp) (i32.const -48)))
	(set $fp (get_local $sp))
	.labeldef_debug .LCFI0
	(set $sp (i32.add (get_local $sp) (i32.const -8)))
        .labeldef_internal .LSC0_\module\()_\name
;; 6 "subrepos/gcc/gcc//config/wasm/import.c" 1
	(set_local $rp (call_import $extcall
                .ndatatextlabel __str_\module
                .ndatatextlabel __str_\name
                (i32.add (get_local $pc0) (get_local $dpc)) (i32.add (get_local $sp) (i32.const 48))))
        (if (i32.and (get_local $rp) (i32.const 3))
                (set_local $dpc (i32.const $
                .dpc .LSC0_\module\()_\name
                ))
                (set_local $dpc (i32.const $
                .dpc .LSC1_\module\()_\name
                ))
                )
        (set_local $rp (i32.or (get_local $fp) (i32.const 1)))
        (br $mainloop)
        .labeldef_internal .LSC1_\module\()_\name
	(return (i32.add (get_local $fp) (i32.const 48)))
	.set __wasm_fallthrough, 0
	.labeldef_debug .LFE0
	.wasmtextlabeldeflast .ends.funcall
	(set_local $rp (i32.add (get_local $sp1) (i32.const -16)))
		(set_local $pc0 (i32.shr_u (i32.load (i32.add (get_local $rp) (i32.const 4))) (i32.const 4)))
		(set_local $dpc (i32.sub (i32.shr_u (i32.load (i32.add (get_local $rp) (i32.const 8))) (i32.const 4)) (get_local $pc0)))
		(set_local $rpc (i32.load (i32.add (get_local $rp) (i32.const 12))))
		(set_local $sp (i32.load (i32.add (get_local $rp) (i32.const 16))))
	(set_local $fp (get_local $rp))
 )
        .endm
