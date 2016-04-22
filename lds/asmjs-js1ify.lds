OUTPUT_FORMAT("binary")
SECTIONS
{
  .text : { *(.javascript.asmjs*) }
  /DISCARD/ : { *(*) }
}
