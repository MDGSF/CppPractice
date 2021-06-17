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

int do_something(char c) {
  std::default_random_engine dre(c);
  std::uniform_int_distribution<int> id(10, 1000);
  for (int i = 0; i < 10; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
    std::cout.put(c).flush();
  }
  return c;
}

int func1() { return do_something('.'); }

int func2() { return do_something('+'); }

int main() {
  std::cout << "starting 2 operations asynchronously" << std::endl;

  auto f1 = std::async(std::launch::async, [] { do_something('.'); });
  auto f2 = std::async(std::launch::async, [] { do_something('+'); });

  if (f1.wait_for(std::chrono::seconds(0)) != std::future_status::deferred ||
      f2.wait_for(std::chrono::seconds(0)) != std::future_status::deferred) {
    while (f1.wait_for(std::chrono::seconds(0)) != std::future_status::ready &&
           f2.wait_for(std::chrono::seconds(0)) != std::future_status::ready) {
      std::this_thread::yield();
    }
  }
  std::cout.put('\n').flush();

  try {
    f1.get();
    f2.get();
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\ndone" << std::endl;

  return 0;
}
