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

void do_something(std::promise<std::string>& p) {
  try {
    std::cout << "read char ('x' for exception): ";
    char c = std::cin.get();
    if (c == 'x') {
      throw std::runtime_error(std::string("char ") + c + " read");
    }
    std::string s = std::string("char ") + c + " processed";
    p.set_value(std::move(s));
  } catch (...) {
    p.set_exception(std::current_exception());
  }
}

int main() {
  try {
    std::promise<std::string> p;
    std::thread t(do_something, std::ref(p));
    t.detach();

    std::future<std::string> f(p.get_future());

    std::cout << "result: " << f.get() << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "exception";
  }
  return 0;
}
