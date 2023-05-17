/*
std::push_heap(begin_interator, end_iterator);
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
  std::vector<int> v1 = { 20, 30, 40, 10 };
  show("raw array", v1);

  // 最大堆
  std::make_heap(v1.begin(), v1.end());
  show("make heap", v1);

  v1.push_back(50); // 向数组末尾插入一个元素
  std::push_heap(v1.begin(), v1.end()); // 把数组末尾的元素也添加到堆中
  show("push heap", v1);

  return 0;
}
