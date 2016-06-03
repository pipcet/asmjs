#include <typeinfo>
#include <stdio.h>

template<class F>
class AsmJSExport {
  const char *name;
  const char *type;
  F *f;

  public:
  AsmJSExport (const char *name,
               F f,
               const char *type)
    : name(name), f(f), type(type)
  {
    printf("%s\n", name);
  }
};

#if 0
#define asmjs_register(name, f, type)                           \
  __attribute__((constructor))                                  \
  static void init_##f()                                        \
  {                                                             \
    AsmJSExport<decltype(f)> jsexport_##f(name, f, "");         \
  }
#else
#define asmjs_register(name, f, type)                           \
  AsmJSExport<void (int)> jsexport_##f(name, f, "");
#endif


struct xyz;
union tu;
enum te {};

int boobooboo(struct xyz*, tu *, te *) {}
extern "C" int lalala(struct xyz*, tu *, te *) {}

void hi(int)
{
  printf("hi\n");
}
asmjs_register("hi", hi, typeid(hi).name());
