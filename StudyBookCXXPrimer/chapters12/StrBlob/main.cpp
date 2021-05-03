#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream> // ifstream
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>  // unique_ptr, shared_ptr, weak_ptr
#include <set>
#include <sstream> // istringstream
#include <string>
#include <utility>
#include <vector>

using namespace std;

class StrBlob {
 public:
   typedef std::vector<std::string>::size_type size_type;
   StrBlob();
   StrBlob(std::initializer_list<std::string> il);
   size_type size() const { return data->size(); }
   bool empty() const { return data->empty(); }

   void push_back(const std::string &t) { data->push_back(t); }
   void pop_back();

   std::string& front();
   std::string& back();

 private:
   std::shared_ptr<std::vector<std::string>> data;
   void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il):
  data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
  if (i >= data->size()) {
    throw out_of_range(msg);
  }
}

std::string& StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

int main() {
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
  }
  cout << b1.size() << endl;
  return 0;
}
