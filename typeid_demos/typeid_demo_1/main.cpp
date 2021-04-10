#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

struct Base {};
struct Derived: Base {};

struct Base2 {
  virtual void foo() {}
};
struct Derived2 : Base2 {};

int main() {
  int myint = 50;
  string mystr = "string";
  double *mydoubleptr = nullptr;
  cout << "myint has type: " << typeid(myint).name() << endl;
  cout << "mystr has type: " << typeid(mystr).name() << endl;
  cout << "mydoubleptr has type: " << typeid(mydoubleptr).name() << endl;

  if (typeid(myint) == typeid(int)) {
    cout << "typeid(myint) == typeid(int)" << endl;
  } else {
    cout << "typeid(myint) != typeid(int)" << endl;
  }

  const std::type_info& r1 = typeid(cout << myint);
  cout << "cout << myint has type: " << r1.name() << endl;

  return 0;
}
