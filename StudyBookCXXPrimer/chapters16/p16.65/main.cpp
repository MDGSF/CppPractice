#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

template <typename T>
std::string debug_rep(T* t);

template <>
std::string debug_rep(const char* str);

template <>
std::string debug_rep(char *str);

int main() {
  char p[] = "alan";
  std::cout << debug_rep(p) << "\n";
  return 0;
}

template <typename T>
std::string debug_rep(T* t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <>
std::string debug_rep(const char* str) {
  std::string ret(str);
  return ret;
}

template <>
std::string debug_rep(char *str) {
  std::string ret(str);
  return ret;
}

