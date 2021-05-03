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
  auto iter = vec.end();
  while (iter != vec.begin()) {
    cout << *(--iter) << " ";
  }
  cout << endl;
  return 0;
}
