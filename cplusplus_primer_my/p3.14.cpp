#include <iostream>
#include <string>
#include <vector>

void show(const std::vector<int>& v) {
  for (auto e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> result;
  std::string s;
  while (std::cin >> s) {
    result.push_back(std::stoi(s));
  }
  show(result);
  return 0;
}
