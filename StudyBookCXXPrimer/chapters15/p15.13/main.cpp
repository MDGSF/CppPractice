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

class base {
 public:
  std::string name() { return basename; }
  virtual void print(std::ostream &os) { os << basename; }

 private:
  std::string basename;
};

class derived : public base {
 public:
  void print(std::ostream &os) {
    // 使用print(os)的话，会调用派生类的print，导致无限递归
    // print(os);
    base::print(os);
    os << " " << i;
  }

 private:
  int i;
};

int main() {
  cout << "hello world!" << endl;
  derived d;
  d.print(std::cout);
  return 0;
}
