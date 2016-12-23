struct __zeropage {
  unsigned long long top_of_memory;
  unsigned long long top_of_sbrk;
  unsigned long long thread_list;
  unsigned long long bottom_of_sbrk;
};

struct __threadpage {
  unsigned long long next;
  unsigned long long prev;
  unsigned long long id;
  unsigned long long bottom_of_stack;
  unsigned long long top_of_stack;
  unsigned long long stop_reason;
  unsigned long long pc;
  unsigned long long sp;
  unsigned long long initsp;
  unsigned long long rv;
  unsigned long long a0;
  unsigned long long a1;
  unsigned long long a2;
  unsigned long long a3;
  unsigned long long tp;
  unsigned long long lp;
  unsigned long long sigfpe;
  unsigned long long sigsegv;
};

#define __threadpage ((struct __threadpage *)(3 * 4096))

asm("llstub:\n\t"
    "i32.const 0x3078\n\t"
    "i32.const 0xdeadbeef\n\t"
    "i32.store a=2 0\n\t"
    "get_local 0\n\t"
    "get_local 1\n\t"
    "get_local 2\n\t"
    "get_local 3\n\t"
    "get_local 4\n\t"
    "get_local 5\n\t"
    "call lazyload@plt\n\t"
    "return");

void lazyload(unsigned long arg0, unsigned long arg1)
{
  unsigned long index = __threadpage->lp;
  void (*f)(unsigned long, unsigned long) = (void *)index;

  lazyload2(index);

  f(arg0, arg1);
}
