#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {
  list<int> lst = {1, 2, 3, 4};
  list<int> lst2, lst3;

  copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
  cout << "lst2: ";
  for (auto it : lst2){
    cout << it << " ";
  }
  cout << endl;

  copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
  cout << "lst3: ";
  for (auto it : lst3){
    cout << it << " ";
  }
  cout << endl;

  list<int> lst4;
  copy(lst.cbegin(), lst.cend(), back_inserter(lst4));
  cout << "lst4: ";
  for (auto it : lst4){
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
