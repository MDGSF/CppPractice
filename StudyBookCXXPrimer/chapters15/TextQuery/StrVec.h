#ifndef STRVEC_H
#define STRVEC_H

#include <initializer_list>
#include <memory>
#include <string>

class StrVec {
 public:
  typedef size_t size_type;
  StrVec() {}
  StrVec(std::initializer_list<std::string>);
  ~StrVec();

  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);

  void push_back(const std::string &s);
  void pop_back();

  void reserve(size_type);
  void resize(size_type, const std::string & = std::string());

  bool empty() const { return cbegin() == cend(); }
  size_type size() const { return first_free - first_elem; }
  size_type capacity() const { return cap - first_elem; }

  std::string *begin() { return first_elem; }
  std::string *end() { return first_free; }
  const std::string *begin() const { return first_elem; }
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
  void reallocate();
  void free();

  static std::allocator<std::string> alloc;

  std::string *first_elem = nullptr;
  std::string *first_free = nullptr;
  std::string *cap = nullptr;
};

#endif
