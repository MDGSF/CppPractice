#include <iostream>

struct type {
  int i;

  type() : i(3) {}

  void f(int v) const {
    // error: cannot assign to non-static data member within const member
    // function 'f'
    // this->i = v;
    const_cast<type*>(this)->i = v;
  }
};

int main() {
  int i = 3;
  const int& rci = i;
  const_cast<int&>(rci) = 4;
  std::cout << "i = " << i << std::endl;

  // if this was const type t, then t.f(4) would be undefined behavior
  type t;
  t.f(4);
  std::cout << "type::i = " << t.i << std::endl;

  const int j = 3;  // j is declared const
  int* pj = const_cast<int*>(&j);
  //*pj = 4; // undefined behavior

  void (type::*pmf)(int) const = &type::f;  // pointer to member function
  // const_cast<void(type::*)(int)>(pmf);   // compile error: const_cast does
  // not work on function pointers
  return 0;
}
