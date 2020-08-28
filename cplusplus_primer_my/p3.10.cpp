#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string s;
  while (std::getline(std::cin, s)) {
    std::string result;
    for (auto c : s) {
      if (!ispunct(c)) {
        result += c;
      }
    }
    std::cout << result << std::endl;
  }
  return 0;
}
