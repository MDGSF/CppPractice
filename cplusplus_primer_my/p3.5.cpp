#include <iostream>
#include <string>

int main() {
  std::string s;
  std::string sum;
  while (std::cin >> s) {
    sum += s;
  }
  std::cout << sum << std::endl;
  return 0;
}
