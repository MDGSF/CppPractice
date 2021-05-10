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

int add(int a, int b) {
  return a + b;
}

struct multiple {
  int operator()(int a, int b) { return a * b; }
};

auto divide = [](int a, int b) { return a / b; };

int main() {
  std::map<std::string, std::function<int (int, int)>> ops = {
    {"+", add},
    {"-", std::minus<int>()},
    {"*", multiple()},
    {"/", divide},
    {"%", [](int a, int b) { return a % b; }},
  };

  int a;
  int b;
  std::string op;
  do {
    std::cout << "Enter expression: ";
    std::cin >> a >> op >> b;
    auto it = ops.find(op);
    if (it != ops.end()) {
      std::cout << it->second(a, b) << std::endl;
    } else {
      std::cout << "Unrecognized operator: " << op << std::endl;
    }
  } while (std::cin);
  return 0;
}
