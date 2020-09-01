#include <array>
#include <iostream>
#include <algorithm>

void foo(int *p, int len) {
  return;
}

int main() {
  std::array<int, 4> arr = {1, 2, 3, 4};
  std::cout << arr.empty() << std::endl;
  std::cout << arr.size() << std::endl;

  for (auto &i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::sort(arr.begin(), arr.end(), [](int a, int b) { return b < a; });

  // foo(arr, arr.size()); // 非法，隐式转换
  foo(&arr[0], arr.size());
  foo(arr.data(), arr.size());
  return 0;
}
