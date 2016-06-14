OUTPUT_FORMAT("binary")
SECTIONS
{
  .text : { *(.javascript*) }
  /DISCARD/ : { *(*) }
}
