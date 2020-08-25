#include <iostream>

void useWhile() {
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0;
  int v2 = 0;
  std::cin >> v1 >> v2;
  int cur = v1;
  while (cur <= v2) {
    std::cout << cur << std::endl;
    cur += 1;
  }
}

void useFor() {
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0;
  int v2 = 0;
  std::cin >> v1 >> v2;
  for (int i = v1; i <= v2; i++) {
    std::cout << i << std::endl;
  }
}

void useFor2() {
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0;
  int v2 = 0;
  std::cin >> v1 >> v2;
  int start = v1;
  int end = v2;
  if (v1 > v2) {
    start = v2;
    end = v1;
  }
  for (int i = start; i <= end; i++) {
    std::cout << i << std::endl;
  }
}

int main() {
  useFor2();
  return 0;
}
