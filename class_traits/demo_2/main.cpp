// Copyright 2021 <HuangJian 1342042894@qq.com>
#include <math.h>
#include <stdio.h>
#include <assert.h>

#include <algorithm>
#include <fstream>     // ifstream
#include <functional>  // function object, bind
#include <iostream>    // cin, cout, cerr
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

// http://www.gotw.ca/publications/mxc++-item-4.htm
// 判断 D 是不是继承自 B
template <typename D, typename B>
class IsDerivedFrom {
  class No {};
  class Yes {
    No no[3];
  };

  static Yes Test(B*);  // not defined
  static No Test(...);  // not defined

  static void Constraints(D* p) {
    B* pb = p;
    pb = p;
  }

 public:
  enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) };

  IsDerivedFrom() { void (*p)(D*) = Constraints; }
};

class Base {};

// class Derived {};
class Derived : public Base {};

template <typename T>
class X : IsDerivedFrom<T, Base> {
  // ...
};

template <typename T>
class X2 {
  bool ValidateRequirements() const {
    // typedef needed because otherwise the , will be
    // interpreted as delimiting macro parameters to assert
    typedef IsDerivedFrom<T, Base> Y;

    // a runtime check, but one that can be turned
    // into a compile-time check without much work
    assert(Y::Is);

    return true;
  }

 public:
  // in X2’s destructor (easier than putting it
  // in every X2 constructor):
  ~X2() { assert(ValidateRequirements()); }

  // ...
};

int main(int argc, char* argv[]) {
  X<Derived> x1;
  X2<Derived> x2;
  return 0;
}

