#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  std::vector<int> v2 = v1;
  for (auto e : v2) {
    std::cout << e << std::endl;
  }
  return 0;
}
