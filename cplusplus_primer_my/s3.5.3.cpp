#include <iostream>

int main() {
  int a[10] = {0};
  int* piBegin = std::begin(a);
  int* piEnd = std::end(a);

  int iCount = 0;
  for (int* piCur = piBegin; piCur != piEnd; ++piCur) {
    *piCur = iCount++;
  }

  for (int* piCur = piBegin; piCur != piEnd; ++piCur) {
    std::cout << *piCur << std::endl;
  }
  return 0;
}
