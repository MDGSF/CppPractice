#include <iostream>
#include <vector>

template <typename T, typename U>
class MagicType {
 public:
  T dark;
  U magic;
};

// error: a typedef cannot be a template
// template<typename T>
// typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;

typedef int (*process)(void*);
using NewProcess = int(*)(void*);

template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main() {
  TrueDarkMagic<bool> you;
  return 0;
}
