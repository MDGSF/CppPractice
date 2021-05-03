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
#include <utility>
#include <vector>

using namespace std;

int main() {
  cout << "hello world!" << endl;
  vector<pair<string, int>> vec;
  string str;
  int num;
  while (cin >> str >> num) {
    // pair<string, int> p = {str, num};
    // vec.push_back(p);

    vec.push_back({str, num});
  }
  for (const auto & e : vec) {
    cout << e.first << " " << e.second << endl;
  }
  return 0;
}
