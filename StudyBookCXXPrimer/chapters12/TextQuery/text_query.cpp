#include "text_query.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

TextQuery::TextQuery(std::ifstream &is) : file(new vector<string>) {
  string text;
  while (getline(is, text)) {
    file->push_back(text);
    int n = file->size() - 1;
    istringstream line(text);
    string word;
    while (line >> word) {
      auto &lines = wm[word];
      if (!lines) {
        lines.reset(new set<line_no>);
      }
      lines->insert(n);
    }
  }
}

QueryResult TextQuery::query(const std::string &sought) const {
  static shared_ptr<set<line_no>> nodata(new set<line_no>);
  auto loc = wm.find(sought);
  if (loc == wm.end()) {
    return QueryResult(sought, nodata, file);
  } else {
    return QueryResult(sought, loc->second, file);
  }
}

string make_plural(size_t ctr, const string &word, const string &ending) {
  return (ctr > 1) ? word + ending : word;
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " "
     << make_plural(qr.lines->size(), "time", "s") << endl;
  for (auto num : *qr.lines) {
    os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
  }
  return os;
}
