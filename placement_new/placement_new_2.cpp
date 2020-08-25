#include <iostream>

int main() {
  int x = 10;
  std::cout << "&x = " << &x << ", x = " << x << std::endl;

  int *ptr = new (&x) int(100);
  std::cout << "&x = " << &x << ", x = " << x << std::endl;
  std::cout << "ptr = " << ptr << ", *ptr = " << *ptr << std::endl;
  return 0;
}

