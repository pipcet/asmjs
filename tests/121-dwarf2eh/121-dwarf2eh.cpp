#include <stdio.h>

main() {
  fprintf(stderr, "fp %p %p\n", __builtin_frame_address(0),
          __builtin_frame_address(1));
  fprintf(stderr, "cfa %p\n", __builtin_dwarf_cfa());
  fprintf(stderr, "rpc %p %p %p\n", __builtin_return_address(0),
          __builtin_return_address(1), __builtin_return_address(2));
  try {
    throw 1;
  }
  catch (...) {
    printf(" in catch\n");
    return 1;
  }
  printf(" back in main\n");
  return 10;
}
