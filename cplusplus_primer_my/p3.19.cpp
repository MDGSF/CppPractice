#include "public.h"

int main() {
  std::vector<int> v1(10, 42);
  std::vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  std::vector<int> v3 = v2;

  std::vector<int> v4;
  for (int i = 0; i < 10; i += 1) {
    v4.push_back(42);
  }

  std::vector<int> v5 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

  showVec(v1);
  showVec(v2);
  showVec(v3);
  showVec(v4);
  showVec(v5);
  return 0;
}
