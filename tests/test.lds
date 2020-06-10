ENTRY(_start)
PHDRS
{
  headers PT_PHDR PHDRS ;
  headers_data PT_LOAD PHDRS ;
  interp PT_INTERP ;
  text PT_LOAD ;
  data PT_LOAD ;
  space_function_index PT_LOAD ;
  space_pc PT_LOAD ;
  space_1 PT_LOAD ;
  space_2 PT_LOAD ;
  space_3 PT_LOAD ;
  space_4 PT_LOAD ;
  space_5 PT_LOAD ;
  space_6 PT_LOAD ;
  space_7 PT_LOAD ;
  space_8 PT_LOAD ;
  space_9 PT_LOAD ;
  space_10 PT_LOAD ;
  space_11 PT_LOAD ;
  space_name_function PT_LOAD ;
  space_name_local PT_LOAD ;
  wasm_1 PT_LOAD ;
  wasm_2 PT_LOAD ;
  wasm_3 PT_LOAD ;
  wasm_4 PT_LOAD ;
  wasm_5 PT_LOAD ;
  wasm_6 PT_LOAD ;
  wasm_7 PT_LOAD ;
  wasm_8 PT_LOAD ;
  wasm_9 PT_LOAD ;
  wasm_10 PT_LOAD ;
  wasm_11 PT_LOAD ;
  wasm_name_function PT_LOAD ;
  wasm_name_local PT_LOAD ;
  dynamic PT_DYNAMIC ;
  dynamic_data PT_LOAD ;
}
SECTIONS
{
  . = 16384;
  .wasm.data = .;
  .asmjs.header 16384 :
  {
     LONG(ABSOLUTE(__data_start));
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
  } :data
  .got :
  {
     . = ALIGN(., 16);
     __data_start = .;
     *(.got)
  } :data
  .got.plt :
  {
    *(.got.plt)
  } :data
  .data :
  {
     . = ALIGN(., 16);
     *(.data*)
     . = ALIGN(., 16);
     *(.gnu.linkonce.d.*)
     . = ALIGN(., 16);
     *(.tm_clone_table*);
     . = ALIGN(., 16);
     *(__libc_IO_vtables)
     . = ALIGN(., 16);
     *(.rodata*)
     . = ALIGN(., 16);
     *(.jcr*)
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
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
    KEEP (*(.init_array EXCLUDE_FILE (*crtend.o *crtend?.o) .ctors))
    PROVIDE_HIDDEN (__init_array_end = .);
     . = ALIGN(., 16);
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
    KEEP (*(.fini_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .dtors))
    PROVIDE_HIDDEN (__fini_array_end = .);
     . = ALIGN(., 16);
  } :data
  .bss :
  {
     *(COMMON)
     *(.dynbss)
     *(.bss* .gnu.linkonce.b.*)
     *(.tbss*)
  } :data
  .preinit_array     :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } :data
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
  } :data
  .dtors          :
  {
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
  } :data
  . = ALIGN(., 16);
  .wasm.data_end = .;
  .dynamic :
  {
    *(.dynamic)
    LONG(0);
  } :dynamic :dynamic_data
  .rela.dyn :
  {
    *(.rela.dyn)
  } :dynamic :dynamic_data
  .dynsym :
  {
    *(.dynsym)
  } :dynamic :dynamic_data
  .dynstr :
  {
    *(.dynstr)
  } :dynamic :dynamic_data
  . = 0;
  .space.function_index 0 (NOLOAD) :
  {
       *(.space.function_index.import);
       *(.space.function_index);
       *(.space.function_index.*);
       .wasm.plt_bias = .;
       *(.space.function_index_.plt);
       .wasm.plt_end = .;
  } :space_function_index
  .space.pc 0 (NOLOAD) :
  {
       *(.space.pc.import);
       *(.space.pc);
       *(.space.pc.*);
       *(.space.pc_.plt);
       .wasm.pc_end = .;
  } :space_pc
  .space.type 0 (NOLOAD) :
  {
       *(.space.type.import);
       *(.space.type);
       *(.space.type.*);
       *(.space.type_.plt);
  } :space_1
  .space.import 0 (NOLOAD) :
  {
       *(.space.import.import);
       *(.space.import);
       *(.space.import.*);
       *(.space.import_.plt);
       .wasm.pc_end = .;
  } :space_2
  .space.function 0 (NOLOAD) :
  {
      /* There is no function space for imports */
      *(.space.function);
      *(.space.function.*);
      *(.space.function_.plt);
  } :space_3
  .space.table 0 (NOLOAD) :
  {
       *(.space.table.import);
       *(.space.table);
       *(.space.table.*);
       *(.space.table_.plt);
  } :space_4
  .space.memory 0 (NOLOAD) :
  {
       *(.space.memory.import);
       *(.space.memory);
       *(.space.memory.*);
       *(.space.memory_.plt);
  } :space_5
  .space.global 0 (NOLOAD) :
  {
       *(.space.global.import);
       *(.space.global);
       *(.space.global.*);
       *(.space.global_.plt);
  } :space_6
  .space.export 0 (NOLOAD) :
  {
       *(.space.export.import);
       *(.space.export);
       *(.space.export.*);
       *(.space.export_.plt);
  } :space_7
  .space.element 0 (NOLOAD) :
  {
       *(.space.element.import);
       *(.space.element);
       *(.space.element.*);
       *(.space.element_.plt);
  } :space_9
  .space.code 0 (NOLOAD) :
  {
      /* There is no code space for imports. */
      *(.space.code);
      *(.space.code.*);
      *(.space.code_.plt);
  } :space_10
  .space.name.function 0 (NOLOAD) :
  {
       *(.space.name.function.import);
       *(.space.name.function);
       *(.space.name.function.*);
       *(.space.name.function_.plt);
  } :space_name_function
  .space.name.local 0 (NOLOAD) :
  {
       *(.space.name.local.import);
       *(.space.name.local);
       *(.space.name.local.*);
       *(.space.name.local_.plt);
  } :space_name_local
  . = 0xc0000000;
  .wasm.type :
  {
       *(.wasm.type.import);
       *(.wasm.type);
       *(.wasm.type.*);
       *(.wasm.type_.plt);
  } :wasm_1
  .wasm.import :
  {
       *(.wasm.import.import);
       *(.wasm.import);
       *(.wasm.import.*);
       *(.wasm.import_.plt);
  } :wasm_2
  .wasm.function :
  {
       /* There is no function payload for imports */
       *(.wasm.function);
       *(.wasm.function.*);
       *(.wasm.function_.plt);
  } :wasm_3
  .wasm.table :
  {
       *(.wasm.table.import);
       *(.wasm.table);
       *(.wasm.table.*);
       *(.wasm.table_.plt);
  } :wasm_4
  .wasm.memory :
  {
       *(.wasm.memory.import);
       *(.wasm.memory);
       *(.wasm.memory.*);
       *(.wasm.memory_.plt);
  } :wasm_5
  .wasm.global :
  {
       *(.wasm.global.import);
       *(.wasm.global);
       *(.wasm.global.*);
       *(.wasm.global_.plt);
  } :wasm_6
  .wasm.export :
  {
       *(.wasm.export.import);
       *(.wasm.export);
       *(.wasm.export.*);
       *(.wasm.export_.plt);
  } :wasm_7
  .wasm.element :
  {
       *(.wasm.element.import);
       *(.wasm.element);
       *(.wasm.element.*);
       *(.wasm.element_.plt);
  } :wasm_9
  .wasm.code :
  {
      /* There is no code payload for imports */
      *(.wasm.code);
      *(.wasm.code.*);
      *(.wasm.code_.plt);
  } :wasm_10
  .wasm.name.function :
  {
       *(.wasm.name.function.import);
       *(.wasm.name.function);
       *(.wasm.name.function.*);
       *(.wasm.name.function_.plt);
  } :wasm_name_function
  . = 0x80000000;
  .wasm.name.local :
  {
       *(.wasm.name.local.import);
       *(.wasm.name.local);
       *(.wasm.name.local.*);
       *(.wasm.name.local_.plt);
  } :wasm_name_local
  .plt :
  {
    *(.plt);
  }
  .rela.plt :
  {
    *(.rela.plt);
  }
  .interp :
  {
    *(.interp)
  }
  .hash : { *(.hash) }
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
  .debug_addr     0 : { *(.debug_addr) }
  .text (NOLOAD) : { *(.text) }
  .init (NOLOAD) : { *(.init) }
  .fini (NOLOAD) : { *(.fini) }
  PROVIDE (_etext = .);
  PROVIDE (etext = .);
  /*   /DISCARD/ : { *(*) } */
}
