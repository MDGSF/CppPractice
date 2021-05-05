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
  int ix = 1024, *pi = &ix, *pi2 = new int(2048);
  typedef unique_ptr<int> IntP;

  // IntP p0(ix);
  // IntP p1(pi);
  IntP p2(pi2);
  // IntP p3(&ix);
  IntP p4(new int(2048));
  // IntP p5(p2.get());

  return 0;
}
