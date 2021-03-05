#include <iostream>

using namespace std;

template <class T, class U = char>
class A {
 public:
  A() { cout << "constructor" << endl; }

 private:
  T x;
  U y;
};

int main() {
  A<char> a;
  A<int, double> b;
  return 0;
}
