#include <cassert>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  string str = "god of war";
  auto reg = regex(R"((\w+)\s(\w+))");
  auto what = smatch();

  auto found = regex_search(str, what, reg);

  assert(found);
  assert(!what.empty());
  assert(what[1] == "god");
  assert(what[2] == "of");

  for (const auto& x : what) {
    cout << x << ',';
  }
  cout << endl;

  return 0;
}
