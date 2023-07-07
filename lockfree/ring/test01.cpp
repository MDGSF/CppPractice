#include "ring01.hpp"
#include <iostream>

int main() {
  Ring<int> ring(10);
  for (int i = 0; i < 20; ++i) {
    if (ring.push(i)) {
      std::cout << i << " success" << std::endl;
    } else {
      std::cout << i << " failed" << std::endl;
    }
  }
  return 0;
}
