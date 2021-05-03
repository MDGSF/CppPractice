#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  cout << "逆序输出" << endl;
  vector<int> vec = {1, 2, 3, 4, 5, 6};
  ostream_iterator<int> out_iter(cout, " ");
  copy(vec.crbegin(), vec.crend(), out_iter);
  cout << endl;
  return 0;
}
