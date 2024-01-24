#include <stdarg.h>
#include <stdio.h>

void printNumbers(int count, ...) {
  va_list args;
  va_start(args, count);

  for (int i = 0; i < count; i++) {
    int num = va_arg(args, int);
    printf("%d ", num);
  }

  va_end(args);
  printf("\n");
}

int main() {
  printNumbers(3, 1, 2, 3);
  printNumbers(5, 10, 20, 30, 40, 50);
  printNumbers(2, -1, -2);

  return 0;
}

