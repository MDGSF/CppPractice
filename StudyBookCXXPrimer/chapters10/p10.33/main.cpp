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
  ifstream in("in");
  istream_iterator<int> in_iter(in);
  istream_iterator<int> eof;

  ofstream out_odd("out_odd");
  ostream_iterator<int> out_odd_iter(out_odd, " ");

  ofstream out_even("out_even");
  ostream_iterator<int> out_even_iter(out_even, "\n");

  while (in_iter != eof) {
    int num = *in_iter++;
    if (num % 2 != 0) {
      *out_odd_iter++ = num;
    } else {
      *out_even_iter++ = num;
    }
  }
  return 0;
}
