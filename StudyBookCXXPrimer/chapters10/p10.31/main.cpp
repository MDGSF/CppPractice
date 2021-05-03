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
  istream_iterator<int> in_iter(cin);
  istream_iterator<int> eof;
  vector<int> vec;
  copy(in_iter, eof, back_inserter(vec));
  sort(vec.begin(), vec.end());
  ostream_iterator<int> out_iter(cout, " ");
  unique_copy(vec.cbegin(), vec.cend(), out_iter);
  cout << endl;
  return 0;
}
