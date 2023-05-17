/*
std::pop_heap(begin_interator, end_iterator);
时间复杂度：O(log(n))
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
  std::vector<int> v1 = { 40, 10, 20, 50, 30 };
  show("raw array", v1);

  // 最大堆
  std::make_heap(v1.begin(), v1.end());
  show("make heap", v1);

  std::pop_heap(v1.begin(), v1.end()); // 把最大元素移动到数组末尾
  show("pop heap", v1);
  v1.pop_back(); // 删除数组末尾元素
  show("pop back", v1);

  return 0;
}
