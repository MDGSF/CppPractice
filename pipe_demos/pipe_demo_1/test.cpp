#include <iostream>
#include <string>
#include <fstream>

int main() {
  std::ofstream file;
  file.open("test.log");

  setbuf(stdout, NULL);
  for (std::string line; std::getline(std::cin, line); ) {
    std::cout << "[subtest]: " << line << std::endl;
    file << "[subtest]: " << line << std::endl << std::flush;
    fflush(stdout);
  }

  file.close();
  return 0;
}
