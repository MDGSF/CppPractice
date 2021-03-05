// Each instantiation of function template has its own copy of local static variables

#include <iostream>

using namespace std;

template <typename T>
void fun(const T& x) {
  static int i = 10;
  ++i;
  cout << i << endl;;
}

int main() {
  fun<int>(1);
  fun<int>(2);
  fun<double>(3);
  return 0;
}
