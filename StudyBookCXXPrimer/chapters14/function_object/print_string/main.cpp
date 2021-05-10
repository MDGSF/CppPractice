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
using std::cerr;
using std::endl;
using std::ostream;
using std::string;

class PrintString {
 public:
  PrintString(ostream &o = cout, char c = ' ') : os(o), sep(c) {}

  void operator()(const string &s) const { os << s << sep; }

 private:
  ostream &os;
  char sep;
};

int main() {
  cout << "hello world!" << endl;
  PrintString cc;
  cc("a");
  cc("b");
  cc("c");

  PrintString err(cerr, '\n');
  err("x");
  err("y");
  err("z");
  return 0;
}
