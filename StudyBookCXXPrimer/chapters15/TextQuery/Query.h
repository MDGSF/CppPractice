#ifndef QUERY_H
#define QUERY_H

class TextQuery;
class QueryResult;
class Query_base;

#include <memory>
#include <string>
#include <iostream>

class Query {
  friend Query operator~(const Query &);
  friend Query operator&(const Query &, const Query &);
  friend Query operator|(const Query &, const Query &);

 public:
  Query(const std::string &);

  QueryResult eval(const TextQuery &t) const;
  std::string rep() const;

 private:
  Query(std::shared_ptr<Query_base> query) : pq(query) {}

  std::shared_ptr<Query_base> pq;
};

inline std::ostream &operator<<(std::ostream &os, const Query &q) {
  return os << q.rep();
}

#endif
