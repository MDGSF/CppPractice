#include "AndQuery.h"

#include <algorithm>
#include <iterator>
#include <memory>

#include "QueryResult.h"
#include "TextQuery.h"

QueryResult AndQuery::eval(const TextQuery &t) const {
  auto left = lhs.eval(t);
  auto right = rhs.eval(t);
  auto ret_lines = std::make_shared<std::set<line_no_type>>();
  std::set_intersection(left.cbegin(), left.cend(), right.cbegin(),
                        right.cend(),
                        std::inserter(*ret_lines, ret_lines->begin()));
  return QueryResult(rep(), ret_lines->size(), ret_lines, left.get_file());
}

Query operator&(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
