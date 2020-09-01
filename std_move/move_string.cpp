#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main() {
  std::string str = "Hello World.";
  std::vector<std::string> v;

  // 将使用 push_back(const T&), 产生拷贝行为
  v.push_back(str);
  std::cout << "str: " << str << std::endl;

  // 将使用 push_back(const T&&)，不会出现拷贝行为
  // 这步操作之后，str 中的值会变成空
  v.push_back(std::move(str));
  std::cout << "str: " << str << std::endl;
  return 0;
}
