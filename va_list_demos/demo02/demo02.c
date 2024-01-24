/*
在C语言中，如果没有明确传入参数个数的变量，没有直接的方法来获取可变参数的个数。
这是因为可变参数的个数是由调用函数时传入的参数个数决定的，函数本身无法自动获取。

一种常见的解决方案是在可变参数列表的最后一个参数中传递一个特殊的值，
用于表示参数的结束。例如，可以使用一个负数作为结束标志，
这样函数可以在遍历可变参数列表时检查到结束标志，从而确定参数的个数。
*/

#include <stdarg.h>
#include <stdio.h>

void printNumbers(int first, ...) {
  va_list args;
  va_start(args, first);

  int num = first;
  int count = 0;

  while (num >= 0) {
    printf("%d ", num);
    num = va_arg(args, int);
    count++;
  }

  va_end(args);
  printf("\nTotal count: %d\n", count);
}

int main() {
  printNumbers(1, 2, 3, -1);
  printNumbers(10, 20, 30, 40, 50, -1);
  printNumbers(-1);

  return 0;
}

