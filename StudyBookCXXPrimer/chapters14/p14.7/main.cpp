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

#include "String.h"

using std::cout;
using std::endl;

void print(const String &s) {
  std::cout << "==== String <" << &s << ">:<" << s << "> size: " << s.size()
            << " capacity: " << s.capacity() << std::endl;
}

void print(std::vector<String> &vs) {
  std::cout << "== vector <" << &vs << "> size: " << vs.size()
            << " capacity: " << vs.capacity() << std::endl;
  for (const auto &s : vs) {
    print(s);
  }
}

int main() {
  cout << "hello world!" << endl;
  String s1;
  print(s1);
  s1.pop_back();
  print(s1);

  s1.push_back('a');
  print(s1);
  s1.push_back('b');
  print(s1);
  s1.push_back('c');
  print(s1);
  s1.push_back('d');
  print(s1);

  {
    String s2 = "s2";
    print(s2);

    s2 = "s3";
    print(s2);

    char *cs = "def";
    s2 = cs;
    print(s2);

    s2 = s1;
    print(s2);
  }
  print(s1);

  s1.pop_back();
  print(s1);

  s1.reserve(s1.capacity() / 2);
  print(s1);

  s1.reserve(s1.capacity() * 2);
  print(s1);

  s1.resize(s1.size() + 6);
  print(s1);

  s1.resize(s1.size() + 6, 'x');
  print(s1);

  s1.resize(s1.size() - 6);
  print(s1);

  s1.resize(s1.size() - 6, 'x');
  print(s1);

  String s2 { 'm', 'n', 'p', 'q', 'r' };
  print(s2);

  String s3 { 'm', 'n', 'p', 'q', 'r' };
  print(s3);

  s3 = std::move(s2);
  print(s2);
  print(s3);

  std::vector<String> vs;
  vs.push_back("s1");
  print(vs);
  vs.push_back("s2");
  print(vs);
  vs.push_back("s3");
  print(vs);
  vs.push_back("s4");
  print(vs);
  vs.push_back("s5");
  print(vs);
  vs.push_back("s6");
  print(vs);
  vs.push_back("s7");
  print(vs);
  vs.push_back("s8");
  print(vs);
  vs.push_back("s9");
  print(vs);

  return 0;
}
