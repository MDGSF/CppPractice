#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> v2;
  for (int i = 0; i != 100; i += 1) {
    v2.push_back(i);
  }
  return 0;
}
