#include <initializer_list>
#include <iostream>
#include <vector>

class MagicFoo {
 public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list) {
    for (std::initializer_list<int>::iterator it = list.begin();
         it != list.end(); ++it) {
      vec.push_back(*it);
    }
  }

  void foo(std::initializer_list<int> list) {
    for (std::initializer_list<int>::iterator it = list.begin();
         it != list.end(); ++it) {
      vec.push_back(*it);
    }
  }
};

int main() {
  // after C++11
  MagicFoo magicFoo = {1, 2, 3, 4, 5};
  magicFoo.foo({6, 7, 8, 9, 10});
  std::cout << "magicFoo: ";
  for (auto e : magicFoo.vec) {
    std::cout << e << std::endl;
  }
  return 0;
}
