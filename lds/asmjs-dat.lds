OUTPUT_FORMAT(binary)
SECTIONS
{
  KEEP(*(.data*))
  /DISCARD/ (*(*))
}
