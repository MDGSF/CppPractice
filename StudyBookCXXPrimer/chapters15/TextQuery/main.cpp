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

#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"

using std::cout;
using std::endl;

void runQueries(std::ifstream &infile) {
  TextQuery tq(infile);

  Query q = Query("fiery") & Query("bird") | Query("wind");
  std::cout << "==================" << std::endl;
  std::cout << q << std::endl;
  std::cout << "==================" << std::endl;
  print(std::cout, q.eval(tq)) << std::endl;

  q = Query("fiery") & Query("bird") | ~Query("wind");
  std::cout << "==================" << std::endl;
  std::cout << q << std::endl;
  std::cout << "==================" << std::endl;
  print(std::cout, q.eval(tq)) << std::endl;

  while (true) {
    std::cout << "Enter word to look for, or 'q' to exit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q")
      break;
    print(std::cout, tq.query(s)) << std::endl;
  }
}

int main() {
  std::cout << "Enter the file name to look up: ";
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Cannot open file: " << filename << std::endl;
    return -1;
  }
  runQueries(in);

  return 0;
}
