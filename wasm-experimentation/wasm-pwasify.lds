OUTPUT_FORMAT("binary")
SECTIONS
{
  .text : {
    BYTE(0x60)
    BYTE(0x28)
    *(.wasm-pwas.text)
    *(.wasm-pwas__libc_freeres_fn)
    *(.wasm-pwas__libc_thread_freeres_fn)
    *(.wasm-pwas.text*)
    BYTE(0x29)
  }
  /DISCARD/ : { *(*) }
}
