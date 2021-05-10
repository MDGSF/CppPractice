// Copyright 2021 <HuangJian 1342042894@qq.com>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream>  // ifstream
#include <functional>  // function object, bind
#include <iostream>  // cin, cout, cerr
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

int main() {
  using namespace std::placeholders;
  int n;
  std::cin >> n;
  std::vector<int> vi { 12, 34, 56, 78, 90, 123, 456, 789 };
  auto it = std::find_if_not(vi.begin(), vi.end(),
      std::bind(std::modulus<int>(), _1, n));
  if (it != vi.end()) {
    std::cout << n << " is divisible by " << *it << std::endl;
  } else {
    std::cout << "Find nothing." << std::endl;
  }
  return 0;
}
