#include <iostream>
#include <string>

template <typename T = std::string>
void f(T a = "") {
  std::cout << a << std::endl;
}

int main() {
  f(1);
  f();
  return 0;
}
