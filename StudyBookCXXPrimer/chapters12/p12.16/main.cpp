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

int main() {
  cout << "hello world!" << endl;
  unique_ptr<int> p1(new int(42));
  unique_ptr<int> p2 = p1;
  return 0;
}
