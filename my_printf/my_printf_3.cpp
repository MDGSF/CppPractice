#include <iostream>

template <typename T, typename... Ts>
auto printf3(T value, Ts... args) {
  std::cout << value << std::endl;
  (void)std::initializer_list<T>{
      ([&args] { std::cout << args << std::endl; }(), value)...};
}

int main() {
  printf3(1, 2, "123", 1.1);
  return 0;
}
