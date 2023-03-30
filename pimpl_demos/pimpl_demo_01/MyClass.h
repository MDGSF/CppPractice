#ifndef MY_CLASS_h_
#define MY_CLASS_h_

class MyClass {
 public:
  MyClass();
  ~MyClass();
  void some_function();

 private:
  class Impl;
  Impl *pimpl;
};

#endif
