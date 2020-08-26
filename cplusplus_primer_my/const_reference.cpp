
/*
下面代码等价于：
const int temp = dval;
const int &ri = temp;
*/
#include <iostream>

int main() {
  double dval = 3.14;
  const int& ri = dval;
  std::cout << ri << std::endl;
  return 0;
}
