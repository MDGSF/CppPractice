// Copyright 2021 <HuangJian 1342042894@qq.com>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream>     // ifstream
#include <functional>  // function object
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

int main() {
  using namespace std::placeholders;

  std::vector<int> vi{1000, 2000, 3000, 4000, 5000};
  std::cout << std::count_if(vi.begin(), vi.end(),
                             std::bind(std::greater<int>(), _1, 1024))
            << std::endl;

  std::vector<std::string> vs{"pooh", "pooh", "abc", "pooh"};
  std::cout << *std::find_if(
                   vs.begin(), vs.end(),
                   std::bind(std::not_equal_to<std::string>(), _1, "pooh"))
            << std::endl;

  std::transform(vi.begin(), vi.end(), vi.begin(),
      std::bind(std::multiplies<int>(), _1, 2));
  for (const auto &i : vi) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  return 0;
}
