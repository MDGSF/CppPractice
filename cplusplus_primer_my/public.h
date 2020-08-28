#ifndef CPLUSPLUS_PRIMER_HJ
#define CPLUSPLUS_PRIMER_HJ

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void showVec(const std::vector<T>& v) {
  for (auto e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

#endif
