#include <iostream>

int main() {
  int a = 10;
  int b = 20;

  const int *p1 = &a;
  std::cout << "*p1 = " << *p1 << std::endl;

  p1 = &b;
  std::cout << "*p1 = " << *p1 << std::endl;

  // *p1 = 100; // error: read-only variable is not assignable

  int *const p2 = &a;
  std::cout << "*p2 = " << *p2 << std::endl;

  // p2 = &b;
  // error: cannot assign to variable 'p2' with const-qualified type
  // 'int *const'

  *p2 = 100;
  std::cout << "*p2 = " << *p2 << std::endl;
  return 0;
}
