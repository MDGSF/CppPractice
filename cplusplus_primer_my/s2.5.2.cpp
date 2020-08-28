#include <iostream>

int main() {
  int i = 0;
  int &r = i;
  auto a = r;

  const int ci = i;
  const int &cr = ci;
  auto b = ci;   // equal to: int b = ci;
  auto c = cr;   // equal to: int c = cr;
  auto d = &i;   // equal to: int *d = &i;
  auto e = &ci;  // equal to: const int *e = &ci;

  const auto f = ci;  // equal to: const int f = ci;

  auto &g = ci;  // equal to: const int &g = ci;
  // auto &h = 42;  // equal to: int &h = 42;
  const auto &j = 42;  // equal to: const int &j = 42;
  return 0;
}
