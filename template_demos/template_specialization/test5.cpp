#include <cstring>
#include <iostream>

using namespace std;

template <class T>
T my_max(T a, T b) {
  return a > b ? a : b;
}

template <>
char* my_max(char* a, char* b) {
  return strcmp(a, b) > 0 ? a : b;
}

template <>
const char* my_max(const char* a, const char* b) {
  return strcmp(a, b) > 0 ? a : b;
}

int main() {
  cout << "max(10, 15) = " << my_max(10, 15) << endl;
  cout << "max('k', 's') = " << my_max('k', 's') << endl;
  cout << "max(10.1, 15.2) = " << my_max(10.1, 15.2) << endl;
  cout << "max(\"Aladdin\", \"Jasmine\") = " << my_max("Aladdin", "Jasmine")
       << endl;
  return 0;
}
