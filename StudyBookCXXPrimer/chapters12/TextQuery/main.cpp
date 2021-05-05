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

#include "text_query.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void runQueries(ifstream &infile) {
  TextQuery tq(infile);
  while (true) {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q") {
      break;
    }
    print(cout, tq.query(s)) << endl;
  }
}

int main() {
  cout << "hello world!" << endl;
  ifstream in("in");
  runQueries(in);
  return 0;
}
