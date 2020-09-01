#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4};
  if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end()) {
    *itr = 4;
  }

  for (auto element : vec) {
    std::cout << element << std::endl;
  }

  for (auto &e : vec) {
    e += 1;
  }

  for (auto e : vec) {
    std::cout << e << std::endl;
  }
  return 0;
}
