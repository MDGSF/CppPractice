#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

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

class StrBlob;

class StrBlobPtr {
  friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

 public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlobPtr();
  explicit StrBlobPtr(StrBlob &a, size_t sz = 0);

  std::string &operator[](size_type n) { return (*wptr.lock())[n]; }
  const std::string &operator[](size_type n) const { return (*wptr.lock())[n]; }

  std::string &operator*() const;
  std::string *operator->() const;

  StrBlobPtr &operator++();  // 前置++
  StrBlobPtr operator++(int);  // 后置++
  StrBlobPtr &operator--();  // 前置--
  StrBlobPtr operator--(int);  // 后置--

  StrBlobPtr &operator+=(int);
  StrBlobPtr &operator-=(int);
  StrBlobPtr operator+(int) const;
  StrBlobPtr operator-(int) const;
  int operator-(const StrBlobPtr &) const;

  std::string &deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }

  StrBlobPtr &incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  }

 private:
  std::shared_ptr<std::vector<std::string>> check(
      std::size_t i, const std::string &msg) const {
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

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

#endif
