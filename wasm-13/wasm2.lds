OUTPUT_FORMAT(binary)
SECTIONS
{
  .data : { *(.output) }
  /DISCARD/ : { *(.discard*) *(*) }
}
