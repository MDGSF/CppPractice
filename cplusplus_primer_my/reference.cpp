#include <iostream>

int main() {
  int i = 10;
  int &ri = i;
  ri = 100;
  std::cout << i << " " << ri << std::endl;

  int *pi = &i;
  int *&rpi = pi;
  *rpi = 200;
  std::cout << i << " " << ri << std::endl;

  int &rri = ri;
  rri = 300;
  std::cout << i << " " << ri << std::endl;
  return 0;
}
