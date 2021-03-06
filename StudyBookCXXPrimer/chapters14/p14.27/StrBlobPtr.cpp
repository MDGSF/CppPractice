#include "StrBlobPtr.h"
#include "StrBlob.h"

StrBlobPtr::StrBlobPtr() : wptr(), curr(0) {}

StrBlobPtr::StrBlobPtr(StrBlob& sb, size_t pos) : wptr(sb.data), curr(pos) {}

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
