        .include "wasm32-macros.s"

        .globl __wasm_null
        .text
        createsig FvE
        .pushsection .space.import_.null
        .reloc .,R_WASM32_CODE_POINTER,0f
	.byte 0
	.popsection
	.pushsection .wasm.import_.null
0:      lstring "sys"
	lstring "null"
	.byte 0
	rleb128 __sigchar_FvE
	.popsection
	.pushsection .space.function_index.import_.null,""
	.type __wasm_null, @function
	.size __wasm_null, 1
__wasm_null:
	.reloc .,R_WASM32_INDEX,1f
	.byte 0
	.popsection
	.pushsection .space.element.import_.null
	.reloc .,R_WASM32_CODE_POINTER,0f
1:      .byte 0
	.popsection
	.pushsection .wasm.element.import_.null
0:      rleb128_32 __wasm_null
	.popsection
	.if 0
	.pushsection .space.name.function.import_.null
	.byte 0
	.popsection
	.pushsection .wasm.name.function.import_.null
	lstring null
	.byte 0
	.popsection
	.endif

	.pushsection .space.global_index.import
	.byte 0
	.byte 0
	.byte 0
	.popsection

	.pushsection .space.global
	.byte 0
	.popsection
	.pushsection .space.global_index
	.globl __wasm_stack_pointer
__wasm_stack_pointer:
	.byte 0
	.popsection
	.pushsection .wasm.global
	.byte 0x7f
	.byte 1
	i32.const 0
	end
	.popsection
