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

template <typename InIter, typename Val>
InIter find_element(InIter bg, InIter ed, const Val &v) {
  for (; bg != ed; ++bg) {
    if (*bg == v) {
      return bg;
    }
  }
  return bg;
}

int main() {
  std::vector<int> vi { 1, 2, 3, 4, 5 };
  auto it1 = find_element(vi.begin(), vi.end(), 3);
  if (it1 != vi.end()) {
    cout << *it1 << endl;
  } else {
    cout << "not found" << endl;
  }

  auto it2 = find_element(vi.begin(), vi.end(), 8);
  if (it2 != vi.end()) {
    cout << *it2 << endl;
  } else {
    cout << "not found" << endl;
  }

  std::list<std::string> ls { "abc", "def", "gh" };
  auto it3 = find_element(ls.begin(), ls.end(), "gh");
  if (it3 != ls.end()) {
    cout << *it3 << endl;
  } else {
    cout << "not found" << endl;
  }

  auto it4 = find_element(ls.begin(), ls.end(), "hello");
  if (it4 != ls.end()) {
    cout << *it4 << endl;
  } else {
    cout << "not found" << endl;
  }

  return 0;
}
