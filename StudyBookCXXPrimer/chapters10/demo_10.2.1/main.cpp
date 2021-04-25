#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> vec(10);
  for (int i = 0; i < vec.size(); i++) {
    vec[i] = i;
  }
  int sum = accumulate(vec.cbegin(), vec.cend(), 0);
  cout << sum << endl;
  return 0;
}
