#include <iostream>

using std::cout;
using std::endl;

class Base {
 public:
  virtual int fcn() {
    cout << "Base::fcn" << endl;
    return 0;
  }
};

class D1 : public Base {
 public:
  int fcn() override {
    cout << "D1::fcn" << endl;
    return 0;
  }

  virtual void f2() {
    cout << "D1::f2" << endl;
  }
};

class D2 : public D1 {
 public:
  int fcn(int) {
    cout << "D2::fcn(int)" << endl;
    return 0;
  }

  int fcn() {
    cout << "D2::fcn" << endl;
    return 0;
  }

  void f2() {
    cout << "D2::f2" << endl;
  }
};

int main() {
  Base bobj;
  D1 d1obj;
  D2 d2obj;
  Base *bp1 = &bobj;
  Base *bp2 = &d1obj;
  Base *bp3 = &d2obj;

  bp1->fcn();
  bp2->fcn();
  bp3->fcn();
  return 0;
}
