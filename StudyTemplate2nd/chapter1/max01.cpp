#include <iostream>

template <typename T>
T max(T a, T b) {
  return a > b ? a : b;
}

int main() {
  std::cout << max(1, 2) << std::endl;
  return 0;
}
