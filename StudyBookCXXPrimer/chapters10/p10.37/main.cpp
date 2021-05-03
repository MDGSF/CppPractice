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
  cout << "hello world!" << endl;
  vector<int> vec = {0,1,2,3,4,5,6,7,8,9,10};
  list<int> lst;
  copy(vec.begin()+3, vec.begin()+8, front_inserter(lst));
  ostream_iterator<int> out_iter(cout, " ");
  copy(lst.begin(), lst.end(), out_iter);
  cout << endl;
  return 0;
}
