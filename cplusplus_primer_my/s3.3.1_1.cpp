#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::vector;

void show(const vector<int>& v) {
  for (auto e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

int main() {
  vector<int> v1(10);  // v1有10个元素，每个元素都是0
  vector<int> v2{10};  // v2有1个元素，该元素的值是10

  vector<int> v3(10, 1);  // v3有10个元素，每个元素都是1
  vector<int> v4{10, 1};  // v4有2个元素，值分别是10和1

  show(v1);
  show(v2);
  show(v3);
  show(v4);
  return 0;
}
