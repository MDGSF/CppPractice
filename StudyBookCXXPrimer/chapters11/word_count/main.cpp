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
  map<string, size_t> word_count;
  string word;
  while (cin >> word) {
    ++word_count[word];
  }
  for (const auto &w : word_count) {
    cout << w.first << " occurs " <<
      w.second << ((w.second > 1) ? " times" : " time") << endl;
  }
  return 0;
}
