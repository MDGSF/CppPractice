#include <iostream>

void test1() {
  const int ci = 0;
  const int &cj = ci;
  decltype(ci) x = 0;  // equal to: const int x = 0;
  decltype(cj) y = x;  // equal to: const int &y = x;
  // decltype(cj) z;   // euqal to: const int &z;
}

void test2() {
  int i = 42;
  int *p = &i;
  int &r = i;
  decltype(r + 0) b;  // equal to: int b;
  // decltype(*p) c;  // equal to: int &c;

  // decltype((i)) d; //equal to: int &d;
  decltype(i) d;  // equal to: int d;

  // decltype((variable))的结果永远是引用。
  // decltype(variable) 只有当variable是引用时才是引用
}

int main() {
  test1();
  test2();
  return 0;
}
