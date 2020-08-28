#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> articles = {"a", "an", "the"};
  for (auto e : articles) {
    std::cout << e << std::endl;
  }

  std::vector<int> ivec(10, -1);
  for (auto e : ivec) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  std::vector<std::string> svec(10, "hi!");
  for (auto e : svec) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
