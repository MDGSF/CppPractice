// Copyright 2021 <HuangJian 1342042894@qq.com>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream>  // ifstream
#include <functional>
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

class ShorterString {
 public:
  bool operator()(const std::string &a, const std::string &b) const {
    return a.size() < b.size();
  }
};

int main() {
  cout << "hello world!" << endl;
  std::vector<std::string> words{"abc", "cd", "b"};

  // stable_sort(words.begin(), words.end(),
  //            [](const std::string &a, const std::string &b) {
  //              return a.size() < b.size();
  //            });

  // stable_sort(words.begin(), words.end(), ShorterString());

  stable_sort(words.begin(), words.end(), std::greater<std::string>());
  //stable_sort(words.begin(), words.end(), std::less<std::string>());

  for (const auto &e : words) {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}
