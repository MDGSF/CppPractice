#include "StrBlob.h"
#include "ConstStrBlobPtr.h"
#include "StrBlobPtr.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

StrBlob::StrBlob(const StrBlob &sb)
    : data(std::make_shared<std::vector<std::string>>(*sb.data)) {}

StrBlob &StrBlob::operator=(const StrBlob &sb) {
  data = std::make_shared<std::vector<std::string>>(*sb.data);
  return *this;
}

std::string &StrBlob::operator[](size_type n) {
  check(n, "subscript nonexist element");
  return (*data)[n];
}

const std::string &StrBlob::operator[](size_type n) const {
  check(n, "subscript nonexist element");
  return (*data)[n];
}

std::string& StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

const std::string& StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

const std::string& StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() {
  auto ret = StrBlobPtr(*this, data->size());
  return ret;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
  // return lhs.data == rhs.data;  // compare address
  return *lhs.data == *rhs.data;  // compare value
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
  return *lhs.data < *rhs.data;  // compare value
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs) { return rhs < lhs; }

bool operator<=(const StrBlob &lhs, const StrBlob &rhs) { return !(lhs > rhs); }

bool operator>=(const StrBlob &lhs, const StrBlob &rhs) { return !(lhs < rhs); }
