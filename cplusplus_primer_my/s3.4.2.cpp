#include "public.h"

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int expected = 90;
  auto beg = v.begin();
  auto end = v.end();
  auto mid = v.begin() + (end - beg) / 2;
  while (mid != end && *mid != expected) {
    if (expected < *mid) {
      end = mid;
    } else {
      beg = mid + 1;
    }
    mid = beg + (end - beg) / 2;
  }

  if (mid == end) {
    std::cout << "not found " << expected << std::endl;
  } else {
    std::cout << "found " << expected << std::endl;
  }
  return 0;
}
