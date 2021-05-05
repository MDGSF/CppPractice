// Copyright 2021 <HuangJian 1342042894@qq.com>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream>  // ifstream
#include <iostream>
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

class A {
 public:
  A() { cout << "A constructor 1, i = " << i_ << endl; }
  A(int i) : i_(i) { cout << "A constructor 2, i = " << i_ << endl; }
  ~A() { cout << "A destructor, i = " << i_ << endl; }

  A(const A& other) {
    cout << "A copy constructor, other.i = " << other.i_ << endl;
    i_ = other.i_ + 1;
  }
  A& operator=(const A& other) {
    cout << "A copy-assignment operator, other.i = " << other.i_ << endl;
    i_ = other.i_ + 2;
    return *this;
  }

 private:
  int i_ = 0;
};

int main() {
  cout << "hello world!" << endl;
  A a(1);
  A b;
  b = a;
  return 0;
}
