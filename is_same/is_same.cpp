#include <cstdint>
#include <iostream>
#include <type_traits>

void print_separator() { std::cout << "----------\n"; }

int main() {
  std::cout << std::boolalpha;

  std::cout << std::is_same<int, std::int32_t>::value << '\n';
  std::cout << std::is_same<int, std::int64_t>::value << '\n';

  print_separator();

  std::cout << std::is_same<float, std::int32_t>::value << '\n';

  print_separator();

  std::cout << std::is_same<int, int>::value << '\n';
  std::cout << std::is_same<int, unsigned int>::value << '\n';
  std::cout << std::is_same<int, signed int>::value << '\n';

  print_separator();

  std::cout << std::is_same<char, char>::value << '\n';
  std::cout << std::is_same<char, unsigned char>::value << '\n';
  std::cout << std::is_same<char, signed char>::value << '\n';

  return 0;
}

