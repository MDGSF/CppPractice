#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string name;
  std::cout << "What is your name? ";
  std::getline(std::cin, name);
  std::cout << "Hello " << name << ", nice to meet you.\n";

  // read file line by line
  std::istringstream input;
  input.str("1\n2\n3\n4\n5\n6\n7\n");
  int sum = 0;
  for (std::string line; std::getline(input, line);) {
    sum += std::stoi(line);
  }
  std::cout << "\nThe sum is: " << sum << std::endl;
  return 0;
}
