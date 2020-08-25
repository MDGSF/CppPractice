#include <iostream>

struct A {
  A(int first) { std::cout << "A " << first << std::endl; }
  A(int first, int second) {
    std::cout << "A " << first << " " << second << std::endl;
  }
  operator bool() const {
    std::cout << "A operator bool\n";
    return true;
  }
};

struct B {
  explicit B(int first) { std::cout << "B " << first << std::endl; }
  explicit B(int first, int second) {
    std::cout << "A " << first << " " << second << std::endl;
  }
  explicit operator bool() const {
    std::cout << "B operator bool\n";
    return true;
  }
};

int main() {
  A a1 = 1;
  A a2(2);
  A a3{4, 5};
  A a4 = {4, 5};
  A a5 = (A)6;
  if (a1) {
  }
  bool na1 = a1;
  bool na2 = static_cast<bool>(a1);

  // B b1 = 1;
  B b2(2);
  B b3{4, 5};
  // B b4 = {4, 5};
  B b5 = (B)6;
  if (b2) {
  }
  // bool nb1 = b2;
  bool nb2 = static_cast<bool>(b2);
  return 0;
}
