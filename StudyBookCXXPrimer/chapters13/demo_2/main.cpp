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
  A() { cout << "A constructor" << endl; }
  ~A() { cout << "A destructor" << endl; }
};

class B {
 public:
  B() { cout << "B constructor" << endl; }
  ~B() { cout << "B destructor" << endl; }

 private:
  A a_;
};

int main() {
  cout << "hello world!" << endl;
  B b;
  return 0;
}
