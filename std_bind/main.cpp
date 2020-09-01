#include <iostream>
#include <functional>

int foo(int a, int b, int c) {
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  return a + b + c;
}

int main() {
  auto bindFoo = std::bind(foo, std::placeholders::_1, 3, 4);
  bindFoo(1);
  return 0;
}
