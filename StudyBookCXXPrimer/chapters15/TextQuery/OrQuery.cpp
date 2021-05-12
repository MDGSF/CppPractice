#include "OrQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"

QueryResult OrQuery::eval(const TextQuery &t) const {
  auto left = lhs.eval(t);
  auto right = rhs.eval(t);
  auto ret_lines =
      std::make_shared<std::set<line_no_type>>(left.cbegin(), left.cend());
  ret_lines->insert(right.cbegin(), right.cend());
  return QueryResult(rep(), ret_lines->size(), ret_lines, left.get_file());
}

Query operator|(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
