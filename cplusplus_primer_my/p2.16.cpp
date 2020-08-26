#include <iostream>

int main() {
  int i = 0;
  int &r1 = i;
  double d = 0;
  double &r2 = d;

  r2 = 3.14159;
  r2 = r1;
  i = r2;
  r1 = d;
  return 0;
}
