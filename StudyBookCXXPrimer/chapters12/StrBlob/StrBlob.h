#pragma once
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

class StrBlobPtr;
class StrBlob {
  friend class StrBlobPtr;

 public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

  StrBlob(std::initializer_list<std::string> il)
      : data(std::make_shared<std::vector<std::string>>(il)) {}

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  void push_back(const std::string& t) { data->push_back(t); }

  void pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
  }

  std::string& front() {
    check(0, "front on empty StrBlob");
    return data->front();
  }

  std::string& back() {
    check(0, "back on empty StrBlob");
    return data->back();
  }

  StrBlobPtr begin();
  StrBlobPtr end();

 private:
  void check(size_type i, const std::string& msg) const {
    if (i >= data->size()) {
      throw std::out_of_range(msg);
    }
  }

  std::shared_ptr<std::vector<std::string>> data;
};

class StrBlobPtr {
 public:
  StrBlobPtr() : curr(0) {}

  StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}

  std::string& deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }

  StrBlobPtr& incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  }

  bool operator==(StrBlobPtr& rhs) {
    return curr == rhs.curr;
  }

  bool operator!=(StrBlobPtr& rhs) {
    return curr != rhs.curr;
  }

 private:
  std::shared_ptr<std::vector<std::string>> check(
      std::size_t i, const std::string& msg) const {
    auto ret = wptr.lock();
    if (!ret) {
      throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
      throw std::out_of_range(msg);
    }
    return ret;
  }

  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};
