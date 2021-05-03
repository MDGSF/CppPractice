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
  {
    vector<int> vec = {10, 8, 9, 1, 3, 2, 5};
    sort(vec.begin(), vec.end()); //从小到大排序
    ostream_iterator<int> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;
  }
  {
    vector<int> vec = {10, 8, 9, 1, 3, 2, 5};
    sort(vec.rbegin(), vec.rend()); //从大到小排序
    ostream_iterator<int> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;
  }
  return 0;
}
