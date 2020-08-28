#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string str("some string");
  for (auto c : str) {
    std::cout << c << std::endl;
  }
  return 0;
}
