#NO_APP
	.include "wasm32-macros.s"
	text_section
	.global __sprintf
	defun __sprintf, FiiiiiiiE
	.labeldef_debug .LFB0
	get_local $sp
	i32.const -48
	i32.add
	set_local $sp
	get_local $sp
	set_local $fp
	.labeldef_debug .LCFI0
	i32.const 8288
	i32.const 0
	i32.store a=2 0
	i32.const 8288
	i32.const 8288
	i32.load a=2 0
	i32.store a=2 0
	i32.const 48
	get_local $fp
	i32.add
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
	i32.const __wasm_pc_base___sprintf
	i32.add
	i32.add
	i32.store a=2 0
	i32.const 0
	get_local $fp
	i32.add
	get_local $fp
	i32.const 48
	i32.add
	i32.store a=2 0
	i32.const 8
	get_local $fp
	i32.add
	get_global $plt
	i32.const __sprintf
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
	i32.const __wasm_pc_base___sprintf
	i32.add
	i32.add
	i32.store a=2 0
	i32.const 28
	get_local $fp
	i32.add
	get_global $gpo
	i32.const __wasm_pc_base___sprintf
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
	i32.const 0
	i32.store a=2 0
	get_local $rp
	return
	end
	endefun __sprintf
	.global sprintf
	.hidden	sprintf
	.set sprintf, __sprintf
	.section	.debug_frame,"",@progbits
	.Lframe0:
	.4byte	.LECIE0-.LSCIE0
	.LSCIE0:
	.4byte	0xffffffff
	.byte	0x3
	.ascii "\0"
	.uleb128 0x1
	.sleb128 -4
	.uleb128 0x24
	.byte	0xc
	.uleb128 0x2
	.uleb128 0
	.byte	0x11
	.uleb128 0x24
	.sleb128 -2
	.p2align 2
	.LECIE0:
.LSFDE0:
	.4byte	.LEFDE0-.LASFDE0
	.LASFDE0:
	.4byte	.Lframe0
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.byte	0x4
	.4byte	.LCFI0-.LFB0
	.byte	0x11
	.uleb128 0x24
	.sleb128 -6
	.byte	0x10
	.byte	0
	.uleb128 0x9
	.byte	0x72
	.sleb128 0
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0x72
	.sleb128 0
	.byte	0x1c
	.byte	0x22
	.byte	0xd
	.uleb128 0
	.p2align 2
	.LEFDE0:
	.section	.eh_frame,"aw",@progbits
	.Lframe1:
	.4byte	.LECIE1-.LSCIE1
	.LSCIE1:
	.4byte	0
	.byte	0x3
	.ascii "\0"
	.uleb128 0x1
	.sleb128 -4
	.uleb128 0x24
	.byte	0xc
	.uleb128 0x2
	.uleb128 0
	.byte	0x11
	.uleb128 0x24
	.sleb128 -2
	.p2align 2
	.LECIE1:
.LSFDE3:
	.4byte	.LEFDE3-.LASFDE3
	.LASFDE3:
	.4byte	.LASFDE3-.Lframe1
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.byte	0x4
	.4byte	.LCFI0-.LFB0
	.byte	0x11
	.uleb128 0x24
	.sleb128 -6
	.byte	0x10
	.byte	0
	.uleb128 0x9
	.byte	0x72
	.sleb128 0
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0x72
	.sleb128 0
	.byte	0x1c
	.byte	0x22
	.byte	0xd
	.uleb128 0
	.p2align 2
	.LEFDE3:
