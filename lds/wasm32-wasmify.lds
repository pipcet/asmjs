OUTPUT_FORMAT(binary)
SECTIONS
{
  .data : SUBALIGN(1)  {
      *(.output)
      *(.asmjs.header)
      *(.got*)
      *(.data)
      *(.bss)
      *(.preinit_array)
      *(.ctors)
      *(.dtors)
      *(.output.named)
  }
  /DISCARD/ : { *(.discard*) *(*) }
}
