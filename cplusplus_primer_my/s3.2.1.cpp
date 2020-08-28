#include <iostream>
#include <string>

int main() {
  std::string s1;  // 默认初始化，s1是一个空字符串
  std::string s2(s1);
  std::string s3 = s1;
  std::string s4("value");   // 直接初始化
  std::string s5 = "value";  // 拷贝初始化
  std::string s6(10, 'c');   // 直接初始化

  // 等价于：
  // std::string temp(10, 'c');
  // std::string s7 = temp;
  std::string s7 = std::string(10, 'c');  // 拷贝初始化
  return 0;
}
