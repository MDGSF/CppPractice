#include <iostream>
#include <stdexcept>

using namespace std;

void case1() try {
  printf("case1\n");
  throw runtime_error("error occured");
} catch (const exception& e) {
  cout << e.what() << endl;
}

int main() {
  case1();
  return 0;
}
