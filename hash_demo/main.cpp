#include <iostream>
#include <functional>
#include <string>
#include <stdio.h>

int main() {
  std::string str = "My hash demo";
  std::size_t h = std::hash<std::string>{}(str);
  printf("%x\n", h);
  return 0;
}
