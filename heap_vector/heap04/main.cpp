/*
std::sort_heap(begin_iterator, end_iterator);
如果数组是一个堆，则可以用sort_heap对数组进行排序
时间复杂度：O(nlogn)
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

  // 最大堆
  std::make_heap(v1.begin(), v1.end());
  show("make heap", v1);

  // 用堆排序算法对数组v1进行排序，从小到大
  std::sort_heap(v1.begin(), v1.end());
  show("sort heap", v1);
  return 0;
}
