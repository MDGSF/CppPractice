#include <stdio.h>

int main() {
  int i = 0;
  auto counter = [&i]() { return i++; };  // capture by reference
  printf("%d\n", counter());
  printf("%d\n", counter());
  printf("%d\n", counter());
  return 0;
}
