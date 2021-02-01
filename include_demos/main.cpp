#include <stdio.h>

// include 在预处理阶段由预处理器处理，只是直接包含进来。
static int calc_table[] = {
#include "calc_values.inc"
};

int main() {
  for (int i = 0; i < sizeof(calc_table) / sizeof(int); i++) {
    printf("%d ", calc_table[i]);
  }
  printf("\n");
  return 0;
}
