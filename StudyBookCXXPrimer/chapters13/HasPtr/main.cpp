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

using std::cout;
using std::endl;

// 类似于值拷贝
class HasPtr1 {
 public:
  HasPtr1(const std::string& s = std::string())
      : ps(new std::string(s)), i(0) {}
  ~HasPtr1() { delete ps; }

  // 拷贝构造函数，也是一个构造函数
  HasPtr1(const HasPtr1& other) : ps(new std::string(*other.ps)), i(other.i) {}

  // 拷贝赋值运算符，要先把旧的数据删除了
  HasPtr1& operator=(const HasPtr1& rhs) {
    if (this == &rhs) {
      return *this;
    }
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
  }

 private:
  std::string* ps;
  int i;
};

// 类似于指针拷贝
class HasPtr2 {
 public:
  HasPtr2(const std::string& s = std::string())
      : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

  ~HasPtr2() {
    if (--*use == 0) {
      delete ps;
      delete use;
    }
  }

  // 拷贝构造函数，也是一个构造函数
  HasPtr2(const HasPtr2& other) : ps(other.ps), i(other.i), use(other.use) {
    ++*use;
  }

  // 拷贝赋值运算符，要先把旧的数据删除了
  HasPtr2& operator=(const HasPtr2& rhs) {
    if (this == &rhs) {
      return *this;
    }
    ++*rhs.use;
    if (--*use == 0) {
      delete ps;
      delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
  }

 private:
  std::string* ps;
  int i;
  std::size_t* use;  //用来记录有多少个对象共享*ps的成员。
};

// 类似于指针拷贝
class HasPtr3 {
 public:
  HasPtr3(const std::string& s = std::string())
      : ps(std::make_shared<std::string>(s)), i(0) {}
  ~HasPtr3() = default;

  HasPtr3(const HasPtr3& other) = default;
  HasPtr3& operator=(const HasPtr3& rhs) = default;

 private:
  std::shared_ptr<std::string> ps;
  int i;
};

// 类似于值拷贝
class HasPtr4 {
  friend void swap(HasPtr4& lhs, HasPtr4& rhs);

 public:
  HasPtr4(const std::string& s = std::string())
      : ps(new std::string(s)), i(0) {}
  ~HasPtr4() { delete ps; }

  // 拷贝构造函数，也是一个构造函数
  HasPtr4(const HasPtr4& other) : ps(new std::string(*other.ps)), i(other.i) {}

  // 拷贝赋值运算符，使用 swap 来实现
  HasPtr4& operator=(HasPtr4 rhs) {
    swap(*this, rhs);
    return *this;
  }

 private:
  std::string* ps;
  int i;
};

inline void swap(HasPtr4& lhs, HasPtr4& rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

int main() {
  cout << "hello world!" << endl;
  return 0;
}
