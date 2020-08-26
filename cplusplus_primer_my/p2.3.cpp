#include <iostream>

int main() {
  unsigned u = 10;
  unsigned u2 = 42;
  std::cout << u2 - u << std::endl;
  std::cout << u - u2 << std::endl;

  int i = 10;
  int i2 = 42;
  std::cout << i2 - i << std::endl;
  std::cout << i - i2 << std::endl;
  std::cout << i - u << std::endl;
  std::cout << u - i << std::endl;
  return 0;
}
