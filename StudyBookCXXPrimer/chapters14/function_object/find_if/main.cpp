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

class SizeComp {
 public:
  SizeComp(size_t n) : sz(n) {}
  bool operator()(const std::string &s) const { return s.size() > sz; }

 private:
  size_t sz;
};

int main() {
  cout << "hello world!" << endl;
  std::vector<std::string> words{"a", "b", "c", "asdfgh", "huangjian"};
  size_t sz = 5;
  //  auto wc = find_if(words.begin(), words.end(),
  //                    [sz](const std::string &a) { return a.size() > sz; });

  auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
  cout << *wc << endl;
  return 0;
}
