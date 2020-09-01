#include <iostream>

template <auto value>
void foo() {
  std::cout << value << std::endl;
  return;
}

int main() {
  foo<10>();
}
