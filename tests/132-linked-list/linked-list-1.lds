SECTIONS
{
  . = 16384;
  .data :
  {
    *(.header)
    *(.data)
    *(.next_header)
    *(.next_data)
  }
}
