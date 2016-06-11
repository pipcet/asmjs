SECTIONS
{
  . = 16384;
  .prev_header :
  {
    *(.prev_header)
  }
  .prev_data :
  {
    *(.prev_data)
  }
  .header :
  {
    LONG(__data_start);
    LONG(__data_end);
    LONG(0);
    LONG(0);
  }
  .data :
  {
    __data_start = .;
    *(.data)
    . = ALIGN(., 16);
    __data_end = .;
  }
}
