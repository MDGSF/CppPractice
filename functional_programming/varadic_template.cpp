#include <iostream>

void print() { std::cout << std::endl; }

template <typename T, typename... Ts>
void print(T value, Ts... values) {
  std::cout << value << " ";
  print(values...);
}

int main() {
  print(1, 2, 3);
  print(1, 2, 3, 4, 5);
  return 0;
}
