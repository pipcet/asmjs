/* Default linker script, for normal executables */
ENTRY(_start)
SECTIONS
{
  . = 0x40010000;
  .init : { *(.prev..init*) }
  .text :
  {
    *(.prev.text*)
    *(.prev__libc_freeres_fn*)
    *(.prev__libc_thread_freeres_fn*)
  }
  .fini : { *(.prev.fini*) }
  .init : { *(.prev.init*) }
  .text :
  {
    *(.prev.text*)
    *(.prev__libc_freeres_fn*)
    *(.prev__libc_thread_freeres_fn*)
  }
  .fini : { *(.prev.fini*) }
  . = 0xc0000000;
  .javascript.init : { FILL(0x20202020); *(.javascript.init*) }
  .javascript.text :
  {
    FILL(0x20202020);
    *(.javascript.text*)
    *(.javascript__libc_freeres_fn*)
    *(.javascript__libc_thread_freeres_fn*)
  }
  .javascript.fini : { FILL(0x20202020); *(.javascript.fini*) }
  .javascript.special.export : { *(.javascript.special.export*) }
  .javascript.special.define : { *(.javascript.special.define*) }
  .javascript.special.fpswitch : { *(.javascript.special.fpswitch*) }
  .javascript.init : { FILL(0x20202020); *(.prev.javascript.init*) }
  .javascript.text :
  {
    FILL(0x20202020);
    *(.prev.javascript.text*)
    *(.prev.javascript__libc_freeres_fn*)
    *(.prev.javascript__libc_thread_freeres_fn*)
  }
  .javascript.fini : { FILL(0x20202020); *(.prev.javascript.fini*) }
  .javascript.special.export : { *(.prev.javascript.special.export*) }
  .javascript.special.define : { *(.prev.javascript.special.define*) }
  .javascript.special.fpswitch : { *(.prev.javascript.special.fpswitch*) }

  .jsexport 0 :
  {
    *(.prev.jsexport)
    *(.jsexport)
  }

  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line .debug_line.* .debug_line_end ) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
  /* DWARF 3 */
  .debug_pubtypes 0 : { *(.debug_pubtypes) }
  .debug_ranges   0 : { *(.debug_ranges) }
  /* DWARF Extension.  */
  .debug_macro    0 : { *(.debug_macro) }
  /*  /DISCARD/ : { *(*) } */

  . = 16384;
  /DISCARD/ :
  {
    *(.prev.asmjs.term)
  }
  .prev.data :
  {
    *(.prev.prev.asmjs.header)
    . = ALIGN(., 16);
    *(.prev.prev.data)
    . = ALIGN(., 16);
    *(.prev.prev.bss)
    . = ALIGN(., 16);
    *(.prev.asmjs.header)
    . = ALIGN(., 16);
    *(.prev.data)
    . = ALIGN(., 16);
    *(.prev.bss)
    . = ALIGN(., 16);
  }
  .asmjs.header :
  {
     LONG(ABSOLUTE(__data_start));
     LONG(0);
     LONG(ABSOLUTE(__terminator));
     LONG(0);
     LONG(ABSOLUTE(__multifile_preinit_array_start));
     LONG(0);
     LONG(ABSOLUTE(__multifile_preinit_array_end));
     LONG(0);
     LONG(ABSOLUTE(__multifile_init_array_start));
     LONG(0);
     LONG(ABSOLUTE(__multifile_init_array_end));
     LONG(0);
     LONG(ABSOLUTE(__multifile_fini_array_start));
     LONG(0);
     LONG(ABSOLUTE(__multifile_fini_array_end));
     LONG(0);
  }
  .data :
  {
     . = ALIGN(., 16);
     PROVIDE_HIDDEN(__data_start = .);
     *(.data*)
     . = ALIGN(., 16);
     *(.gnu.linkonce.d.*)
     . = ALIGN(., 16);
     *(.rodata*)
     . = ALIGN(., 16);
     *(.jcr*)
     . = ALIGN(., 16);
     *(.dynbss)
     . = ALIGN(., 16);
     *(.bss* .gnu.linkonce.b.*)
     . = ALIGN(., 16);
     *(.gcc_except_table*)
     . = ALIGN(., 16);
     *(.eh_frame*)
     . = ALIGN(., 16);
     __start___libc_atexit = .;
     *(__libc_atexit)
     __stop___libc_atexit = .;
     . = ALIGN(., 16);
     __start___libc_subfreeres = .;
     *(__libc_subfreeres)
     __stop___libc_subfreeres = .;
     . = ALIGN(., 16);
     *(__libc_thread_subfreeres)
     . = ALIGN(., 16);
     *(__libc_freeres_ptrs)
     . = ALIGN(., 16);
    __multifile_init_array_start = .;
    KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
    KEEP (*(.init_array EXCLUDE_FILE (*crtend.o *crtend?.o) .ctors))
    __multifile_init_array_end = .;
     . = ALIGN(., 16);
    __multifile_fini_array_start = .;
    KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
    KEEP (*(.fini_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .dtors))
    __multifile_fini_array_end = .;
    . = ALIGN(., 16);
     *(COMMON)
     *(.tbss*)
    . = ALIGN(., 16);
  }
  .preinit_array     :
  {
    __multifile_preinit_array_start = .;
    KEEP (*(.preinit_array))
    __multifile_preinit_array_end = .;
  }
  .ctors          :
  {
    /* gcc uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    /* We don't want to include the .ctor section from
       the crtend.o file until after the sorted ctors.
       The .ctor section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
  }
  .dtors          :
  {
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
  }
  . = ALIGN(., 16);
  .asmjs.term :
  {
    PROVIDE_HIDDEN(__terminator = .);
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
    LONG(0);
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
