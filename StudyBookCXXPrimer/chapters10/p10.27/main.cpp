#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {
  vector<int> v = {1, 1, 2, 3, 3, 3, 4};
  list<int> lst(7);
  unique_copy(v.cbegin(), v.cend(), lst.begin());
  for (auto item : lst) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
