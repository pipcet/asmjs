SECTIONS
{
  . = 16384;
  .header :
  {
    LONG(__header_start);
    LONG(0);
    LONG(0);
    LONG(0);
  }
  /DISCARD/ :
  {
    *(.header)
  }
  .data :
  {
    *(.data)
    . = ALIGN(., 16);
  }
  __header_start = .;
  .next_header :
  {
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
  }
  .next_data :
  {
    *(.next_data)
  }
}
