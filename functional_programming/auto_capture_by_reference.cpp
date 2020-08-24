// Note that if you do use capture, you will lose the ability to convert to a
// old-style C function pointer

#include <stdio.h>

int main() {
  int i = 0;
  auto counter = [&]() {
    i++;
    return i;
  };
  printf("%d\n", counter());
  printf("%d\n", counter());
  printf("%d\n", counter());
  return 0;
}
