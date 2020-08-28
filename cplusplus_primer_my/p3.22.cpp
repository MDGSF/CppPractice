#include "public.h"

int main() {
  std::vector<std::string> text = {"Hello", "world", "", "Hi"};
  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
    for (auto &c : *it) {
      c = std::toupper(c);
    }
  }
  for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
    std::cout << *it << std::endl;
  }
  return 0;
}
