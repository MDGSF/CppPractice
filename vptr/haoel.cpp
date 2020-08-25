#include <iostream>

typedef void (*Fun)(void);

class Base {
 public:
  virtual void f() { std::cout << "Base::f()" << std::endl; }
  virtual void g() { std::cout << "Base::g()" << std::endl; }
  virtual void h() { std::cout << "Base::h()" << std::endl; }
};

class Derived1 : public Base {
 public:
  virtual void f1() { std::cout << "Derived1::f1()" << std::endl; }
  virtual void g1() { std::cout << "Derived1::g1()" << std::endl; }
  virtual void h1() { std::cout << "Derived1::h1()" << std::endl; }
};

class Derived2 : public Base {
 public:
  virtual void f() { std::cout << "Derived2::f()" << std::endl; }
  virtual void g1() { std::cout << "Derived2::g1()" << std::endl; }
  virtual void h1() { std::cout << "Derived2::h1()" << std::endl; }
};

void showBase() {
  Base b;
  std::cout << "sizeof(Base) = " << sizeof(Base) << std::endl;  // 8
  std::cout << "sizeof(b) = " << sizeof(b) << std::endl;        // 8
  std::cout << "b's virtual table address = " << (int64_t*)(&b) << std::endl;

  int64_t* p1FunctionAddress = (int64_t*)*(int64_t*)(&b);
  int64_t* p2FunctionAddress = p1FunctionAddress + 1;
  int64_t* p3FunctionAddress = p1FunctionAddress + 2;
  int64_t* pEnd = p1FunctionAddress + 3;

  Fun p1Function = (Fun)*p1FunctionAddress;  // Base::f()
  Fun p2Function = (Fun)*p2FunctionAddress;  // Base::g()
  Fun p3Function = (Fun)*p3FunctionAddress;  // Base::h()

  std::cout << "b's virtual table[0][0] address = " << p1FunctionAddress
            << ", function address = " << *p1FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][1] address = " << p2FunctionAddress
            << ", function address = " << *p2FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][2] address = " << p3FunctionAddress
            << ", function address = " << *p3FunctionAddress << std::endl;
  std::cout << "b's virtual table end address = " << pEnd
            << ", end value = " << *pEnd << std::endl;

  p1Function();  // Base::f()
  p2Function();  // Base::g()
  p3Function();  // Base::h()

  std::cout << std::endl;
}

void showDerived1() {
  Derived1 d1;
  std::cout << "sizeof(Derived1) = " << sizeof(Derived1) << std::endl;  // 8
  std::cout << "sizeof(d1) = " << sizeof(d1) << std::endl;              // 8
  std::cout << "d1's virtual table address = " << (int64_t*)(&d1) << std::endl;

  int64_t* p1FunctionAddress = (int64_t*)*(int64_t*)(&d1);
  int64_t* p2FunctionAddress = p1FunctionAddress + 1;
  int64_t* p3FunctionAddress = p1FunctionAddress + 2;
  int64_t* p4FunctionAddress = p1FunctionAddress + 3;
  int64_t* p5FunctionAddress = p1FunctionAddress + 4;
  int64_t* p6FunctionAddress = p1FunctionAddress + 5;
  int64_t* pEnd = p1FunctionAddress + 6;

  Fun p1Function = (Fun)*p1FunctionAddress;  // Base::f()
  Fun p2Function = (Fun)*p2FunctionAddress;  // Base::g()
  Fun p3Function = (Fun)*p3FunctionAddress;  // Base::h()
  Fun p4Function = (Fun)*p4FunctionAddress;  // Derived1::f1()
  Fun p5Function = (Fun)*p5FunctionAddress;  // Derived1::g1()
  Fun p6Function = (Fun)*p6FunctionAddress;  // Derived1::h1()

  std::cout << "b's virtual table[0][0] address = " << p1FunctionAddress
            << ", function address = " << *p1FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][1] address = " << p2FunctionAddress
            << ", function address = " << *p2FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][2] address = " << p3FunctionAddress
            << ", function address = " << *p3FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][3] address = " << p4FunctionAddress
            << ", function address = " << *p4FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][4] address = " << p5FunctionAddress
            << ", function address = " << *p5FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][5] address = " << p6FunctionAddress
            << ", function address = " << *p6FunctionAddress << std::endl;

  std::cout << "b's virtual table end address = " << pEnd
            << ", end value = " << *pEnd << std::endl;

  p1Function();  // Base::f()
  p2Function();  // Base::g()
  p3Function();  // Base::h()
  p4Function();  // Derived1::f1()
  p5Function();  // Derived1::g1()
  p6Function();  // Derived1::h1()

  std::cout << std::endl;
}

void showDerived2() {
  Derived2 d2;
  std::cout << "sizeof(Derived2) = " << sizeof(Derived2) << std::endl;  // 8
  std::cout << "sizeof(d2) = " << sizeof(d2) << std::endl;              // 8
  std::cout << "d2's virtual table address = " << (int64_t*)(&d2) << std::endl;

  int64_t* p1FunctionAddress = (int64_t*)*(int64_t*)(&d2);
  int64_t* p2FunctionAddress = p1FunctionAddress + 1;
  int64_t* p3FunctionAddress = p1FunctionAddress + 2;
  int64_t* p4FunctionAddress = p1FunctionAddress + 3;
  int64_t* p5FunctionAddress = p1FunctionAddress + 4;
  int64_t* pEnd = p1FunctionAddress + 5;

  Fun p1Function = (Fun)*p1FunctionAddress;  // Derived2::f()
  Fun p2Function = (Fun)*p2FunctionAddress;  // Base::g()
  Fun p3Function = (Fun)*p3FunctionAddress;  // Base::h()
  Fun p4Function = (Fun)*p4FunctionAddress;  // Derived2::f1()
  Fun p5Function = (Fun)*p5FunctionAddress;  // Derived2::g1()

  std::cout << "b's virtual table[0][0] address = " << p1FunctionAddress
            << ", function address = " << *p1FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][1] address = " << p2FunctionAddress
            << ", function address = " << *p2FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][2] address = " << p3FunctionAddress
            << ", function address = " << *p3FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][3] address = " << p4FunctionAddress
            << ", function address = " << *p4FunctionAddress << std::endl;
  std::cout << "b's virtual table[0][4] address = " << p5FunctionAddress
            << ", function address = " << *p5FunctionAddress << std::endl;

  std::cout << "b's virtual table end address = " << pEnd
            << ", end value = " << *pEnd << std::endl;

  p1Function();  // Derived2::f()
  p2Function();  // Base::g()
  p3Function();  // Base::h()
  p4Function();  // Derived2::f1()
  p5Function();  // Derived2::g1()

  std::cout << std::endl;
}

int main() {
  showBase();
  showDerived1();
  showDerived2();
  return 0;
}
