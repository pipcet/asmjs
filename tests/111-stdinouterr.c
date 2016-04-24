#define stdin __emscripten_stdin
#define stdout __emscripten_stdout
#define stderr __emscripten_stderr
#include <stdio.h>

FILE *stdin;
FILE *stdout;
FILE *stderr;

void init_stdinouterr(void)
{
  stdin = fdopen(0, "r");
  stdout = fdopen(1, "w");
  stderr = fdopen(2, "w");
}

#if 0
int main(void)
{
  init_stdinouterr();

  fprintf(stderr, "test\n");
}
#endif
