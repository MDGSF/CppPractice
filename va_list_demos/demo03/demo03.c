/*
__VA_ARGS__ 是C语言中的一个预处理宏，用于表示可变参数的占位符。
它可以在宏定义中作为参数列表的一部分，用来接受可变数量的参数。

通常情况下，当定义一个带有可变参数的宏时，我们可以使用 __VA_ARGS__
来代表可变参数的部分。在宏展开时，__VA_ARGS__ 会被实际的可变参数替换掉。
*/

#include <stdio.h>

#define LOG(format, ...) printf(format, __VA_ARGS__)

int main() {
  int num = 42;
  LOG("The value is: %d\n", num);
  LOG("Hello, %s!\n", "World");
  LOG("The answer is: %d\n", 42);

  return 0;
}

