#include "str_vec.h"

using std::cout;
using std::endl;

std::allocator<std::string> StrVec::alloc;

StrVec::~StrVec() { free(); }

StrVec::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = newdata.second;
  cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = data.second;
  cap = data.second;
  return *this;
}

StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
  s.elements = nullptr;
  s.first_free = nullptr;
  s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = nullptr;
    rhs.first_free = nullptr;
    rhs.cap = nullptr;
  }
  return *this;
}

void StrVec::push_back(const std::string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

void StrVec::pop_back() {
  if (size() > 0) {
    alloc.destroy(--first_free);
  }
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(
    const std::string *b, const std::string *e) {
  auto data = alloc.allocate(e - b);
  return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  if (elements) {
    for (auto p = first_free; p != elements;) {
      alloc.destroy(--p);
    }
    alloc.deallocate(elements, cap - elements);
  }
}

void StrVec::reallocate() {
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

void StrVec::resize(size_type n, const std::string &s) {
  if (n > size()) {
    for (int i = n - size(); i != 0; --i) {
      push_back(s);
    }
  } else if (n < size()) {
    for (int i = size() - n; i != 0; --i) {
      pop_back();
    }
  }
}
