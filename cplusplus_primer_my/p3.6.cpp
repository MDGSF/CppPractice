#include <cctype>
#include <iostream>
#include <string>

void test1() {
  std::string s;
  while (std::cin >> s) {
    for (auto &c : s) {
      if (isalpha(c)) {
        c = 'X';
      }
    }
    std::cout << s << std::endl;
  }
}

void test2() {
  std::string s;
  while (std::cin >> s) {
    for (decltype(s.size()) i = 0; i < s.size(); i += 1) {
      if (isalpha(s[i])) {
        s[i] = 'X';
      }
    }
    std::cout << s << std::endl;
  }
}

int main() {
  test2();
  return 0;
}
