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

class Foo {
 public:
  Foo() = default;
  Foo(std::initializer_list<int> il) : data(il) {}

  Foo sorted() &&;
  Foo sorted() const &;

  void print() const;

 private:
  std::vector<int> data;
};

Foo Foo::sorted() && {
  std::cout << "Foo Foo::sorted() &&" << std::endl;
  std::sort(data.begin(), data.end());
  return *this;
}

/*
// version 1
Foo Foo::sorted() const & {
  std::cout << "Foo Foo::sorted() const &" << std::endl;
  Foo ret(*this);
  std::sort(ret.data.begin(), ret.data.end());
  return ret;
}
*/

/*
// version 2, 错误，因为ret是左值，会导致无限递归调用自己
Foo Foo::sorted() const & {
  std::cout << "Foo Foo::sorted() const &" << std::endl;
  Foo ret(*this);
  return ret.sorted();
}
*/

Foo Foo::sorted() const & {
  std::cout << "Foo Foo::sorted() const &" << std::endl;
  return Foo(*this).sorted();
}

void Foo::print() const {
  std::cout << "<" << this << ">";
  for (const auto &i : data) {
    std::cout << " " << i;
  }
  std::cout << std::endl;
}

int main() {
  cout << "hello world!" << endl;
  Foo f1;
  f1.print();

  Foo f2{9, 6, 1, 3, 2, 5};
  f2.print();

  Foo f3 = f2.sorted();
  f2.print();
  f3.print();

  Foo f4 = Foo({2, 3, 1, 4, 9, 5}).sorted();
  f4.print();

  return 0;
}
