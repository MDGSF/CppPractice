#include "public.h"

void test1() {
  std::vector<int> result;
  int num;
  while (std::cin >> num) {
    result.push_back(num);
  }

  for (decltype(result.size()) i = 1; i < result.size(); i++) {
    std::cout << result[i - 1] + result[i] << std::endl;
  }
}

void test2() {
  std::vector<int> result;
  int num;
  while (std::cin >> num) {
    result.push_back(num);
  }

  for (decltype(result.size()) i = 0; i <= result.size() / 2; i++) {
    std::cout << result[i] + result[result.size() - 1 - i] << std::endl;
  }
}

int main() {
  test2();
  return 0;
}
