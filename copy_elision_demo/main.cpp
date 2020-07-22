#include <stdio.h>
#include <iostream>

using namespace::std;

struct C {
  C() {}
  C(const C&) { std::cout << "A copy was made.\n"; }
};

C f() {
  return C();
}

C g() {
  C c;
  return c; //Maybe performs copy elision
}

int main() {
  std::cout << "Hello World!\n";
  C obj = g();
}
