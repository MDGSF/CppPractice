// 在编译期间就计算好了

#include <iostream>

using namespace std;

// 2 ^ n
template <int n>
struct fun {
  enum { val = 2 * fun<n - 1>::val };
};

template <>
struct fun<0> {
  enum { val = 1 };
};

int main() {
  cout << fun<8>::val << endl;
  return 0;
}
