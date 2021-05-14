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
#include <cstring>

using std::cout;
using std::endl;

template <typename T>
int compare(const T &v1, const T &v2) {
  if (v1 < v2) {
    return -1;
  }
  if (v2 < v1) {
    return 1;
  }
  return 0;
}

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
  return std::strcmp(p1, p2);
}

int main() {
  cout << compare(1, 0) << endl;

  std::vector<int> vec1{1, 2, 3};
  std::vector<int> vec2{4, 5, 6};
  cout << compare(vec1, vec2) << endl;

  cout << compare("hello", "world!") << endl;
  return 0;
}
