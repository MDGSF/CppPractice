#include <iostream>

int main() {
  int a[10] = {0};
  for (int i = 0; i < 10; i++) {
    a[i] = i;
  }

  int b[10] = {0};
  for (int i = 0; i < 10; i++) {
    b[i] = a[i];
  }

  for (auto e : b) {
    std::cout << e << std::endl;
  }
  return 0;
}
