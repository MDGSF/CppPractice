/*
std::make_heap(begin_iterator, end_iterator, compare);
时间复杂度：O(n)
*/

#include <algorithm>
#include <iostream>
#include <vector>

void show(const std::string& name, const std::vector<int>& array) {
  std::cout << name << ":[ ";
  for (auto item : array) {
    std::cout << item << " ";
  }
  std::cout << "]" << std::endl;
}

int main() {
  std::vector<int> v1 = { 20, 30, 40, 25, 15 };
  show("raw array", v1);

  // 最小堆
  std::make_heap(v1.begin(), v1.end(), [](int a, int b) { return a > b; });
  show("make heap", v1);

  std::cout << "The minimum element of heap is: " << v1.front() << std::endl;
  return 0;
}
