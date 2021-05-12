#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include "StrVec.h"

class QueryResult;

class TextQuery {
 public:
  using line_no_type = StrVec::size_type;

  explicit TextQuery(std::ifstream &in);

  QueryResult query(const std::string &word) const;

 private:
  std::shared_ptr<StrVec> text;
  std::map<std::string, std::shared_ptr<std::set<line_no_type>>> word_map;
};

#endif
