#include <iostream>

using namespace std;

template <typename T1, typename T2>
class X {};

// 部分特化
template <typename T1>
class X<T1, int> {};

int main() {
  X<char, char> a;
  X<char, int> b;
  return 0;
}
