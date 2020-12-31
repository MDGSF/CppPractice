#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
  string str1 = "hello world";
  string str2 = str1;
  str2 += "Mini";
  cout << str1 << endl;
  cout << str2 << endl;
  return 0;
}

