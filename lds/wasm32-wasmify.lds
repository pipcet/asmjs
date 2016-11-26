OUTPUT_FORMAT(binary)
SECTIONS
{
  .data : SUBALIGN(1) {
      *(.output)
      *(.asmjs.header)
      *(.data)
      *(.bss)
      *(.preinit_array)
      *(.ctors)
      *(.dtors)
      *(.asmjs.term)
  }
  /DISCARD/ : { *(.discard*) *(*) }
}
