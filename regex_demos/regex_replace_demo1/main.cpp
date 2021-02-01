#include <cassert>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  string str = "god of war";
  auto reg = regex(R"(\w+$)");
  auto what = smatch();

  auto newstr = regex_replace(str, reg, "peace");

  cout << newstr << endl;

  return 0;
}
