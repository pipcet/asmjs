OUTPUT_FORMAT("binary")
SECTIONS
{
  .text : {
    BYTE(0x60)
    BYTE(0x28)
    *(.javascript*)
    BYTE(0x29)
  }
  /DISCARD/ : { *(*) }
}
