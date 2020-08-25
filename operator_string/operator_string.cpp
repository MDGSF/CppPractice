#include <iostream>
#include <string>

struct MyStr {
 public:
  // 自动转换为 std::string
  operator std::string() { return "MyStr"; }
};

int main() {
  MyStr str;
  std::string s = str;
  std::cout << s << std::endl;
  return 0;
}
