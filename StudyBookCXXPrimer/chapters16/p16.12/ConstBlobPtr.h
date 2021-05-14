#ifndef CONSTBLOBPTR_H
#define CONSTBLOBPTR_H

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class ConstBlobPtr;

template <typename T>
bool operator==(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

template <typename T>
bool operator<(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

template <typename T>
bool operator-(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

template <typename T>
class ConstBlobPtr {
  friend bool operator==<T>(const ConstBlobPtr &, const ConstBlobPtr &);
  friend bool operator< <T>(const ConstBlobPtr &, const ConstBlobPtr &);
  friend bool operator-<T>(const ConstBlobPtr &, const ConstBlobPtr &);

 public:
  using size_type = typename std::vector<T>::size_type;

  ConstBlobPtr() : wptr(), curr(0) {}

  explicit ConstBlobPtr(Blob<T> &b, size_type pos = 0) : wptr(b.data), curr(0) {
    check(pos, "ConstBlobPtr initial position out of range");
    curr = pos;
  }

  const T &operator*() const {
    return (*check(curr + 1, "dereference out of range"))[curr];
  }

  const T *operator->() const {
    return &**this;  // delegate by operator*
  }

  ConstBlobPtr &operator++() {
    check(curr + 1, "ConstBlobPtr increament pass the end");
    ++curr;
    return *this;
  }

  ConstBlobPtr operator++(int) {
    ConstBlobPtr ret = *this;
    ++*this;
    return ret;
  }

  ConstBlobPtr &operator--() {
    check(curr - 1, "ConstBlobPtr decreament pass the beginning");
    --curr;
    return *this;
  }

  ConstBlobPtr operator--(int) {
    ConstBlobPtr ret = *this;
    --*this;
    return ret;
  }

  ConstBlobPtr &operator+=(int n) {
    check(curr + n, "compound assignment out of range");
    curr += n;
    return *this;
  }

  ConstBlobPtr &operator-=(int n) { return *this + -n; }

  ConstBlobPtr operator+(int n) const {
    ConstBlobPtr ret = *this;
    return ret += n;
  }

  ConstBlobPtr operator-(int n) const {
    ConstBlobPtr ret = *this;
    return ret += -n;
  }

 private:
  std::shared_ptr<std::vector<T>> check(size_type pos,
                                        const std::string &msg) const {
    std::shared_ptr<std::vector<T>> ret = wptr.lock();
    if (!ret) {
      throw std::runtime_error("unbound ConstBlobPtr");
    } else if (pos > ret->size()) {
      throw std::out_of_range(msg);
    }
    return ret;
  }

  std::weak_ptr<std::vector<T>> wptr;
  size_type curr;
};

template <typename T>
int operator-(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
  return lhs.curr - rhs.curr;
}

template <typename T>
bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
  return rhs < lhs;
}

template <typename T>
bool operator<=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
  return !(lhs > rhs);
}

template <typename T>
bool operator>=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
  return !(lhs < rhs);
}

using ConstStrBlobPtr = ConstBlobPtr<std::string>;

#endif
