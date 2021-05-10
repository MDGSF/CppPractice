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

class StrRange {
 public:
  StrRange(size_t l, size_t h) : low(l), high(h) {}
  bool operator()(const std::string &s) const {
    return s.size() >= low && s.size() <= high;
  }

 private:
  size_t low;
  size_t high;
};

int main() {
  std::string filename;
  std::cin >> filename;
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cerr << "cannot open file: " << filename << endl;
    return -1;
  }
  std::istream_iterator<std::string> iter(ifs), eof;
  std::cout << std::count_if(iter, eof, StrRange(1, 5)) << std::endl;
  return 0;
}
