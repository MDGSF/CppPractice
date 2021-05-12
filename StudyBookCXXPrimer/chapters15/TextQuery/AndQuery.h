#ifndef ANDQUERY_H
#define ANDQUERY_H

#include <string>
#include "BinaryQuery.h"

class TextQuery;
class QueryResult;

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query &, const Query &);

  AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") {}

  QueryResult eval(const TextQuery &) const override;
};

Query operator&(const Query &, const Query &);

#endif
