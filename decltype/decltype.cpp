#include <iostream>
#include <vector>

void f(const std::vector<int>& a, const std::vector<float>& b) {
  typedef decltype(a[0] * b[0]) Tmp;
  for (int i = 0; i < b.size(); i++) {
    Tmp* p = new Tmp(a[i] * b[i]);
    std::cout << *p << '\n';
    delete (p);
  }
}

int main() {
  std::vector<int> a = {1, 2, 3};
  std::vector<float> b = {4.0, 5., 6.};
  f(a, b);
  return 0;
}
