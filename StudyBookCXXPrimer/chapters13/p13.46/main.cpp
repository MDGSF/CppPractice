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

int f() { return 0; }

int main() {
  cout << "hello world!" << endl;

  std::vector<int> vi(100);

  int &&r1 = f();
  int &r2 = vi[0];
  int &r3 = r1;
  int &&r4 = vi[0] * f();

  return 0;
}
