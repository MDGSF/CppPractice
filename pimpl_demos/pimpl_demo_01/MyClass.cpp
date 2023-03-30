#include "MyClass.h"
#include <iostream>

class MyClass::Impl {
 public:
  void some_private_function();

 private:
};

MyClass::MyClass() : pimpl(new Impl) {}

MyClass::~MyClass() { delete pimpl; }

void MyClass::some_function() { pimpl->some_private_function(); }

void MyClass::Impl::some_private_function() {
  std::cout << "some private function" << std::endl;
}
