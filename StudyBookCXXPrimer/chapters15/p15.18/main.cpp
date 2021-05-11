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

class Base {
 public:
  void pub_mem();

 protected:
  int prot_mem;

 private:
  char priv_mem;
};

struct Pub_Derv : public Base {
  // 正确：派生类可以访问protected成员
  int f() { return prot_mem; }

  // 错误：派生类不可以访问private成员
  // char g() { return priv_mem; }
};

struct Priv_Derv : private Base {
  // ok: private derivation doesn’t affect access in the derived class
  int f() { return prot_mem; }
  // error: private members are inaccessible to derived classes
  // char g() { return priv_mem; }
};

struct Prot_Derv : protected Base {
  // ok: derived classes can access protected members
  int f() { return prot_mem; }
  // error: private members are inaccessible to derived classes
  //char g() { return priv_mem; }
};

int main() {
  cout << "hello world!" << endl;
  return 0;
}
