extern void asmjs_breakpoint(void);
extern int breakpoint2(void *);

int breakpoint3(void)
{
  return breakpoint2(__builtin_frame_address (0));

  asm volatile("pc = $\n\t.codetextlabel .Lbp3\n\t>>4;\n\trp = fp|1; break mainloop;\n\t.codetextlabeldef .Lbp3");

  asmjs_breakpoint();

  return 0;
}
