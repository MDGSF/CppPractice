#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

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

class ConstStrBlobPtr {
  friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

 public:
  typedef std::vector<std::string>::size_type size_type;

  ConstStrBlobPtr();
  explicit ConstStrBlobPtr(const StrBlob &sb, size_type pos = 0);

  const std::string &operator[](size_type n) const {
    return (*wptr.lock())[n];
  }

  const std::string &operator*() const;
  const std::string *operator->() const;

  ConstStrBlobPtr &operator++();
  ConstStrBlobPtr operator++(int);
  ConstStrBlobPtr &operator--();
  ConstStrBlobPtr operator--(int);

  ConstStrBlobPtr &operator+=(int);
  ConstStrBlobPtr &operator-=(int);
  ConstStrBlobPtr operator+(int) const;
  ConstStrBlobPtr operator-(int) const;
  int operator-(const ConstStrBlobPtr &) const;

  //const std::string &deref() const;

 private:
  std::shared_ptr<std::vector<std::string>>
    check(size_type pos, const std::string &msg) const;

  std::weak_ptr<std::vector<std::string>> wptr;
  size_type curr;
};

bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

#endif
