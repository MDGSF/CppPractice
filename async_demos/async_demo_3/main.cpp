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

int query_number() {
  std::cout << "read number: ";
  int num;
  std::cin >> num;

  if (!std::cin) {
    throw std::runtime_error("no number read");
  }

  return num;
}

void do_something(char c, std::shared_future<int> f) {
  try {
    int num = f.get();

    for (int i = 0; i < num; ++i) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      std::cout.put(c).flush();
    }

  } catch (const std::exception& e) {
    std::cout << std::this_thread::get_id() << ": " << e.what() << std::endl;
  }
}

int main() {
  try {
    std::shared_future<int> f = std::async(query_number);

    auto f1 = std::async(std::launch::async, do_something, '.', f);
    auto f2 = std::async(std::launch::async, do_something, '+', f);
    auto f3 = std::async(std::launch::async, do_something, '*', f);

    f1.get();
    f2.get();
    f3.get();
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\ndone" << std::endl;

  return 0;
}
