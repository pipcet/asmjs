SECTIONS {
  . = 0x40000000;
  .text : { *(.text*) }
  . = 0x60000000;
  .javascript.asmjs : {
    *(.special.100)
    *(.javascript.data*)
    *(.javascript.rodata*)
    *(.javascript.bss*)
    *(.special.200)
    *(.javascript.special.fpswitch*)
    *(.special.300)
    *(.javascript.text*)
    *(.special.400)
    *(.javascript.special.export*)
    *(.special.500)
    *(.javascript.special.define)
    *(.special.600)
  }

  PROVIDE(__top_of_memory = 1024 * 1024 * 1024);
  PROVIDE(__start_of_sbrk = 32 * 1024 * 1024);
  PROVIDE(__top_of_stack = __top_of_mem);
  PROVIDE(__size_of_stack = 2 * 1024 * 1024);
  PROVIDE(__bottom_of_stack = __top_of_stack - __size_of_stack);
  PROVIDE(__start_of_data = 5402632);
  . = __start_of_data;
  .data : { *(.data*) }
  PROVIDE(__end_of_data = .);
  /DISCARD/ : { *(*) }
}
