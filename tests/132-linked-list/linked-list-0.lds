SECTIONS
{
  . = 16384;
  .header :
  {
    __header_start = .;
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
  }
  .data :
  {
    *(.data)
    . = ALIGN(., 16);
  }
  __next_header_start = .;
}
