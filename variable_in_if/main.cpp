#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4};

  if (const std::vector<int>::iterator it =
          std::find(vec.begin(), vec.end(), 3);
      it != vec.end()) {
    *it = 4;
  }

  for (auto e : vec) {
    std::cout << e << std::endl;
  }

  return 0;
}
