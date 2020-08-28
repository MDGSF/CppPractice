#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string s("some string");
  for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]);
       ++index) {
    s[index] = toupper(s[index]);
  }
  std::cout << s << std::endl;
  return 0;
}
