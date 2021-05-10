#include "StrBlobPtr.h"
#include "StrBlob.h"

StrBlobPtr::StrBlobPtr() : wptr(), curr(0) {}

StrBlobPtr::StrBlobPtr(StrBlob& sb, size_t pos) : wptr(sb.data), curr(pos) {}

std::string &StrBlobPtr::operator*() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

std::string *StrBlobPtr::operator->() const {
  //return &this->operator*(); // 将工作委托给解引用运算符
  return &**this;
}

StrBlobPtr &StrBlobPtr::operator++() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
  auto ret = *this;
  ++*this;
  return ret;
}

StrBlobPtr &StrBlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator--(int) {
  auto ret = *this;
  --*this;
  return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(int n) {
  curr += n;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(int n) {
  return *this += -n;
}

StrBlobPtr StrBlobPtr::operator+(int n) const {
  StrBlobPtr ret = *this;
  return ret += n;
}

StrBlobPtr StrBlobPtr::operator-(int n) const {
  StrBlobPtr ret = *this;
  return ret -= n;
}

int StrBlobPtr::operator-(const StrBlobPtr &rhs) const {
  return curr - rhs.curr;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return rhs < lhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs < rhs);
}
