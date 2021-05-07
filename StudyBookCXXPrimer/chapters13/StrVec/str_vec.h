#ifndef STR_VEC_H
#define STR_VEC_H

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

class StrVec {
 public:
  typedef size_t size_type;
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  ~StrVec();

  StrVec(const StrVec &s);
  StrVec &operator=(const StrVec &rhs);

  void push_back(const std::string &s);
  void pop_back();

  void resize(size_type n, const std::string &s = std::string());

  bool empty() const { return cbegin() == cend(); }
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }

  std::string *begin() { return elements; }
  std::string *end() { return first_free; }
  const std::string *begin() const { return elements; }
  const std::string *end() const { return first_free; }
  const std::string *cbegin() const { return begin(); }
  const std::string *cend() const { return end(); }

 private:
  void chk_n_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }

  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();
  void reallocate();

  static std::allocator<std::string> alloc;
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

#endif
