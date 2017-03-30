#include <stdio.h>

main() {
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
