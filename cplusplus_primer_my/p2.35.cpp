#include <iostream>

int main() {
  const int i = 42;
  auto j = i;
  const auto &k = i;
  auto *p = &i;  // equal to: const int *p = &i;
  const auto j2 = i;
  const auto &k2 = i;
  return 0;
}
