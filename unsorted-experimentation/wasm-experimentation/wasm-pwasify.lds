OUTPUT_FORMAT("binary")
SECTIONS
{
  .text : {
/*    BYTE(0x60)
    BYTE(0x28) */
    *(.wasm_pwas.text)
    *(.wasm_pwas__libc_freeres_fn)
    *(.wasm_pwas__libc_thread_freeres_fn)
    *(.wasm_pwas.text*)
/*    BYTE(0x29) */
  }
  /DISCARD/ : { *(*) }
}
