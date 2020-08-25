#include <iostream>

int main() {
  int curValue = 0;
  int value = 0;
  if (std::cin >> curValue) {
    int cnt = 1;
    while (std::cin >> value) {
      if (curValue == value) {
        cnt += 1;
      } else {
        std::cout << curValue << " occurs " << cnt << " times " << std::endl;
        curValue = value;
        cnt = 1;
      }
    }
    std::cout << curValue << " occurs " << cnt << " times " << std::endl;
  }
  return 0;
}
