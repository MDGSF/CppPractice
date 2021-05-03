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
  list<int> lst = {1, 2, 0, 3, 4, 0, 5};
  auto rzero = find(lst.crbegin(), lst.crend(), 0);
  cout << *rzero << endl;

  rzero++;
  cout << *rzero << endl;
  return 0;
}
