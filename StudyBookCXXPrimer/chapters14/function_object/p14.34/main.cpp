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

class IfThenElse {
 public:
   typedef int value_type;
   value_type operator()(bool condition, value_type t, value_type f) const {
     return condition ? t : f;
   }
};

int main() {
  cout << "hello world!" << endl;
  int n;
  std::cin >> n;
  std::cout << IfThenElse()(n > 0, 1, -1) << std::endl;
  return 0;
}
