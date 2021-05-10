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

struct Equal {
  typedef int ty;
  Equal(ty v): val(v) {}
  bool operator()(ty rhs) {
    return val == rhs;
  }
 private:
  ty val;
};

int main() {
  std::vector<int> vi { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int oldVal, newVal;
  std::cin >> oldVal >> newVal;
  std::replace_if(vi.begin(), vi.end(), Equal(oldVal), newVal);
  for (const auto &i : vi)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
