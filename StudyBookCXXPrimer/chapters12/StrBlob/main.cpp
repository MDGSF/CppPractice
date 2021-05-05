#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream>  // ifstream
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>  // unique_ptr, shared_ptr, weak_ptr
#include <set>
#include <sstream>  // istringstream
#include <string>
#include <utility>
#include <vector>

#include "StrBlob.h"

using namespace std;

void test1() {
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
  }
  cout << b1.size() << endl;
}

void test2() {
  ifstream in("foo");
  StrBlob vec;
  string word;
  while(getline(in, word)) {
    vec.push_back(word);
  }

  StrBlobPtr p = vec.begin();
  StrBlobPtr end = vec.end();
  while (p != end) {
    cout << p.deref() << endl;
    p.incr();
  }
}

int main() {
  test2();
  return 0;
}
