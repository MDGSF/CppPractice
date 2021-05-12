#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include <string>
#include "Query.h"
#include "Query_base.h"

class BinaryQuery : public Query_base {
 protected:
  BinaryQuery(const Query &l, const Query &r, const std::string &o)
      : lhs(l), rhs(r), op(o) {}

  std::string rep() const override {
    return "(" + lhs.rep() + " " + op + " " + rhs.rep() + ")";
  }

  Query lhs;
  Query rhs;
  std::string op;
};

#endif
