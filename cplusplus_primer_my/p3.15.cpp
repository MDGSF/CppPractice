#include <iostream>
#include <string>
#include <vector>

void show(const std::vector<std::string>& v) {
  for (auto e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> result;
  std::string s;
  while (std::cin >> s) {
    result.push_back(s);
  }
  show(result);
  return 0;
}
