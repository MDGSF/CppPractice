#include <iostream>

int main() {
  int a = 3;
  int b = 4;
  decltype(a) c = a;      // equal to: int c = a;
  decltype(a = b) d = a;  // equal to: int &d = a;
  c++;
  d++;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << d << std::endl;
  return 0;
}
