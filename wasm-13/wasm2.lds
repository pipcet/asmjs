OUTPUT_FORMAT(binary)
SECTIONS
{
  .data : { *(.output) *(.output.data) }
  /DISCARD/ : { *(.discard*) *(*) }
}
