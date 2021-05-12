#ifndef NOTQUERY_H
#define NOTQUERY_H

#include <memory>
#include <string>
#include "Query.h"
#include "Query_base.h"

class TextQuery;
class QueryResult;

class NotQuery : public Query_base {
  friend Query operator~(const Query &);

  NotQuery(const Query &query) : q(query) {}

  QueryResult eval(const TextQuery &) const override;

  std::string rep() const override { return "~(" + q.rep() + ")"; }

  Query q;
};

Query operator~(const Query &);

#endif
