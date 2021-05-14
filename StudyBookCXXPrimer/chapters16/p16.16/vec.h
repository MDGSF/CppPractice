#ifndef VEC_H
#define VEC_H

#include <memory>
#include <initializer_list>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <string>

template <typename T>
class Vec;

template <typename T>
bool operator==(const Vec<T> &, const Vec<T> &);

template <typename T>
bool operator<(const Vec<T> &, const Vec<T> &);

template <typename T>
class Vec {
  friend bool operator==<T>(const Vec<T> &, const Vec<T> &);
  friend bool operator< <T>(const Vec<T> &, const Vec<T> &);

 public:
  using size_type = size_t;

  Vec() = default;

  Vec(std::initializer_list<T> il) : Vec() {
    for (auto &t : il) {
      push_back(std::move(t));
    }
  }

  ~Vec() {
    free();
  }

  Vec(const Vec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    first_elem = data.first;
    first_free = data.second;
    cap = data.second;
  }

  Vec &operator=(const Vec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    first_elem = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
  }

  Vec(Vec &&rhs) noexcept
    : first_elem(rhs.first_elem), first_free(rhs.first_free), cap(rhs.cap) {
      rhs.first_elem = nullptr;
      rhs.first_free = nullptr;
      rhs.cap = nullptr;
    }

  Vec &operator=(Vec &&rhs) noexcept {
    if (this != &rhs) {
      free();
      first_elem = rhs.first_elem;
      first_free = rhs.first_free;
      cap = rhs.cap;
      rhs.first_elem = nullptr;
      rhs.first_free = nullptr;
      rhs.cap = nullptr;
    }
    return *this;
  }

  Vec &operator=(std::initializer_list<T> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    first_elem = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
  }

  const T &at(size_type n) const {
    if (n >= size()) {
      throw std::out_of_range("subscript out of range");
    }
    return first_elem[n];
  }

  T &at(size_type n) {
    return const_cast<T &>(const_cast<const Vec &>(*this).at(n));
  }

  const T &operator[](size_type n) const { return first_elem[n]; }

  T &operator[](size_type n) {
    return const_cast<T &>(const_cast<const Vec &>(*this)[n]);
  }

  void push_back(const T &t) {
    chk_n_alloc();
    alloc.construct(first_free++, t);
  }

  void push_back(T &&t) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(t));
  }

  void pop_back() {
    if (size() > 0) {
      alloc.destroy(--first_free);
    }
  }

  void reserve(size_type n) {
    if (n > capacity()) {
      reallocate(n);
    }
  }

  void resize(size_type n, const T &t = T()) {
    if (n > size()) {
      for (int i = n - size(); i != 0; --i) {
        push_back(t);
      }
    } else if(n < size()) {
      for (int i = size() - n; i != 0; --i) {
        pop_back();
      }
    }
  }

  bool empty() const { return cbegin() == end(); }

  size_type size() const { return first_free - first_elem; }

  size_type capacity() const { return cap - first_elem; }

  const T *begin() const { return first_elem; }

  T *begin() { return first_elem; }

  const T *end() const { return first_free; }

  T *end() { return first_free; }

  const T *cbegin() const { return begin(); }

  const T *cend() const { return end(); }

 private:
  void chk_n_alloc() {
    if (size() == capacity()) {
      reallocate(size() ? 2 * size() : 1);
    }
  }

  std::pair<T *, T *> alloc_n_copy(const T *b, const T *e) {
    auto b2 = alloc.allocate(e - b);
    return {b2, std::uninitialized_copy(b, e, b2)};
  }

  void reallocate(size_type new_cap_sz) {
    auto new_first_elem = alloc.allocate(new_cap_sz);
    auto new_first_free = new_first_elem;
    auto old_first_elem = first_elem;
    for (size_type i = 0; i != size(); ++i) {
      alloc.construct(new_first_free++, std::move(*old_first_elem++));
    }
    free();
    first_elem = new_first_elem;
    first_free = new_first_free;
    cap = first_elem + new_cap_sz;
  }

  void free() {
    if (first_elem) {
      for (auto p = first_free; p != first_elem; alloc.destroy(--p)) {}
      alloc.deallocate(first_elem, cap - first_elem);
      first_elem = nullptr;
      first_free = nullptr;
      cap = nullptr;
    }
  }

  static std::allocator<T> alloc;
  T *first_elem = nullptr;
  T *first_free = nullptr;
  T *cap = nullptr;
};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
  return lhs.size() == rhs.size() &&
    std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
  auto lit = lhs.begin();
  auto rit = rhs.begin();
  for (; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit) {
    if (*lit < *rit) {
      return true;
    } else if (*rit < *lit) {
      return false;
    }
  }
  return lit == lhs.end() && rit != rhs.end();
}

template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
  return rhs < lhs;
}

template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
  return !(lhs > rhs);
}

template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
  return !(lhs < rhs);
}

using StrVec = Vec<std::string>;

#endif
