#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string s("Hello World!!!");
  decltype(s.size()) punct_cnt = 0;
  for (auto c : s) {
    if (ispunct(c)) {
      punct_cnt += 1;
    }
  }
  std::cout << punct_cnt << " punctuation characters in " << s << std::endl;
  return 0;
}
