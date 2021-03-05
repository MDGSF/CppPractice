#include <iostream>

using namespace std;

template <class T>
class Test {
 public:
  Test() { m_count++; }
  static int m_count; // 每种具体类型都有一个独立的静态变量

 private:
  T m_val;
};

template <class T>
int Test<T>::m_count = 0;

int main() {
  Test<int> a;
  Test<int> b;
  Test<double> c;
  cout << Test<int>::m_count << endl;
  cout << Test<double>::m_count << endl;
  return 0;
}
