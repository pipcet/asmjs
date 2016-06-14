        .include "asmjs-macros.s"
        .macro .wasmtextlabeldef label
.LAT\@0:
        .popsection
        .long 0
        .long 0
\label\():
        .long 0
        .long 0
        .pushsection .javascript%S,"a"
        .endm

        .macro .wasmtextlabeldeffirst label
.LAT\@0:
        .popsection
\label\():
.LAT\@1:
        .long 0
        .long 0
        .pushsection .javascript%S,"a"
        .set .L__pc0, .LAT\@1
        .endm

        .macro .wasmtextlabeldeflast label
.LAT\@0:
        .popsection
        .long 0
        .long 0
\label\():
        .pushsection .javascript%S,"a"
        .endm

        .macro .wrpcr4 a, b
        .ascii ",(string->number (string-delete \""
        .reloc .,R_ASMJS_HEX16R4,\b-\a
        .ascii "0000000000000000"
        .ascii "\" #\\ 0) 16)"
        .endm

        .macro .wdpc label
        .wrpcr4 .L__pc0, \label
        .endm
        
        .text
        .global main
        .global _start
        .set _start,main
        .pushsection .javascript%S,"a"

`(
(
        .wasmtextlabeldeffirst main
        "f_$
        .textlabel main
        "
        (label)
        .wasmtextlabeldef .L001
        (if (i32.eq (get_local $r0) (i32.const 0)) (return) (nop))
        (call_import $cp (get_local $r0))
        (set $r0 (i32.add (get_local $r0) (i32.const -1)))
        (set $dpc (i32.const
        .wdpc .L001
        ))
        (jump)
        .wasmtextlabeldeflast .ends.main
)
)
