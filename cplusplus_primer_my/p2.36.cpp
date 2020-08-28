#include <iostream>

int main() {
  int a = 3;
  int b = 4;
  decltype(a) c = a;    // int c = a;
  decltype((b)) d = a;  // int &d = a;
  c++;
  d++;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << d << std::endl;
  return 0;
}
