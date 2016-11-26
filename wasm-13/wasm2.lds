OUTPUT_FORMAT(binary)
SECTIONS
{
  .data : SUBALIGN(1) { *(.output) *(.output.data) }
  /DISCARD/ : { *(.discard*) *(*) }
}
