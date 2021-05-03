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
  ifstream in("foo");
  istream_iterator<string> str_iter(in);
  istream_iterator<string> eof;
  vector<string> vec(str_iter, eof);
  ostream_iterator<string> out_iter(cout, " ");
  copy(vec.cbegin(), vec.cend(), out_iter);
  cout << endl;
  return 0;
}
