#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main() {
  vector<int> v1;
  std::cout << v1.size() << std::endl;  // 0
  vector<int> v2(10);
  std::cout << v2.size() << std::endl;  // 10
  vector<int> v3(10, 42);
  std::cout << v3.size() << std::endl;  // 10
  vector<int> v4{10};
  std::cout << v4.size() << std::endl;  // 1
  vector<int> v5{10, 42};
  std::cout << v5.size() << std::endl;  // 2
  vector<string> v6{10};
  std::cout << v6.size() << std::endl;  // 10
  vector<string> v7{10, "hi"};
  std::cout << v7.size() << std::endl;  // 10
  return 0;
}
