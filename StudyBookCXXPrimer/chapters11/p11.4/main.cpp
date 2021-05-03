#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// trim from start (in place)
static inline void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return std::isalpha(ch);
          }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](unsigned char ch) { return std::isalpha(ch); })
              .base(),
          s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
  ltrim(s);
  rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
  ltrim(s);
  return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
  rtrim(s);
  return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
  trim(s);
  return s;
}

int main() {
  map<string, size_t> word_count;
  set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                         "the", "but", "and", "or", "an", "a"};

  string word;
  while (cin >> word) {
    std::transform(word.begin(), word.end(), word.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    trim(word);
    if (exclude.find(word) == exclude.end()) {
      ++word_count[word];
    }
  }
  for (const auto &w : word_count) {
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
  }
  return 0;
}
