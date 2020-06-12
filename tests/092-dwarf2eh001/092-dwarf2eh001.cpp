#include <stdio.h>

main() {
  fprintf(stderr, "fp %p\n", __builtin_frame_address(0));
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
