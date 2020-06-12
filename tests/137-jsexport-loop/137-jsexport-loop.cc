#include <stdio.h>
#include <string.h>

asm(".include \"/home/pip/git/asmjs/unsorted-experimentation/import-macros.s\"");
asm(".import3 thinthin,queue_peek,__thinthin_queue_peek");
asm(".import3 thinthin,queue_pop,__thinthin_queue_pop");
asm(".import3 thinthin,queue_return,__thinthin_queue_return");

extern "C"
__attribute__((stackcall))
int
__thinthin_queue_peek();

extern "C"
__attribute__((stackcall))
int
__thinthin_queue_pop(void (**)(long, long, void *, double *),
                     void *,
                     void *);

extern "C"
__attribute__((stackcall))
int
__thinthin_queue_return(void *);

class AsmJSExportLoop {
public:
  AsmJSExportLoop (const char *)
  {
  }

  ~AsmJSExportLoop ()
  {
    ssize_t size;
    printf("looping...\n");
    while ((size = __thinthin_queue_peek()) >= 0) {
      double stack[1+size];
      void (*apply)(long, long, void *, double *);
      void *fun;

      memset(stack, 0, (1+size) * sizeof(double));

      __thinthin_queue_pop(&apply, &fun, stack+1);

      printf("applying...\n");
      apply(0, 0, fun, stack);

      __thinthin_queue_return(stack);
    }
  }
};

static AsmJSExportLoop loop("dummy");
