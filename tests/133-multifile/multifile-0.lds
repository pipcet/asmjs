SECTIONS
{
  . = 16384;
  .header :
  {
    LONG(ABSOLUTE(__data_start));
    LONG(ABSOLUTE(__data_end));
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
  .term :
  {
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
  }
}
