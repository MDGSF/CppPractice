#include <iostream>

struct C {
  C() { std::cout << "constructed\n"; }
  C(const C&) { std::cout << "copy-constructed.\n"; }
  C(C&&) { std::cout << "move-constructed.\n"; }
  ~C() { std::cout << "destructed\n"; }
};

C f() { return C(); }

C g() {
  C c;
  return c;  // Maybe performs copy elision
}

int main() {
  C obj1 = f();
  C obj2 = g();
}
