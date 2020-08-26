#include <iostream>

constexpr int *np = nullptr;
int j = 0;
constexpr int i = 42;
constexpr const int *p = &i;
constexpr int *p1 = &j;  // p1 是常量指针，修改 p1 的值

int main() {
  *p1 = 100;
  std::cout << j << std::endl;
  return 0;
}
