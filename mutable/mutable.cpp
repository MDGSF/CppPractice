#include <iostream>

int main() {
  int n1 = 0;           // non-const object
  const int n2 = 0;     // const object
  int const n3 = 0;     // const object (same as n2)
  volatile int n4 = 0;  // volatile object
  const struct {
    int n1;
    mutable int n2;
  } x = {0, 0};  // const object with mutable member

  n1 = 1;
  // n2 = 2;
  n4 = 3;
  // x.n1 = 4; // error: member of a const object is const
  x.n2 = 4;  // ok, mutable member of a const object isn't const

  const int& r1 = n1;
  // error: cannot assign to variable 'r1' with const-qualified
  // type 'const int &'
  // r1 = 2;
  const_cast<int&>(r1) = 2;  // ok, modify non-const object n1

  const int& r2 = n2;
  // r2 = 2;

  // undefined behavior: attempt to modify const
  // object n2
  // const_cast<int&>(r2) = 2;
  return 0;
}
