#include "Query.h"
#include "QueryResult.h"
#include "Query_base.h"
#include "TextQuery.h"
#include "WordQuery.h"

Query::Query(const std::string &s) : pq(new WordQuery(s)) {}

QueryResult Query::eval(const TextQuery &t) const { return pq->eval(t); }

std::string Query::rep() const { return pq->rep(); }
