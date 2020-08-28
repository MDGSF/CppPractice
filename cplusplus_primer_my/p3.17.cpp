#include "public.h"

int main() {
  std::vector<std::string> result;

  std::string s;
  while (std::cin >> s) {
    result.push_back(s);
  }

  for (auto &word : result) {
    for (auto &c : word) {
      c = std::toupper(c);
    }
  }

  for (auto word : result) {
    std::cout << word << std::endl;
  }

  return 0;
}
