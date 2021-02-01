#include <iostream>

using namespace std;

template <int N>
struct fib {
  static const int val = fib<N - 1>::val + fib<N - 2>::val;
};

template <>
struct fib<0> {
  static const int val = 0;
};

template <>
struct fib<1> {
  static const int val = 1;
};

int main() {
  cout << fib<2>::val << endl;
  cout << fib<3>::val << endl;
  cout << fib<4>::val << endl;
  cout << fib<5>::val << endl;
  return 0;
}
