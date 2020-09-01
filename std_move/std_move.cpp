/*
std::move 这个方法将左值参数无条件的转换为右值
*/

#include <iostream>
#include <string>

void reference(std::string& str) {
  std::cout << " left value" << std::endl;
}

void reference(std::string&& str) {
  std::cout << " right value" << std::endl;
}

int main() {
  std::string lv1 = "string,"; // left value

  // error: rvalue reference to type 'basic_string<...>' cannot
  // bind to lvalue of type 'basic_string<...>'
  // std::string&& rv1 = lv1;

  // std::move 将左值转换为右值
  std::string&& rv1 = std::move(lv1);
  std::cout << rv1 << std::endl;

  const std::string& lv2 = lv1 + lv1;
  std::cout << lv2 << std::endl;

  std::string&& rv2 = lv1 + lv2;
  rv2 += "Test";
  std::cout << rv2 << std::endl;

  // rv2 虽然引用了一个右值，但由于它是一个引用，所以 rv2 是一个左值。
  reference(rv2);
  return 0;
}
