#include <iostream>

namespace test1 {
void print1() {
  std::cout << "print1" << std::endl;
}
}

namespace test2 {
  void f2() {
    test1::print1();
  }
}

int main() {
  //test1::print1();
  test2::f2();
  return 0;
}
