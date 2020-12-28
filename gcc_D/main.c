#include <stdio.h>

int main() {
#ifdef HELLO
  printf("HELLO defined !\n");
  printf("HELLO = %d\n", HELLO);
#else
  printf("HELLO not define!\n");
#endif

  return 0;
}
