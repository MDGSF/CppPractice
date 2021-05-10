#ifndef STRBLOB_H
#define STRBLOB_H

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
class ConstStrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
  friend bool operator==(const StrBlob &, const StrBlob &);
  friend bool operator!=(const StrBlob &, const StrBlob &);
  friend bool operator<(const StrBlob &, const StrBlob &);
  friend bool operator>(const StrBlob &, const StrBlob &);
  friend bool operator<=(const StrBlob &, const StrBlob &);
  friend bool operator>=(const StrBlob &, const StrBlob &);

 public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  StrBlob(const StrBlob &);
  StrBlob &operator=(const StrBlob &);

  std::string &operator[](size_type n);
  const std::string &operator[](size_type n) const;

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  void push_back(const std::string& t) { data->push_back(t); }

  void push_back(std::string&& t) {
    data->push_back(std::move(t));
  }

  void pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
  }

  std::string& front();
  const std::string& front() const;
  std::string& back();
  const std::string& back() const;

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

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);

#endif
