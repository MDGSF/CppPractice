#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> vec = {1, 2, 3, 4, 5};
  ostream_iterator<int> out_iter(cout, " ");
  copy(vec.cbegin(), vec.cend(), out_iter);
  cout << endl;
  return 0;
}
