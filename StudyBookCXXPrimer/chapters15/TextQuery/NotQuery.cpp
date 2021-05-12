#include "NotQuery.h"
#include <memory>
#include "TextQuery.h"
#include "QueryResult.h"

QueryResult NotQuery::eval(const TextQuery &t) const {
  auto result = q.eval(t);
  auto bg = result.cbegin();
  auto ed = result.cend();
  auto sz = result.get_file()->size();
  auto ret_lines = std::make_shared<std::set<line_no_type>>();
  for (std::size_t n = 0; n != sz; ++n) {
    if (bg == ed || *bg != n) {
      ret_lines->insert(n);
    } else if (bg != ed) {
      ++bg;
    }
  }
  return QueryResult(rep(), ret_lines->size(), ret_lines, result.get_file());
}

Query operator~(const Query &query) {
  return std::shared_ptr<Query_base>(new NotQuery(query));
}
