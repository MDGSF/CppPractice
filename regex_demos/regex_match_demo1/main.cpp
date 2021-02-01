#include <cassert>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  string str = "neir:autometa";
  auto reg = regex(R"(^(\w+)\:(\w+)$)");
  auto what = smatch();

  // 查看是否匹配
  assert(regex_match(str, what, reg));

  for (const auto& x : what) {
    cout << x << ',';
  }
  cout << endl;

  return 0;
}
