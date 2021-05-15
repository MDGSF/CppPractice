#include <iostream>
#include <vector>
#include <cstring>

// 声明
template <typename T>
std::size_t count(const std::vector<T>& vec, T value);

template <>
std::size_t count(const std::vector<const char*>& vec, const char* value);

// 定义
template <typename T>
std::size_t count(const std::vector<T>& vec, T value) {
  std::size_t count = 0;
  for (auto& item : vec) {
    count += (item == value) ? 1 : 0;
  }
  return count;
}

template <>
std::size_t count(const std::vector<const char*>& vec, const char* value) {
  std::size_t count = 0;
  for (auto& item : vec) {
    count += (strcmp(item, value) == 0) ? 1 : 0;
  }
  return count;
}

int main() {
  std::vector<int> vi = { 1, 1, 1, 2, 3, 4 };
  std::cout << count(vi, 1) << std::endl;

  std::vector<const char*> vec = {"alan", "alan", "moophy"};
  std::cout << count(vec, "alan") << std::endl;
  return 0;
}
