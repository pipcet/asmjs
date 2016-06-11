SECTIONS
{
  . = 16384;
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
