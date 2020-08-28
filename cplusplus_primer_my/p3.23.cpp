#include "public.h"

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (auto it = v.begin(); it != v.end(); ++it) {
    *it = (*it) * 2;
  }
  for (auto e : v) {
    std::cout << e << std::endl;
  }
  return 0;
}
