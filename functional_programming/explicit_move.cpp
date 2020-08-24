#include <iostream>
#include <string>

int main() {
  std::string a = "original";
  std::string b = "new";
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  b = std::move(a);
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  return 0;
}
