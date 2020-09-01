#include <iostream>
#include <memory>

struct A;
struct B;

struct A {
  std::shared_ptr<B> pointer;
  ~A() {
    std::cout << "A destructor" << std::endl;
  }
};

struct B {
  std::shared_ptr<A> pointer;
  ~B() {
    std::cout << "B destructor" << std::endl;
  }
};

int main() {
  auto a = std::make_shared<A>();
  auto b = std::make_shared<B>();
  a->pointer = b;
  b->pointer = a;
  return 0;
}
