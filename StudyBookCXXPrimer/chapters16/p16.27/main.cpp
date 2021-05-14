#include <string>
using std::string;

template <typename T>
class Stack {
  typedef typename T::NotExist StaticAssert;
};

void f1(Stack<char>);

class Exercise {
  Stack<double> &rsd;
  //Stack<int> si;
};

int main() {
  Stack<char> *sc;

  //f1(*sc);

  //int iObj = sizeof(Stack<string>);

  return 0;
}
