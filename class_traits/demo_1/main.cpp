// Copyright 2021 <HuangJian 1342042894@qq.com>
#include <math.h>
#include <stdio.h>

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

// HasClone requires that T must provide
// T* T::Clone() const
template <typename T>
class HasClone {
 public:
  static void Constraints() {
    T* (T::*test)() const = &T::Clone;
    test;  // suppress warnings about unused variables
  }
  HasClone() { void (*p)() = Constraints; }
};

template <typename T>
class C : HasClone<T> {
  // ...
};

class A {
 public:
  A* Clone() const { return nullptr; };
};

int main(int argc, char* argv[]) {
  C<A> c;
  return 0;
}

