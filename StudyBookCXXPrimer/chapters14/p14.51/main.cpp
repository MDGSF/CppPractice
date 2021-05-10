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

struct LongDouble {
  LongDouble(double = 0.0) {}
  operator double() {
    std::cout << "operator double()" << std::endl;
    return 0;
  }
  operator float() {
    std::cout << "operator float()" << std::endl;
    return 0;
  }
};

void calc(int) {
  std::cout << "void calc(int)" << std::endl;
}

void calc(LongDouble) {
  std::cout << "void calc(LongDouble)" << std::endl;
}

int main() {
  double dval = 0;
  calc(dval);
  return 0;
}
