#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream> // ifstream
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>  // unique_ptr, shared_ptr, weak_ptr
#include <set>
#include <sstream> // istringstream
#include <string>
#include <utility>
#include <vector>

using namespace std;

shared_ptr<vector<int>> read_data() {
  shared_ptr<vector<int>> vec = make_shared<vector<int>>();
  istream_iterator<int> in_iter(cin);
  istream_iterator<int> eof;
  copy(in_iter, eof, back_inserter(*vec));
  return vec;
}

void process_data(shared_ptr<vector<int>> data) {
  for (auto e : *data) {
    cout << e << endl;
  }
}

int main() {
  cout << "hello world!" << endl;
  shared_ptr<vector<int>> data = read_data();
  process_data(data);
  return 0;
}
