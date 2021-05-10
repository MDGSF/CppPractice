// Copyright 2021 <HuangJian 1342042894@qq.com>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream>  // ifstream
#include <functional>  // function object, bind
#include <iostream>  // cin, cout, cerr
#include <iterator>
#include <list>
#include <map>
#include <memory>  // unique_ptr, shared_ptr, weak_ptr
#include <set>
#include <sstream>  // istringstream
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;

class SmallInt {
  friend SmallInt operator+(const SmallInt&, const SmallInt&);
 public:
  SmallInt(int = 0) {}
  operator int() const { return val; }
 private:
  std::size_t val = 0;
};

SmallInt operator+(const SmallInt&, const SmallInt&) {
  std::cout << "SmallInt operator+(const SmallInt&, const SmallInt&)" << std::endl;
  return SmallInt();
}

int main() {
  SmallInt s1;
  // double d = s1 + 3.14;
  double d = static_cast<double>(s1) + 3.14;
  double d2 = s1 + SmallInt(3.14);
  return 0;
}
