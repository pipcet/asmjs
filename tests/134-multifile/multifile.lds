SECTIONS
{
  . = 16384;
  .prev.data :
  {
    *(.prev.prev.header)
    *(.prev.prev.data)
    *(.prev.prev.init_array)
    . = ALIGN(., 16);
    *(.prev.header)
    *(.prev.data)
    *(.prev.init_array)
    . = ALIGN(., 16);
  }
  . = ALIGN(., 16);
  .header :
  {
    LONG(ABSOLUTE(__data_start));
    LONG(ABSOLUTE(__terminator));
    LONG(0);
    LONG(0);
    LONG(ABSOLUTE(__init_array_start));
    LONG(ABSOLUTE(__init_array_end));
    LONG(0);
    LONG(0);
  }
  .data :
  {
    __data_start = .;
    *(.data)
    . = ALIGN(., 16);
  }
  .init_array :
  {
    __init_array_start = .;
    *(.init_array)
    __init_array_end = .;
  }
  /DISCARD/ :
  {
    *(.prev.term)
  }
  . = ALIGN(., 16);
  .term :
  {
    __terminator = .;
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
  }
}
