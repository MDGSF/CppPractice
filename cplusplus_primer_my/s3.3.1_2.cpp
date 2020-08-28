#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

void show(const vector<string>& v) {
  std::cout << "size = " << v.size() << ", value = [ ";
  for (auto e : v) {
    std::cout << e << " ";
  }
  std::cout << "]" << std::endl;
}

int main() {
  vector<string> v5{"hi"};
  // vector<string> v6("hi"); // error
  vector<string> v7{10};        // v7有10个默认初始化的元素
  vector<string> v8{10, "hi"};  // v8有10个值为"hi"的元素

  show(v5);
  show(v7);
  show(v8);
  return 0;
}
