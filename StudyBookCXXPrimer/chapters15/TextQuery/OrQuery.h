#ifndef ORQUERY_H
#define ORQUERY_H

#include <string>
#include "BinaryQuery.h"

class TextQuery;
class QueryResult;

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query &, const Query &);

  OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "|") {}

  QueryResult eval(const TextQuery &) const override;
};

Query operator|(const Query &, const Query &);

#endif
