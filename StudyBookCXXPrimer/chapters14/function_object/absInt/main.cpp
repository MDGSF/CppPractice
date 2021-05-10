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

struct absInt {
  int operator()(int val) const {
    return val < 0 ? -val : val;
  }
};

int main() {
  cout << "hello world!" << endl;
  int i = -86;
  absInt absObj;
  int ui = absObj(i);
  cout << ui << endl;
  return 0;
}
