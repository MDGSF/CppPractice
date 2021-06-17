// Copyright 2021 <HuangJian 1342042894@qq.com>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <chrono>
#include <exception>
#include <fstream>     // ifstream
#include <functional>  // function object, bind
#include <future>
#include <iostream>  // cin, cout, cerr
#include <iterator>
#include <list>
#include <map>
#include <memory>  // unique_ptr, shared_ptr, weak_ptr
#include <random>
#include <set>
#include <sstream>  // istringstream
#include <string>
#include <thread>
#include <utility>
#include <vector>

using namespace std;

int do_something(char c) {
  std::default_random_engine dre(c);
  std::uniform_int_distribution<int> id(10, 1000);
  for (int i = 0; i < 1000; ++i) {
    this_thread::sleep_for(chrono::milliseconds(id(dre)));
    cout.put(c).flush();
  }
  return c;
}

int func1() { return do_something('.'); }

int func2() { return do_something('+'); }

int main() {
  cout << "starting func1() in background"
       << " and func2() in foreground" << endl;

  std::future<int> result1(std::async(std::launch::async, func1));
  int result2 = func2();
  int result = result1.get() + result2;

  std::cout << "result = " << result << std::endl;
  return 0;
}
