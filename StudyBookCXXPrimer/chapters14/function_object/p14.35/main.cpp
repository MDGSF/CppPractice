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

class PrintStr {
 public:
   std::string operator()(std::istream &is) {
     std::string s;
     if (std::getline(is, s)) {
       return s;
     } else {
       return s;
     }
   }
};

int main() {
  cout << "hello world!" << endl;
  PrintStr ps;
  std::vector<std::string> vs;
  std::string s = ps(std::cin);
  while (!s.empty()) {
    vs.push_back(s);
    s = ps(std::cin);
  }
  for (const auto &l : vs) {
    std::cout << "<" << l << ">" << endl;
  }
  return 0;
}
